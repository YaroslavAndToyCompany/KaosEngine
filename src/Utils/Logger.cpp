#include "Utils/Logger.hpp"
#include <iostream>

Logger* Logger::m_logger = nullptr;

Logger* Logger::getInstance()
{
    if (m_logger == nullptr)
        m_logger = new Logger();
    return m_logger;
}

void Logger::log(std::string_view className, std::string_view message, ErrType errorType)
{
    std::string errTypeStr;

    switch (errorType) {
    case ErrType::INFO:
        errTypeStr = "INFO";
    case ErrType::WARNING:
        errTypeStr = "WARNING";
    case ErrType::ERROR:
        errTypeStr = "ERROR";
    }

    std::cout << "[" << errTypeStr << "][" << className << "] " << message <<  std::endl;
}