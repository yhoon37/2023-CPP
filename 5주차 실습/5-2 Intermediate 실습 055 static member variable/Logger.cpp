// implement your code

// static 멤버 변수를 "정의" 하고 초기값을 1로 설정합니다.

// 멤버 함수들 구현

#include "Logger.h"

int Logger::logLevel = 1;

void Logger::setLogLevel(int level) {Logger::logLevel = static_cast<LogLevel>(level);}

void Logger::debug(std::string message, std::string tag) {
    if(Logger::logLevel <= DEBUG)
        std::cout << "[DEBUG][" << tag << "] " << message << std::endl;
}

void Logger::info(std::string message, std::string tag) {
    if(Logger::logLevel <= INFO)
        std::cout << "[INFO][" << tag << "] " << message << std::endl;
}

void Logger::warning(std::string message, std::string tag) {
    if(Logger::logLevel <= WARNING)
        std::cout << "[WARNING][" << tag << "] " << message << std::endl;
}

void Logger::error(std::string message, std::string tag) {
    if(Logger::logLevel <= ERROR)
        std::cout << "[ERROR][" << tag << "] " << message << std::endl;
}