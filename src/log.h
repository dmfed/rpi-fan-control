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

public:
    static Logger& getInstance();

    void setLevel(LogLevel level);
    void Log(const string& log, LogLevel level);
    void Debug(const string& log);
    void Warning(const string& log);
    void Error(const string& log);
}; 