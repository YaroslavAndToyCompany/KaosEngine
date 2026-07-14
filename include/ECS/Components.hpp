#pragma once
#include "Renderer/VertexArray.hpp"
#include "Utils/SlotMap.hpp"
#include <memory>

struct TransformComponent
{
	float transform;
};

struct MeshComponent
{
    std::shared_ptr<VertexArray> vertexArray;
    AssetHandle shaderHandle;
};