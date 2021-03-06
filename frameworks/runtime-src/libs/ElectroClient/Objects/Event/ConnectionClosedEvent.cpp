/*
 * ConnectionClosedEvent.cpp
 *
 *  Created on: Jan 20, 2016
 *      Author: QuyetNguyen
 */

#include "ConnectionClosedEvent.h"

#include "../thrift/ThriftConnectionClosedEvent_types.h"
#include "../thrift/libs/TBinaryProtocol.h"
#include "../thrift/libs/TBufferTransports.h"


namespace es {

ConnectionClosedEvent::ConnectionClosedEvent() {
	// TODO Auto-generated constructor stub
	messageType = es::type::ConnectionClosedEvent;
}

ConnectionClosedEvent::~ConnectionClosedEvent() {
	// TODO Auto-generated destructor stub
}

bool ConnectionClosedEvent::initWithBytes(const char* bytes, int len){
	apache::thrift::transport::TMemoryBuffer transport((uint8_t*)bytes, len, apache::thrift::transport::TMemoryBuffer::MemoryPolicy::OBSERVE);
	apache::thrift::protocol::TBinaryProtocol protocol(&transport);

	ThriftConnectionClosedEvent thriftObj;
	thriftObj.read(&protocol);

	this->connectionId = thriftObj.connectionId;

	//to json
	rapidjson::Document doc;
	doc.SetObject();
	doc.AddMember("messageType", messageType, doc.GetAllocator());
	doc.AddMember("connectionId", connectionId, doc.GetAllocator());

	rapidjson::StringBuffer buffer;
	buffer.Clear();
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	doc.Accept(writer);
	jsonData =  buffer.GetString();

	return true;
}

void ConnectionClosedEvent::printDebug(){

}

} /* namespace es */
