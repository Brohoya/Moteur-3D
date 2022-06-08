/*
   • file : main.cpp
   • date : 31/05/2022
   • project : Engine
   • author : Brohoya
*/

#include <iostream>
#include "Rendering/Renderer/OpenGL33/COpenGL33Window.hpp"

int main(int argc, char** argv) {

	Ge::COpenGL33Window opengl_window;
	Ge::SWindowCreateInfo window_create_info {};
	window_create_info.window_width = 1280;
	window_create_info.window_height = 720;
	window_create_info.p_window_title = "Engine";

	try
	{
		opengl_window.Initialize(window_create_info);
	}
	catch(std::runtime_error& e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
		return -1;
	}

	GLFWwindow* p_window = opengl_window.GetHandle();

	while(!glfwWindowShouldClose(p_window) && glfwGetKey(p_window, GLFW_KEY_ESCAPE) != GLFW_PRESS) 
	{
		glfwSwapBuffers(p_window);
		glfwPollEvents();
	}

	return 0;
}