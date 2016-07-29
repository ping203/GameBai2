/*
 * SFSEntity.cpp
 *
 *  Created on: May 31, 2016
 *      Author: Quyet Nguyen
 */

#include "SFSEntity.h"
#include "SFSObject.h"
#include "SFSPrimitive.h"
#include "SFSArray.h"
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include <stdint.h>

namespace SFS{
namespace Entity{

SFSEntity::SFSEntity() {
	// TODO Auto-generated constructor stub
	dataType = SFSDataType::SFSDATATYPE_NULL;
}

SFSEntity::~SFSEntity() {
	// TODO Auto-generated destructor stub
}

void SFSEntity::writeToJSON(std::ostringstream& stream){
	stream << "null";
}

void SFSEntity::writeToBuffer(StreamWriter* writer){
	writer->WriteByte(dataType);
}

void SFSEntity::initWithReader(StreamReader* reader){

}

void SFSEntity::printDebug(std::ostringstream& os, int padding){

}

std::string SFSEntity::toJSON(){
	std::ostringstream stringStream;
	//stringStream << std::setprecision(17);
	this->writeToJSON(stringStream);
	return stringStream.str();
}

SFSEntity* SFSEntity::createSFSEntityWithReader(StreamReader* reader){
	int dataType = reader->NextByte(); 
	SFSEntity* entity = 0;

	switch (dataType){
		case Entity::SFSDataType::SFSDATATYPE_NULL:{
			entity = new SFSPrimitive();
			break;
		}
		case Entity::SFSDataType::SFSDATATYPE_BOOL:
		case Entity::SFSDataType::SFSDATATYPE_BYTE:
		case Entity::SFSDataType::SFSDATATYPE_SHORT:
		case Entity::SFSDataType::SFSDATATYPE_INT:
		case Entity::SFSDataType::SFSDATATYPE_LONG:
		case Entity::SFSDataType::SFSDATATYPE_FLOAT:
		case Entity::SFSDataType::SFSDATATYPE_DOUBLE:{
			entity = new SFSPrimitive();
			break;
		}
		case Entity::SFSDataType::SFSDATATYPE_STRING:{
			entity = new SFSString();
			break;
		}
		case Entity::SFSDataType::SFSDATATYPE_BOOL_ARRAY:
		case Entity::SFSDataType::SFSDATATYPE_BYTE_ARRAY:
		case Entity::SFSDataType::SFSDATATYPE_SHORT_ARRAY:
		case Entity::SFSDataType::SFSDATATYPE_INT_ARRAY:
		case Entity::SFSDataType::SFSDATATYPE_LONG_ARRAY:
		case Entity::SFSDataType::SFSDATATYPE_FLOAT_ARRAY:
		case Entity::SFSDataType::SFSDATATYPE_DOUBLE_ARRAY:
		case Entity::SFSDataType::SFSDATATYPE_STRING_ARRAY:
		case Entity::SFSDataType::SFSDATATYPE_SFS_ARRAY:{
			entity = new SFSArray();
			break;
		}
		case Entity::SFSDataType::SFSDATATYPE_SFS_OBJECT:{
			entity = new SFSObject();
			break;
		}
		case Entity::SFSDataType::SFSDATATYPE_CLASS:{
			int a = 2;
		}
		default:{
			entity = new SFSEntity();
		}
	}

	entity->dataType = dataType;
	entity->initWithReader(reader);
	return entity;
}

SFSEntity* SFSEntity::createEntityWithData(const char* buffer, int size){
	StreamReader reader(buffer, size, false);
	return createSFSEntityWithReader(&reader);
}


/****/
SFSEntity* __SFS_createObjectFromJSON(rapidjson::Value& value);
SFSEntity* __SFS_createArrayFromJSON(rapidjson::Value& value);
SFSEntity* __SFS_createNumberFromJSON(rapidjson::Value& value);

SFSEntity* __SFS_createEntityFromJSON(rapidjson::Value& value){
	int type = value.GetType();
	switch (type)
	{
	case rapidjson::Type::kNullType:{
		return new SFSEntity();
	}
	case rapidjson::Type::kFalseType:{
		auto pret = new SFSPrimitive();
		pret->setBool(false);
		return pret;
	}
	case rapidjson::Type::kTrueType:{
		auto pret = new SFSPrimitive();
		pret->setBool(true);
		return pret;
	}
	case rapidjson::Type::kNumberType:{
		return __SFS_createNumberFromJSON(value);
	}
	case rapidjson::Type::kStringType:{
		auto pret = new SFSString();
		pret->setString(value.GetString());
		return pret;
	}
	case rapidjson::Type::kObjectType:{
		return __SFS_createObjectFromJSON(value);
	}
	case rapidjson::Type::kArrayType:{
		return __SFS_createArrayFromJSON(value);
	}
	}

	return new SFSEntity();
}

SFSEntity* __SFS_createNumberFromJSON(rapidjson::Value& value){
	auto pret = new SFSPrimitive();
	if (value.IsInt()){
		pret->setInt(value.GetInt());
	}
	else if (value.IsInt64()){
		pret->setLong(value.GetInt64());
	}
	else if (value.IsUint()){
		pret->setInt(value.GetUint());
	}
	else if (value.IsUint64()){
		pret->setLong(value.GetUint64());
	}
	else if (value.IsDouble()){
		pret->setFloat(value.GetDouble());
	}
	return pret;
}

SFSEntity* __SFS_createObjectFromJSON(rapidjson::Value& value){
	auto pret = new SFSObject();
	for (auto it = value.MemberBegin(); it != value.MemberEnd(); it++){
		SFSEntity* value = __SFS_createEntityFromJSON(it->value);
		pret->setItem(it->name.GetString(), value);
		value->release();
	}
	return pret;
}

SFSEntity* __SFS_createArrayFromJSON(rapidjson::Value& value){
	int _is_bool =		1 << 0;
	int _is_int =		1 << 1;
	int _is_float =		1 << 2;
	int _is_string =	1 << 3;
	int _flag = _is_bool | _is_int | _is_float | _is_string;
	
	for (int i = 0; i < value.Size(); i++){
		if (!_flag){
			break;
		}
		if (value[i].IsBool()){ //bool array
			_flag = _flag & _is_bool;
		}
		else if (value[i].IsDouble()){ //float array
			_flag = _flag & _is_float;
		}
		else if (value[i].IsNumber()){ //int array
			_flag = _flag & _is_int;
		}
		else if (value[i].IsString()){ //string array
			_flag = _flag & _is_string;
		}
	}

	SFSArray* arr = new SFSArray();
	for (int i = 0; i < value.Size(); i++){
		SFSEntity* item = __SFS_createEntityFromJSON(value[i]);
		arr->addItem(item);
		item->release();
	}
	
	if (!_flag){
		arr->dataType = SFS::Entity::SFSDataType::SFSDATATYPE_SFS_ARRAY;
	}
	else if (_flag & _is_bool){
		arr->dataType = SFS::Entity::SFSDataType::SFSDATATYPE_BOOL_ARRAY;
	}
	else if (_flag & _is_int){
		arr->dataType = SFS::Entity::SFSDataType::SFSDATATYPE_INT_ARRAY;
	}
	else if (_flag & _is_float){
		arr->dataType = SFS::Entity::SFSDataType::SFSDATATYPE_FLOAT_ARRAY;
	}
	else if (_flag & _is_string){
		arr->dataType = SFS::Entity::SFSDataType::SFSDATATYPE_STRING_ARRAY;
	}

	return arr;
}


SFSEntity* SFSEntity::createFromJSON(const std::string& json){
	return createFromJSON(json.data(), json.size());
}

SFSEntity* SFSEntity::createFromJSON(const char* json, int size){
	rapidjson::Document doc;
	bool b = doc.Parse<0>(json).HasParseError();
	if (!b){
		if (doc.IsObject()){		
			SFSEntity*  value = __SFS_createEntityFromJSON(doc);
			value->autoRelease();
			return value;
		}	
	}
	return 0;
}

}
}
