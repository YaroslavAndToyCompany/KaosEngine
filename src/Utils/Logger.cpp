#include "Utils/Logger.hpp"

Logger& Logger::get()
{
    static Logger instance;

    return instance;
}

void Logger::logMes()
{
    std::cout << getColorFromErrType(ErrType::INFO) << "\n";
}

const char* Logger::convertErrType(ErrType errType)
{
    switch (errType) 
    {
        case ErrType::INFO:    return "INFO";
        case ErrType::WARNING: return "WARNING";
        case ErrType::ERROR:   return "ERROR";
        default: return "Unknown";
    }
}

const char* Logger::getColorFromErrType(ErrType errType) 
{
    switch (errType) 
    {
        case ErrType::WARNING: return "\033[33m"; // Red
        case ErrType::ERROR:   return "\033[31m"; // Yellow
        case ErrType::INFO:                         
        default: return "\033[0m";                // Reset
    }
}
