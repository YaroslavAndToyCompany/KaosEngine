#pragma once
#include <iostream>
#include <vector>
#include <limits>

static constexpr uint32_t INVALID_VALUE = std::numeric_limits<uint32_t>::max();

struct AssetHandle
{
    uint32_t m_index = INVALID_VALUE;
    uint32_t m_generation = 0;
    AssetHandle(uint32_t index = INVALID_VALUE, uint32_t generation = 0)
        : m_index(index), m_generation(generation) {
    }
    bool bIsActive() const { return m_index != INVALID_VALUE; }
};

template<typename T>
class SlotMap
{
    struct Slot
    {
        alignas(T) uint8_t m_data[sizeof(T)]; // array of bytes
        uint32_t nextFreeIndex = INVALID_VALUE;
        uint32_t generation = 0;
        bool bIsActive = false;
    };

    std::vector<Slot> m_slots;
    uint32_t m_freeindex = INVALID_VALUE;
    uint32_t m_size = 0;

public:
    SlotMap() = default;

    ~SlotMap()
    {
    for(Slot& slot : m_slots)
     {
    if(slot.bIsActive)
        reinterpret_cast<T*>(slot.m_data);
     }
    }

    template<typename... Args>
    AssetHandle insert(Args&&... args)
    {
        uint32_t index;
        if (m_freeindex != INVALID_VALUE)
        {
            index = m_freeindex;
            m_freeindex = m_slots[index].nextFreeIndex;
        }
        else
        {
            m_slots.emplace_back();
            index = static_cast<uint32_t>(m_slots.size() - 1);
        }

        Slot& slot = m_slots[index];
        new(slot.m_data) T(std::forward<Args>(args)...);

        slot.bIsActive = true;
        slot.nextFreeIndex = INVALID_VALUE;
        m_size++;
        return { index, slot.generation };
    }

    T* get(AssetHandle handle)
    {
        if (handle.m_index < m_slots.size())
        {
            Slot& slot = m_slots[handle.m_index];
            if (slot.bIsActive && slot.generation == handle.m_generation)
                return reinterpret_cast<T*>(slot.m_data); 
        }
        return nullptr;
    }

    void erase(AssetHandle handle)
    {
        if (handle.m_index >= m_slots.size())
            return;

        Slot& slot = m_slots[handle.m_index];
        if (slot.bIsActive && slot.generation == handle.m_generation)
        {
            reinterpret_cast<T*>(slot.m_data)->~T();

            slot.bIsActive = false;
            slot.generation++;
            slot.nextFreeIndex = m_freeindex;
            m_freeindex = handle.m_index;
            m_size--;
        }
    }
};