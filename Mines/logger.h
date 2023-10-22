#pragma once
#ifndef LOGGER_H
#define LOGGER_H
#include<string>
namespace logger {
	void log(std::string s, char type);
	void Log(std::string s);
	void init();
	void close();
	const char OTHER = '%';
	const char WARN = '?';
	const char REPLAY = '$';
}
#endif // !LOGGER_H
