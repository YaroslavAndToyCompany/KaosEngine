#pragma once
#include <string_view>

class Logger
{
public:
    enum class ErrType
    {
        INFO,
        WARNING,
        ERROR
    };

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger* getInstance();

    void log(std::string_view className, std::string_view message, ErrType errorType);

private:
    Logger() {}

    static Logger* m_logger;
};