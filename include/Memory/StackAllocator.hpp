#pragma once

#include <cstdlib>
#include <cstdint>
#include "Utils/Logger.hpp"

class StackAllocator
{
public:
    static StackAllocator& get();

    template <typename T>
    void* allocate();

    void deallocate();

    std::size_t size();
private:
    StackAllocator();
    ~StackAllocator();

    StackAllocator(const StackAllocator&) = delete;
    StackAllocator &operator=(const StackAllocator&) = delete;

    char* alignUp(char* addr, std::uint16_t alignment);

    struct Header {
        char* prevHeaderTopPtr;
    };

    char* m_initPtr = nullptr;
    char* m_offsetPtr = nullptr;

    static constexpr const char* m_className = "StackAllocator";

    static std::size_t s_stackSize;
};

template <typename T>
void* StackAllocator::allocate() 
{
    char* prevHeaderTopPtr = m_offsetPtr;

    m_offsetPtr = alignUp(m_offsetPtr, alignof(T));

    void* memToReturn = m_offsetPtr;
    m_offsetPtr += sizeof(T);

    m_offsetPtr = alignUp(m_offsetPtr, alignof(Header));
    Header* header = reinterpret_cast<Header*>(m_offsetPtr);
    header->prevHeaderTopPtr = prevHeaderTopPtr;

    m_offsetPtr += sizeof(Header);

    Logger::get().log(m_className, Logger::ErrType::INFO, reinterpret_cast<uintptr_t>(m_offsetPtr) - reinterpret_cast<uintptr_t>(prevHeaderTopPtr), " Memory is given for some object");
    Logger::get().log(m_className, Logger::ErrType::INFO, "Current m_offsetPtr address ", (void*)m_offsetPtr);
    return memToReturn;
}
