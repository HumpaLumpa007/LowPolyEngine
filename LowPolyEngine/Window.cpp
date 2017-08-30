#include "Window.h"
#include <string>
#include "stdafx.h"
#include "SwapChain.h"
#include <future>

lpe::Window::Window(const uint32_t width, const uint32_t height, std::string&& title, const bool resizeable)
{
	InitWindow(width, height, title, resizeable);
}

lpe::Window::Window(const uint32_t width, const uint32_t height, const std::string& title, const bool resizeable)
{
	InitWindow(width, height, title, resizeable);
}

lpe::Window::~Window()
{
	// TODO: device.waitIdle();
	glfwDestroyWindow(window);
}

void lpe::Window::InitWindow(const uint32_t width, const uint32_t height, const std::string& title, const bool resizeable)
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	glfwWindowHint(GLFW_RESIZABLE, resizeable ? GLFW_TRUE : GLFW_FALSE);

	window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	this->width = width;
	this->height = height;

	SwapChain swapChain = {title, this};
	this->swapChain = swapChain;
}

bool lpe::Window::IsOpen() const
{
	return !glfwWindowShouldClose(window);
}

void lpe::Window::Render()
{
	glfwPollEvents();

	// TODO: UpdateUniformBuffers();
	// TODO: DrawFrame();

	// TODO: calculate FPS?
}

uint32_t lpe::Window::GetHeight() const
{
	return height;
}

uint32_t lpe::Window::GetWidth() const
{
	return width;
}
