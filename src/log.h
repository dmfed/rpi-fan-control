#pragma once
#include <string>

using namespace std;

enum LogLevel
{
    Error = 0,
    Warning = 1,
    Debug = 2
};

class Logger
{
private:
    LogLevel mLevel;
    Logger();
    const char* getLogLevelName(const LogLevel level) const;

public:
    static Logger& getInstance();

    void setLevel(const LogLevel level);
    void Log(const string& log, const LogLevel level) const;
    void Debug(const string& log) const;
    void Warning(const string& log) const;
    void Error(const string& log) const;
}; 
