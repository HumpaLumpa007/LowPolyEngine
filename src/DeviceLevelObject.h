#pragma once

#include "helper.h"

namespace lpe
{
  namespace vulkan
  {
    class Instance;
    class PhysicalDevice;
    class Device;

    class DeviceLevelObject
    {
    protected:
      helper::Pointer<Instance> instance;
      helper::Pointer<PhysicalDevice> physicalDevice;
      helper::Pointer<Device> device;

      vk::Instance VkInstance() const;
      vk::PhysicalDevice VkPhysicalDevice() const;
      vk::Device VkDevice() const;
    public:
      DeviceLevelObject() = default;
      DeviceLevelObject(const DeviceLevelObject& other);
      DeviceLevelObject(DeviceLevelObject&& other) noexcept;
      DeviceLevelObject& operator=(const DeviceLevelObject& other);
      DeviceLevelObject& operator=(DeviceLevelObject&& other) noexcept;

      explicit DeviceLevelObject(Instance* instance,
                                 PhysicalDevice* physicalDevice,
                                 Device* device);

      virtual ~DeviceLevelObject() = default;
    };
  }
}