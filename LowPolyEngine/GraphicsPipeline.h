#ifndef GRAPHICS_PIPELINE_H
#define GRAPHICS_PIPELINE_H

#include <vulkan/vulkan.hpp>

namespace lpe
{
	class GraphicsPipeline
	{
		vk::PhysicalDevice physicalDevice;
		vk::Device device;

		vk::RenderPass renderPass;
		vk::DescriptorSetLayout descriptorSetLayout;
		vk::PipelineLayout pipelineLayout;
		vk::Pipeline graphicsPipeline;

	protected:
		vk::ShaderModule CreateShaderModule(const std::vector<char>& code);

		void CreateRenderPass(vk::Format swapChainImageFormat);
		void CreateDescriptorSetLayout();
		void CreateGraphicsPipeline(vk::Extent2D swapChainExtent);

	public:
		GraphicsPipeline() = default;
		~GraphicsPipeline();

		vk::Format FindDepthFormat() const;

		void Create(vk::PhysicalDevice physicalDevice, const vk::Device& device, vk::Format swapChainImageFormat, vk::Extent2D swapChainExtent);


		vk::RenderPass GetRenderPass() const;
		vk::DescriptorSetLayout GetDescriptorSetLayout() const;
		vk::PipelineLayout GetPipelineLayout() const;
		vk::Pipeline GetGraphicsPipeline() const;
	};
}

#endif