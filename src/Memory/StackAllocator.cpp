#include "Memory/StackAllocator.hpp"

#include "Utils/Logger.hpp"
#include <stdexcept>

std::size_t StackAllocator::s_stackSize = 1024;

StackAllocator& StackAllocator::get() 
{
    static StackAllocator stack;
    return stack;
}

void StackAllocator::deallocate() 
{
    char* headerInitPtr = m_offsetPtr - sizeof(Header);
    if (headerInitPtr < m_initPtr)
        throw std::out_of_range("header point out of range of the stackallocator");

    Header* header = reinterpret_cast<Header*>(headerInitPtr);

    m_offsetPtr = header->prevHeaderTopPtr;
    Logger::get().log(m_className, Logger::ErrType::INFO, "Current m_offsetPtr address ", (void*)m_offsetPtr);
}

std::size_t StackAllocator::size() 
{
    return m_offsetPtr - m_initPtr;
}

StackAllocator::StackAllocator() 
{
    m_initPtr = static_cast<char*>(std::malloc(s_stackSize));
    if (!m_initPtr)
        throw std::bad_alloc();

    m_offsetPtr = m_initPtr;
    Logger::get().log(m_className, Logger::ErrType::INFO, "Memmory for stack with size of ", s_stackSize, " was allocated");
    Logger::get().log(m_className, Logger::ErrType::INFO, "Current m_offsetPtr address ", (void*)m_offsetPtr);
}

StackAllocator::~StackAllocator() 
{
    std::free(m_initPtr);
    Logger::get().log(m_className, Logger::ErrType::INFO, "Memmory is freed from the stack");
}

char* StackAllocator::alignUp(char* addr, std::uint16_t alignment) 
{
    return reinterpret_cast<char*>((reinterpret_cast<uintptr_t>(m_offsetPtr) + alignment - 1) & ~(alignment - 1));
}
