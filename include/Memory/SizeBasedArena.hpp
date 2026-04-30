#pragma once

#include "Utils/Logger.hpp"
#include <cstddef>
#include <cstdlib>
#include <new>

template <class T, std::size_t N>
class SizeBasedArena
{
public:
    SizeBasedArena();
    ~SizeBasedArena();

    void* allocateOne();
    void* allocateArray(std::size_t);
    void deallocateOne(void*) noexcept {}
    void deallocateArray(void*) noexcept {}

private:
    char* m_basePtr;
    char* m_curPtrPos;
    
    SizeBasedArena(const SizeBasedArena&) = delete;
    SizeBasedArena& operator=(const SizeBasedArena&) = delete;

    static constexpr const char* m_className = "ArenaBasedAlloc";
};

template <typename T, std::size_t N>
SizeBasedArena<T, N>::SizeBasedArena()
    : m_basePtr(static_cast<char*>(std::malloc(N * sizeof(T))))
{
    if (!m_basePtr) throw std::bad_alloc();
    m_curPtrPos = m_basePtr;

    Logger::get().log(m_className, Logger::ErrType::INFO, "Memory is allocated");
}

template <class T, std::size_t N>
SizeBasedArena<T, N>::~SizeBasedArena()
{
    std::free(m_basePtr);
    Logger::get().log(m_className, Logger::ErrType::INFO, "Memory is deallocated");
}

template <typename T, std::size_t N>
void* SizeBasedArena<T, N>::allocateOne()
{
    char* memToReturn = m_curPtrPos;
    m_curPtrPos += sizeof(T);
    Logger::get().log(m_className, Logger::ErrType::INFO, "Memory is given for one object");

    return memToReturn;
}

template <typename T, std::size_t N>
void* SizeBasedArena<T, N>::allocateArray(std::size_t n)
{
    char* memToReturn = m_curPtrPos;
    m_curPtrPos += n * sizeof(T);
    Logger::get().log(m_className, Logger::ErrType::INFO, "Memory is given for array of objects");

    return memToReturn;
}
