/*
 * EsEntity.h
 *
 *  Created on: Jan 21, 2016
 *      Author: QuyetNguyen
 */

#ifndef ELECTROCLIENT_OBJECTS_ESENTITY_H_
#define ELECTROCLIENT_OBJECTS_ESENTITY_H_

#define RAPIDJSON_HAS_STDSTRING 1

#include "EsMessageStreamer.h"
#include <sstream>
#include "../rapidjson/rapidjson.h"
#include "../rapidjson/document.h"
#include "../rapidjson/stringbuffer.h"
#include "../rapidjson/prettywriter.h"

namespace es {

class EsArray;
class EsObject;
class EsPrimitive;
class EsString;
class EsEntity {
protected:
#ifdef ES_LOGGER
	virtual void printPadding(std::ostream &outStream, int padding);
#endif
public:
	int type;
public:
	EsEntity();
	virtual ~EsEntity();

	virtual void writeToBuffer(EsMessageWriter* writer);
	virtual void readFromBuffer(EsMessageReader* reader);

	virtual void initFromFlattenedEsObject(void* esObject);
	virtual void initFromFlattenedEsObjectRO(void* esObject);	

	virtual void writeToFlattenedEsObject(void* esObject);
	virtual void writeToFlattenedEsObjectRO(void* esObject);

#ifdef ES_LOGGER
	virtual void printDebug();
	virtual void printDebugToBuffer(std::ostringstream &outStream, int padding);
#endif

	virtual void toJson(rapidjson::Value& value, rapidjson::Document::AllocatorType &allocator);

	static EsEntity* createFromJson(const rapidjson::Value& value);
};

} /* namespace es */

#endif /* ELECTROCLIENT_OBJECTS_ESENTITY_H_ */
