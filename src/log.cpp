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

void Logger::setLevel(const LogLevel level)
{
    mLevel = level;
}

void Logger::Log(const string& log, LogLevel level) const
{
    if (level <= mLevel)
        std::cout << "[" << getLogLevelName(level) << "] " << log << std::endl;
}

void Logger::Debug(const string& log) const
{
    Log(log, LogLevel::Debug);
}

void Logger::Warning(const string& log) const
{
    Log(log, LogLevel::Warning);
}

void Logger::Error(const string& log) const
{
    Log(log, LogLevel::Error);
}

const char* Logger::getLogLevelName(const LogLevel level) const
{
    switch (level)
    {
        case LogLevel::Error:
            return "Error";
        case LogLevel::Warning:
            return "Warning";
        case LogLevel::Debug:
            return "Debug";
        default:
            return "";
    }
}
