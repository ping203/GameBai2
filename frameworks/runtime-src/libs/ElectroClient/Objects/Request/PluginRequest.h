/*
 * PluginRequest.h
 *
 *  Created on: Jan 25, 2016
 *      Author: QuyetNguyen
 */

#ifndef ELECTROCLIENT_OBJECTS_PLUGINREQUEST_H_
#define ELECTROCLIENT_OBJECTS_PLUGINREQUEST_H_

#include "BaseRequest.h"

namespace es {

class PluginRequest : public BaseRequest {
public:
	std::string pluginName;
	int zoneId;
	int roomId;
	int sessionKey;
	EsObject* parameters;
public:
	PluginRequest();
	virtual ~PluginRequest();

	virtual bool initWithBytes(const char* bytes, int len);
	virtual void initWithJson(const rapidjson::Value& jsonData);
	virtual void getBytes(std::vector<char> &buffer);
	virtual void printDebug();
};

} /* namespace es */

#endif /* ELECTROCLIENT_OBJECTS_PLUGINREQUEST_H_ */
