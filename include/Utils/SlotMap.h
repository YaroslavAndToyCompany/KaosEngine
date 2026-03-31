#pragma once
#include <vector>

struct AssetHandle
{
	const uint32_t MAX = std::numeric_limits<uint32_t>::max();
	uint32_t m_index;
	uint32_t m_generation;
};

template<typename T>
class SlotMap
{
	struct Slot
	{
		Slot(T& data) : m_data(data) {}
		uint32_t m_freeIndex;
		uint32_t m_generation = 0;
		bool bIsActive = false;
	};
	std::vector<T> m_data;
	std::vector<Slot> m_slots;
	std::vector<uint32_t> m_freelist;
	const uint32_t m_firstFreeIndex = MAX;
public:
	SlotMap();

	template<typename T>
	T& insert(m_data)
	{
		if (m_firstFreeIndex == MAX)
			m_slots.emplace_back(std::forward(m_data));
	}
};