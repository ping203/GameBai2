/*
 * ResourceLoader.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: QuyetNguyen
 */

#include "ResourceLoader.h"
#include "2d/CCFontAtlasCache.h"
//#include "audio/include/SimpleAudioEngine.h"
#include "audio/include/AudioEngine.h"
#include "GameLaucher.h"
#include "EngineUtilsThreadSafe.h"
#include "WorkerManager.h"
//using namespace CocosDenshion;

namespace quyetnd {

ResourceLoader::ResourceLoader() {
	// TODO Auto-generated constructor stub
	running = false;
	processHandler = nullptr;
}

ResourceLoader::~ResourceLoader() {
	// TODO Auto-generated destructor stub
	Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
	CCLOG("ResourceLoader::~ResourceLoader");
}

void ResourceLoader::addTextureLoad(const std::string &img, const std::string &plist){
	TextureData textureLoad;
	textureLoad.texture = img;
	textureLoad.plist = plist;
	_preLoad.push_back(textureLoad);
}

void ResourceLoader::addBMFontLoad(const std::string &texture, const std::string &font){
	BMFontData fontData;
	fontData.texture = texture;
	fontData.font = font;
	_preloadBMFont.push_back(fontData);
}

void ResourceLoader::addTextureUnLoad(const std::string &img, const std::string &plist){
	TextureData textureLoad;
	textureLoad.texture = img;
	textureLoad.plist = plist;
	_preUnload.push_back(textureLoad);
}

void ResourceLoader::addSoundPreload(const std::string& sound){
	_preloadSound.push_back(sound);
}

void ResourceLoader::addSoundUnload(const std::string& sound){
	_unloadSound.push_back(sound);
}

//void ResourceLoader::onLoadImageThread(std::string img, std::function<void(cocos2d::Texture2D*)> callback){
//	std::string fullpath = EngineUtilsThreadSafe::getInstance()->fullPathForFilename(img);
//	Texture2D* texture = EngineUtilsThreadSafe::getInstance()->getTextureForKey(fullpath);
//	if (texture){
//		GameLaucher::getInstance()->runOnUI([=](){
//			callback(texture);
//		});
//		return;
//	}
//	else{
//		Data data = EngineUtilsThreadSafe::getInstance()->getFileData(fullpath);
//		if (!data.isNull()){
//			Image* imageData = new Image();
//			imageData->initWithImageData(data.getBytes(), data.getSize());			
//			GameLaucher::getInstance()->runOnUI([=](){
//				Texture2D* texture = TextureCache::getInstance()->addImage(imageData, fullpath);
//				callback(texture);
//				imageData->release();
//				//delete imageData;
//			});
//			return;
//		}
//	}
//	GameLaucher::getInstance()->runOnUI([=](){
//		callback(0);
//	});
//}
//
//void ResourceLoader::onLoadSpriteFrameThread(std::string plist, cocos2d::Texture2D* texture, std::function<void(bool)> callback){
//	std::string fullpath = EngineUtilsThreadSafe::getInstance()->fullPathForFilename(plist);
//	Data data = EngineUtilsThreadSafe::getInstance()->getFileData(fullpath);
//	if (!data.isNull()){
//		std::string plistContent(data.getBytes(), data.getBytes() + data.getSize());		
//		GameLaucher::getInstance()->runOnUI([=](){
//			SpriteFrameCache::getInstance()->addSpriteFramesWithFileContent(plistContent, texture);
//			callback(true);
//		});
//		return;
//	}
//	GameLaucher::getInstance()->runOnUI([=](){
//		callback(false);
//	});
//}

void ResourceLoader::runOnUI(const std::function<void()>& runable){
	cocos2d::Director::getInstance()->getScheduler()->performFunctionInCocosThread(runable);
}

void ResourceLoader::loadTexture(std::string img, std::string plist, WorkerTicket* ticket){
	WorkerManager::getInstance()->pushAction([=](){
		std::string fullpath = EngineUtilsThreadSafe::getInstance()->fullPathForFilename(img);
		auto tex = EngineUtilsThreadSafe::getInstance()->getTextureForKey(fullpath);
		if (tex){
			if (plist.empty()){
				this->runOnUI([=](){
					ticket->done(true);
					this->currentStep++;
					this->onProcessLoader();
				});
			}
			else{
				this->loadSpriteFrame(tex, plist, ticket);
			}
		}
		else{
			Data data = EngineUtilsThreadSafe::getInstance()->getFileData(fullpath);
			if (!data.isNull()){
				Image* imageData = new Image();
				if (imageData->initWithImageData(data.getBytes(), data.getSize())){
					this->runOnUI([=](){
						Texture2D* texture = TextureCache::getInstance()->addImage(imageData, fullpath);
						imageData->release();
						if (texture){
							if (plist.empty()){
								ticket->done(true);
								this->currentStep++;
								this->onProcessLoader();
							}
							else{
								this->loadSpriteFrame(texture, plist, ticket);
							}
						}
						else{
							ticket->done(false);
						}					
					});
					return;
				}
			}
			CCLOG("loadTexture error: ", img.c_str());
			ticket->done(false);
		}
	});
}

void ResourceLoader::loadSpriteFrame(Texture2D* tex, std::string plist, WorkerTicket* ticket){
	WorkerManager::getInstance()->pushAction([=](){
		std::string fullpath = EngineUtilsThreadSafe::getInstance()->fullPathForFilename(plist);
		Data data = EngineUtilsThreadSafe::getInstance()->getFileData(fullpath);
		if (!data.isNull()){
			std::string plistContent(data.getBytes(), data.getBytes() + data.getSize());
			this->runOnUI([=](){
				SpriteFrameCache::getInstance()->addSpriteFramesWithFileContent(plistContent, tex);
				ticket->done(true);
				this->currentStep++;
				this->onProcessLoader();
			});
		}
		else{
			CCLOG("loadSpriteFrame error: ", plist.c_str());
			ticket->done(false);
		}
	});
}

void ResourceLoader::loadBitmapFont(std::string img, std::string fnt, WorkerTicket* ticket){
	WorkerManager::getInstance()->pushAction([=](){
		std::string fullpath = EngineUtilsThreadSafe::getInstance()->fullPathForFilename(img);
		auto tex = EngineUtilsThreadSafe::getInstance()->getTextureForKey(fullpath);
		if (tex){
			this->runOnUI([=](){
				FontAtlasCache::getFontAtlasFNT(fnt);
				ticket->done(true);
				currentStep++;
				onProcessLoader();
			});
		}
		else{
			Data data = EngineUtilsThreadSafe::getInstance()->getFileData(fullpath);
			if (!data.isNull()){
				Image* imageData = new Image();
				if (imageData->initWithImageData(data.getBytes(), data.getSize())){
					this->runOnUI([=](){
						Texture2D* texture = TextureCache::getInstance()->addImage(imageData, fullpath);
						imageData->release();
						if (texture){
							ticket->done(true);
							currentStep++;
							onProcessLoader();
						}
						else{
							ticket->done(false);						
						}
					});
				}
			}
			else{
				CCLOG("loadTexture error: ", img.c_str());
				ticket->done(false);
			}
		}
	});
}

void ResourceLoader::update(float dt){
	if (running){
		switch (step)
		{
			case kStepUnloadImage:
			{	
				if (index < _preUnload.size()){
					TextureCache* textureCache = Director::getInstance()->getTextureCache();
					Texture2D* texture = textureCache->getTextureForKey(_preUnload[index].texture);
					if (texture){
						SpriteFrameCache* spriteCache = SpriteFrameCache::getInstance();
						TextureCache* textureCache = Director::getInstance()->getTextureCache();

						spriteCache->removeSpriteFramesFromTexture(texture);
						textureCache->removeTexture(texture);
					}
					
					currentStep++;
					index++;
					onProcessLoader();				
				}
				else{
					index = 0;
					step = kStepUnloadSound;
				}

				break;
			}

			case kStepUnloadSound:
			{
				if (index < _unloadSound.size()){
					CCLOG("unload sound: %s", _unloadSound[index].c_str());
					cocos2d::experimental::AudioEngine::uncache(_unloadSound[index]);
					//SimpleAudioEngine* audioEngine = SimpleAudioEngine::getInstance();
					//audioEngine->unloadEffect(_unloadSound[index].c_str());

					index++;
					currentStep++;
					onProcessLoader();
				}
				else{
					index = 0;
					step = kStepLoadImage;
				}

				break;
			}

			case kStepLoadImage:
			{	
				step = kStepWaitingLoadImage;
				auto ticket = WorkerTicket::create(_preLoad.size());
				ticket->finishedCallback = [=](bool success){
					if (success){
						index = 0;
						step = kStepLoadBMFont;
					}
					else{
						CCLOG("LOAD TEXTURE ERROR");
					}
				};

				for (int i = 0; i < _preLoad.size(); i++){
					auto textureImg = _preLoad[i].texture;
					auto plistData = _preLoad[i].plist;
					CCLOG("loading texture: %s : %s", textureImg.c_str(), plistData.c_str());
					this->loadTexture(textureImg, plistData, ticket);
				}

				break;
			}

			case kStepLoadBMFont:
			{	
				step = kStepWaitingLoadImage;
				auto ticket = WorkerTicket::create(_preloadBMFont.size());
				ticket->finishedCallback = [=](bool success){
					if (success){
						index = 0;
						step = kStepLoadSound;
					}
					else{
						CCLOG("LOAD TEXTURE ERROR");
					}
				};

				for (int i = 0; i < _preloadBMFont.size(); i++){
					auto textureImg = _preloadBMFont[i].texture;
					auto fnt = _preloadBMFont[i].font;
					CCLOG("loading font: %s : %s", textureImg.c_str(), fnt.c_str());
					this->loadBitmapFont(textureImg, fnt, ticket);
				}

				break;
			}

			case kStepWaitingLoadImage:
			{
				break;
			}

			case kStepLoadSound:
			{
				if (index < _preloadSound.size()){
					auto n = _preloadSound.size() - index;
					if (n > 10){
						n = 10;
					}
					for (auto i = 0; i < n; i++){
						CCLOG("load sound: %s", _preloadSound[index + i].c_str());
						cocos2d::experimental::AudioEngine::preload(_preloadSound[index + i]);
					}
					
					index += n;
					currentStep += n;
					onProcessLoader();
				}
				else{
					index = 0;
					step = kStepPreFinishLoadResource;
				}	
				break;
			}

			case kStepPreFinishLoadResource:
			{
				currentStep++;
				onProcessLoader();
				step = kStepFinishLoadResource;
				break;
			}

			case kStepFinishLoadResource:
			{	
				/*clear all*/
				_preLoad.clear();
				_preUnload.clear();
				_preloadBMFont.clear();
				_preloadSound.clear();
				_unloadSound.clear();
				/**/
				running = false;
				break;
			}
		}

	}
}

void ResourceLoader::start(){
	running = true;
	index = 0;
	currentStep = 0;
	step = kStepUnloadImage;

	targetStep = 1;
	targetStep += _preUnload.size();
	targetStep += _preLoad.size();
	targetStep += _preloadBMFont.size();
	targetStep += _unloadSound.size();
	targetStep += _preloadSound.size();
}

void ResourceLoader::stop(){
	running = false;
}

void ResourceLoader::onProcessLoader(){
	if (processHandler){
		processHandler(currentStep, targetStep);
	}
}

int ResourceLoader::getMaxStep(){
	targetStep = 1;
	targetStep += _preUnload.size();
	targetStep += _preLoad.size();
	targetStep += _preloadBMFont.size();
	targetStep += _unloadSound.size();
	targetStep += _preloadSound.size();
	return targetStep;
}

int ResourceLoader::getCurrentStep(){
	return currentStep;
}

bool ResourceLoader::isFinished(){
	return (currentStep >= targetStep);
}

} /* namespace quyetnd */
