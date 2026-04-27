#pragma once
#include <string_view>
#include <iostream>
#include <type_traits>

class Logger
{
public:
    enum class ErrType
    {
        INFO,
        WARNING,
        ERROR
    };

    template <typename T, typename = void>
    struct is_streamable : std::false_type{};

    template <typename T>
    struct is_streamable<T, std::void_t<decltype(std::cout << std::declval<T>())>> : std::true_type{};

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& get();

    template <typename T, typename ...Args, typename = std::enable_if_t<is_streamable<T>::value>>
    void log(std::string_view className, ErrType errorType, T message, Args... moreMessges);

private:
    Logger() {}

    template <typename T, typename ...Args, typename = std::enable_if_t<is_streamable<T>::value>>
    void logMes(T message, Args... moreMessages);

    void logMes();

    const char* convertErrType(ErrType errType);
    const char* getColorFromErrType(ErrType errType);
};

template <typename T, typename ...Args, typename>
void Logger::log(std::string_view className, ErrType errorType, T message, Args... moreMessages)
{
    const char* errMessage = convertErrType(errorType);
    const char* colorMessage = getColorFromErrType(errorType);

    std::cout << colorMessage << "[" << errMessage << "][" << className << "] " << message;

    logMes(moreMessages...);
}

template <typename T, typename ...Args, typename>
void Logger::logMes(T message, Args... moreMessages)
{
    std::cout << message;

    logMes(moreMessages...);
}
