#pragma once

#include <cstdlib>

class StackAllocator
{
public:
    static StackAllocator& get(); 

    void* allocate(std::size_t size);
    void deallocate(); 
private:
    StackAllocator(); 
    ~StackAllocator(); 

    StackAllocator(const StackAllocator&) = delete;
    StackAllocator &operator=(const StackAllocator&) = delete;

    struct Header {
        std::size_t sizeOfPrevTakenMem;
    };

    char* m_initPtr = nullptr;
    char* m_offsetPtr = nullptr;

    static constexpr const char* m_className = "StackAllocator";

    static std::size_t s_stackSize;
};
