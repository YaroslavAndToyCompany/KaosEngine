#pragma once

#include <cstddef>
#include <cstdlib>
#include <new>

template <class T, std::size_t N>
class ArenaBasedAlloc {
public:
    ArenaBasedAlloc();
    ~ArenaBasedAlloc();

    void* allocateOne();
    void* allocateArray(std::size_t);
    void deallocateOne(void*) noexcept;
    void deallocateArray(void*) noexcept;

private:
    char* basePtr;
    char* curPtrPos;
    
    ArenaBasedAlloc(const ArenaBasedAlloc&) = delete;
    ArenaBasedAlloc& operator=(const ArenaBasedAlloc&) = delete;
};

template <typename T, std::size_t N>
ArenaBasedAlloc<T, N>::ArenaBasedAlloc()
    : basePtr(static_cast<char*>(std::malloc(N * sizeof(T))))
{
    if (!basePtr) throw std::bad_alloc();
    curPtrPos = basePtr;
}

template <typename T, std::size_t N>
void* ArenaBasedAlloc<T, N>::allocateOne()
{
    char* memToReturn = curPtrPos;
    curPtrPos += sizeof(T);
    return memToReturn;
}

template <typename T, std::size_t N>
void* ArenaBasedAlloc<T, N>::allocateArray(std::size_t n)
{
    char* memToReturn = curPtrPos;
    curPtrPos += n * sizeof(T);
    return memToReturn;
}

template <typename T, std::size_t N>
void ArenaBasedAlloc<T, N>::deallocateOne(void* mem) noexcept {}

template <typename T, std::size_t N>
void ArenaBasedAlloc<T, N>::deallocateArray(void* mem) noexcept {}


