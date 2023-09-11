#ifndef UNTITLED_LOGGER_H
#define UNTITLED_LOGGER_H
#include <string>
#include <iostream>

enum LogLevel {
    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    ERROR = 3
};

class Logger {
public:
    static void setLogLevel(int level);
    static void debug(std::string message, std::string tag);
    static void info(std::string message, std::string tag);
    static void warning(std::string message, std::string tag);
    static void error(std::string message, std::string tag);
private:
    static int logLevel;
};

#endif //UNTITLED_LOGGER_H
