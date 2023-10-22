#define _CRT_SECURE_NO_WARNINGS
#include "logger.h"

#include<fstream>
#include<iostream>
#include<ctime>

static std::ofstream log_file;
static char file_name[] = "MinesLog-yyyy-mm-dd-hh-mm-ss.log";
static void putAtFileName(int v, int p, int n)
{
	while (n--)
	{
		file_name[p] = v % 10 + '0';
		v = v / 10;
		p--;
	}
}
void logger::log(std::string s, char type)
{
	log_file << type + " " + s << std::endl;
}
void logger::Log(std::string s)
{
	std::cerr << s << std::endl;
	log(s, logger::WARN);
}
void logger::init()
{
	time_t timer = time(NULL);
	tm start_time;
	localtime_s(&start_time, &timer);
	int year = start_time.tm_year + 1900;
	putAtFileName(year, 12, 4);
	int month = start_time.tm_mon + 1;
	putAtFileName(month, 15, 2);
	putAtFileName(start_time.tm_mday, 18, 2);
	putAtFileName(start_time.tm_hour, 21, 2);
	putAtFileName(start_time.tm_min, 24, 2);
	putAtFileName(start_time.tm_sec, 27, 2);
	std::cout << file_name << std::endl;
	log_file.open(file_name, std::ios::out);
	if (!log_file.is_open())
		exit(-1);
	atexit(logger::close);
}

void logger::close()
{
	log_file.close();
}