/*
 * PrivateMessageRequest.h
 *
 *  Created on: Feb 5, 2016
 *      Author: Quyet Nguyen
 */

#ifndef ELECTROCLIENT_OBJECTS_PRIVATEMESSAGEREQUEST_H_
#define ELECTROCLIENT_OBJECTS_PRIVATEMESSAGEREQUEST_H_

#include "BaseMessage.h"
#include "EsObject.h"

namespace es {

class PrivateMessageRequest : public BaseMessage{
public:
	std::string message;
	std::vector<std::string>  userNames;
	EsObject* esObject;
public:
	PrivateMessageRequest();
	virtual ~PrivateMessageRequest();

	virtual bool initWithBytes(const char* bytes, int len);
	virtual void getBytes(std::vector<char> &buffer);
	virtual void printDebug();
};

} /* namespace es */

#endif /* ELECTROCLIENT_OBJECTS_PRIVATEMESSAGEREQUEST_H_ */