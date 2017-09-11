#ifndef VERTEX_H
#define VERTEX_H

#include <vulkan/vulkan.hpp>
#include <vector>
#include <array>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/hash.hpp>
#include "stdafx.h"

BEGIN_LPE
  struct Vertex
  {
    glm::vec3 position;
    glm::vec3 normals;
    glm::vec3 color;
    glm::vec2 texCoord;

    static vk::VertexInputBindingDescription getBindingDescription()
    {
      return {0, sizeof(Vertex), vk::VertexInputRate::eVertex};
    }

    static decltype(auto) getAttributeDescriptions()
    {
      std::array<vk::VertexInputAttributeDescription, 4> descriptions = {};
      descriptions[0] = {0, 0, vk::Format::eR32G32B32Sfloat, offsetof(Vertex, position)};
      descriptions[1] = {1, 0, vk::Format::eR32G32B32Sfloat, offsetof(Vertex, normals)};
      descriptions[2] = {2, 0, vk::Format::eR32G32B32Sfloat, offsetof(Vertex, color)};
      descriptions[3] = {3, 0, vk::Format::eR32G32Sfloat, offsetof(Vertex, texCoord)};

      return descriptions;
    }

    bool operator==(const Vertex& other) const
    {
      return position == other.position &&
             normals == other.normals &&
             color == other.color &&
             texCoord == other.texCoord;
    }
  };

END_LPE

namespace std
{
  template <>
  struct hash<lpe::Vertex>
  {
    size_t operator()(lpe::Vertex const& vertex) const
    {
      return ((hash<glm::vec3>()(vertex.position) ^ (hash<glm::vec3>()(vertex.color) << 1)) >> 1) ^ (hash<glm::vec2>()(vertex.texCoord) << 1); // TODO: add normals to hashgeneration
    }
  };
}

#endif
