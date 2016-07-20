/*
 * Logger.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: Quyet Nguyen
 */

#include "Logger.h"
#include <algorithm>
#include <cstdarg>
#include <string>

#if defined(_WIN32) || defined(WINRT)
#include "Windows.h"
#elif defined(ANDROID)
#include <android/log.h>
#endif

#define MAX_LOG_LENGTH 16 * 1024 //16KB log

namespace quyetnd{

static void _log(const char *format, va_list args){
#ifdef LOBBY_LOGGER
	char* buf = new char[MAX_LOG_LENGTH];

	vsnprintf(buf, MAX_LOG_LENGTH - 3, format, args);
	strcat(buf, "\n");

	log_to_console(buf);

	delete[] buf;
#endif
}

void log_to_console(const char* buf){
#ifdef LOBBY_LOGGER

#if defined(ANDROID)
	__android_log_print(ANDROID_LOG_DEBUG, "lobby-debug", "%s", buf);
#elif defined(_WIN32) || defined(WINRT)
	int pos = 0;
	int len = strlen(buf);
	int bufferSize = len > MAX_LOG_LENGTH ? MAX_LOG_LENGTH : len;
	char* tempBuf = new char[bufferSize + 1];
	WCHAR* wszBuf = new WCHAR[bufferSize + 1];

	while (pos < len)
	{
		std::copy(buf + pos, buf + pos + bufferSize, tempBuf);

		tempBuf[bufferSize] = 0;

		MultiByteToWideChar(CP_UTF8, 0, tempBuf, -1, wszBuf, (bufferSize + 1));
		OutputDebugStringW(wszBuf);
		WideCharToMultiByte(CP_ACP, 0, wszBuf, -1, tempBuf, (bufferSize + 1), nullptr, FALSE);
		printf("%s", tempBuf);

		pos += bufferSize;
		bufferSize = len - pos;
		if (bufferSize > MAX_LOG_LENGTH){
			bufferSize = MAX_LOG_LENGTH;
		}
	}

	fflush(stdout);

	delete[] tempBuf;
	delete[] wszBuf;
#else
	fprintf(stdout, "%s", buf);
	fflush(stdout);
#endif

#endif
}

void log(const char * format, ...){
#ifdef LOBBY_LOGGER
	va_list args;
	va_start(args, format);
	_log(format, args);
	va_end(args);
#endif
}

void log_hex(const char* buf, int len){
#ifdef LOBBY_LOGGER
	char* data = new char[len * 3 + 10];

	for (int i = 0; i<len; i++){
		sprintf(&data[i * 3], "%02X ", (unsigned char)buf[i]);
	}

	log("%s", data);

	delete[]data;
#endif
}

}

