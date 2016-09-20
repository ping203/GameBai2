/*
 * GameLaucher.cpp
 *
 *  Created on: Jun 27, 2016
 *      Author: Quyet Nguyen
 */

#include "GameLaucher.h"
#include "json/rapidjson.h"
#include "json/document.h"
#include "cocos2d.h"
USING_NS_CC;

namespace quyetnd {

GameLaucher::GameLaucher() {
	// TODO Auto-generated constructor stub
	versionFile = "";
	versionHash = "";
	jsMainFile = "js/main.js";
	statusCallback = nullptr;
	downloadCallback = nullptr;
	resourceHost = "http://10.0.1.106/quyetnd/Game/";
}

GameLaucher::~GameLaucher() {
	// TODO Auto-generated destructor stub
	for (auto it = _allResources.begin(); it != _allResources.end(); it++){
		delete it->second;
	}
	_allResources.clear();
}

bool GameLaucher::checkFileExist(const std::string& file){
	bool pret = false;
	FILE* f = fopen(file.c_str(), "rb");
	if (f){
		pret = true;
		fclose(f);
	}
	return pret;
}

void GameLaucher::checkFiles(){
	std::vector<GameFile*> _resourceUpdate;

	Data d = FileUtils::getInstance()->getDataFromFile(versionFile);
	char* data = (char*)d.getBytes();
	ssize_t fileSize = d.getSize();

	std::vector<char> buffer(data, data + fileSize);
	buffer.push_back('\0');

	rapidjson::Document doc;
	doc.Parse<0>(buffer.data());
	std::string versionName = doc["versionName"].GetString();
	uint32_t versionCode = doc["versionCode"].GetInt();
	if (doc.HasMember("main")){
		jsMainFile = doc["main"].GetString();
	}
	const rapidjson::Value& files = doc["files"];
	for (int i = 0; i < files.Size(); i++){
		const rapidjson::Value& fileData = files[i];

		GameFile* resource = new GameFile();
		resource->fileName = fileData["file"].GetString();
		resource->md5Digest = fileData["hash"].GetString();
		std::transform(resource->md5Digest.begin(), resource->md5Digest.end(), resource->md5Digest.begin(), ::tolower);
		resource->fileSize = fileData["size"].GetUint();

		_allResources.insert(std::make_pair(resource->fileName, resource));
	}

	this->onProcessStatus(GameLaucherStatus_TestHash);
	downloadMaxValue = 0;
	for (auto it = _allResources.begin(); it != _allResources.end(); it++){
		if (it->second->test()){
			CCLOG("HASH true: %s", it->second->filePath.c_str());
		}
		else{
			CCLOG("HASH false: %s", it->second->fileName.c_str());
			downloadMaxValue += it->second->fileSize;
			_resourceUpdate.push_back(it->second);
		}	
	}

	if (_resourceUpdate.size() > 0){
		downloadCurrentValue = 0;
		this->onProcessStatus(GameLaucherStatus_Updating);
		for (int i = 0; i < _resourceUpdate.size();){
			auto pret = _resourceUpdate[i]->update(resourceHost + _resourceUpdate[i]->fileName);
			if (pret == 0){
				i++;
			}
			else{
				this->onProcessStatus(GameLaucherStatus_UpdateFailure);
				return;
			}
		}
	}
	this->onProcessStatus(GameLaucherStatus_Finished);
}

bool GameLaucher::startFromFile(const std::string& versionFile){
	this->versionFile = versionFile;
	this->status = GameLaucherStatus_TestVersion;
	std::thread checkThread(&GameLaucher::checkFiles, this);
	checkThread.detach();
	return true;
}

void GameLaucher::onUpdateDownloadProcess(int size){
	UIThread::getInstance()->runOnUI([=](){
		downloadCurrentValue += size;
		if (this->downloadCallback){
			this->downloadCallback(downloadCurrentValue, downloadMaxValue);
		}
	});
}

void GameLaucher::setResourceHost(const std::string& updateHost){
	resourceHost = updateHost;
}

void GameLaucher::setVersionHash(const std::string& hash){
	versionHash = hash;
}

void GameLaucher::run(){
	//clear all
	for (auto it = _allResources.begin(); it != _allResources.end(); it++){
		delete it->second;
	}
	_allResources.clear();

	std::thread checkVersion(&GameLaucher::checkVersionFile, this);
	checkVersion.detach();
}

void GameLaucher::checkVersionFile(){
	GameFile* versionFile = new GameFile();
	versionFile->fileName = "version.json";
	versionFile->md5Digest = versionHash;
	std::transform(versionFile->md5Digest.begin(), versionFile->md5Digest.end(), versionFile->md5Digest.begin(), ::tolower);
	versionFile->fileSize = 0;

	if (!versionFile->test()){
		int returnCode = versionFile->updateNoHandler(resourceHost + versionFile->fileName);
		if (returnCode != 0){
			delete versionFile;
			UIThread::getInstance()->runOnUI([=](){			
				this->onProcessStatus(GameLaucherStatus_UpdateFailure);
			});
			return;
		}
	}

	std::string filePath = versionFile->filePath;
	delete versionFile;
	UIThread::getInstance()->runOnUI([=](){
		this->startFromFile(filePath);
	});
}

void GameLaucher::onProcessStatus(GameLaucherStatus status){
	UIThread::getInstance()->runOnUI([=](){
		if (this->statusCallback){
			this->statusCallback(status);
		}
	});
}

GameFile* GameLaucher::getFile(const std::string& file){
	auto it = _allResources.find(file);
	if (it != _allResources.end()){
		return it->second;
	}
	return 0;
}

GameFile* GameLaucher::getMainJs(){
	return this->getFile(jsMainFile);
}

static GameLaucher* s_GameLaucher = 0;

GameLaucher* GameLaucher::getInstance(){
	if (!s_GameLaucher){
		s_GameLaucher = new GameLaucher();
	}
	return s_GameLaucher;
}

/****/
UIThread::UIThread(){

}
UIThread::~UIThread(){

}

UIThreadRunnable UIThread::popEvent(){
	std::unique_lock<std::mutex> lk(_mutex);
	if (!mQueue.empty()){
		auto ev = mQueue.front();
		mQueue.pop();
		return ev;
	}
	return nullptr;
}

void UIThread::runOnUI(const std::function<void()>& callback){
	std::unique_lock<std::mutex> lk(_mutex);
	mQueue.push(callback);
}

void UIThread::update(float dt){
	auto ev = this->popEvent();
	while (ev){
		ev();
		ev = this->popEvent();
	}
}

static UIThread* s_UIThread = 0;
UIThread* UIThread::getInstance(){
	if (!s_UIThread){
		s_UIThread = new UIThread();
	}
	return s_UIThread;
}


} /* namespace quyetnd */
