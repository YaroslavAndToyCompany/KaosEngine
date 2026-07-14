#pragma once
#include <vector>
#include <memory>
#include <cstdint>
#include "Renderer/VertexBuffer.hpp"

class IndexBuffer
{
public:
    IndexBuffer(const std::uint32_t* indices, std::uint32_t size);
    ~IndexBuffer();

    IndexBuffer(const IndexBuffer&) = delete;
    IndexBuffer& operator=(const IndexBuffer&) = delete;

    void bind() const;
    void unbind() const;

    inline std::uint32_t getCount() const { return m_size; }
private:
    std::uint32_t m_rendererID = 0;
    std::uint32_t m_size = 0;
};
