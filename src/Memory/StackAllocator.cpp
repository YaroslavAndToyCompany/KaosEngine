#include "Memory/StackAllocator.hpp"

#include "Utils/Logger.hpp"

std::size_t StackAllocator::s_stackSize = 1024;

StackAllocator& StackAllocator::get() 
{
    static StackAllocator stack;
    return stack;
}

void* StackAllocator::allocate(std::size_t size) 
{
    void *memToReturn = m_offsetPtr;

    m_offsetPtr += size;

    Header* header = reinterpret_cast<Header*>(m_offsetPtr);
    header->sizeOfPrevTakenMem = size;

    m_offsetPtr += sizeof(Header);

    Logger::get().log(m_className, Logger::ErrType::INFO, size + sizeof(Header), " Memory is given for some object");
    Logger::get().log(m_className, Logger::ErrType::INFO, "Current m_offsetPtr address ", (void*)m_offsetPtr);
    return memToReturn;
}

void StackAllocator::deallocate() 
{
    m_offsetPtr -= sizeof(Header);
    Header* header = reinterpret_cast<Header*>(m_offsetPtr);

    m_offsetPtr -= header->sizeOfPrevTakenMem;
    Logger::get().log(m_className, Logger::ErrType::INFO, header->sizeOfPrevTakenMem + sizeof(Header), " Memmory is freed from one object");
    Logger::get().log(m_className, Logger::ErrType::INFO, "Current m_offsetPtr address ", (void*)m_offsetPtr);
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
