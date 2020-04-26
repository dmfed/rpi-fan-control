#include <iostream>
#include <string>
#include "log.h"

using namespace std;

Logger::Logger() :
    mLevel(LogLevel::Error)
{
}

Logger& Logger::getInstance()
{
    static Logger instance;
    return instance;
}

void Logger::setLevel(LogLevel level)
{
    mLevel = level;
}

void Logger::Log(const string& log, LogLevel level)
{
    if (level <= mLevel)
        std::cout << log << std::endl;
}

void Logger::Debug(const string& log)
{
    std::cout << "[DEBUG] ";
    Log(log, LogLevel::Debug);
}

void Logger::Warning(const string& log)
{
    std::cout << "[WARNING] ";
    Log(log, LogLevel::Warning);
}

void Logger::Error(const string& log)
{
    std::cout << "[ERROR] ";
    Log(log, LogLevel::Error);
}
