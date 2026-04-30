#pragma once

#include "StackAllocator.hpp"

template <typename T>
class StackAllocatorContainer
{
public:
    StackAllocatorContainer();
    ~StackAllocatorContainer();

    T* get() { return object; }

private:
    T* object;
};

template <typename T>
StackAllocatorContainer<T>::StackAllocatorContainer()
{
    void* allocatedMem = StackAllocator::get().allocate<T>();
    object = new (allocatedMem) T();
}

template <typename T>
StackAllocatorContainer<T>::~StackAllocatorContainer<T>()
{
    StackAllocator::get().deallocate();
}
