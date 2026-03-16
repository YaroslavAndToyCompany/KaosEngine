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

    static Logger& get();

    void log(std::string_view className, std::string_view message, ErrType errorType = ErrType::INFO);

private:
    Logger() {}
    
    const char* convertErrType(ErrType errType);
    const char* getColorFromErrType(ErrType errType);
};