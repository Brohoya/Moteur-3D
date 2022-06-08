/*
   • file : COpenGL33Window.cpp
   • date : 31/05/2022
   • project : Engine
   • author : Brohoya
*/

#include <iostream>
#include "Rendering/Renderer/OpenGL33/COpenGL33Window.hpp"

namespace Ge
{

void ErrorCallback(int error, const char* description) { std::cerr << "Error : " << description << std::endl; }

COpenGL33Window::~COpenGL33Window() {
    Release(); // RAII => Ressource acquisition is initialization
}

void COpenGL33Window::Initialize(const SWindowCreateInfo& window_create_info) {

	if(m_initialized) Release();
    // std::cout << "Initializing the OpenGL 3.3 window..." << std::endl;

    /* ===== Configuration d'OpenGL ===== */
	if(!glfwInit()) {
		throw std::runtime_error("Failed to initialize GLFW.");
	}

	glfwSetErrorCallback(ErrorCallback);
	// Activer l'anti-aliasing MSAA => Multi sample anti-aliasing
	glfwWindowHint(GLFW_SAMPLES, 4);
	// Utiliser OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	// Précision pour utiliser les dernières versions du core d'OpenGl ¯\_(ツ)_/¯
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	/* ================================== */

	/* ===== Création de la 1ère fenêtre ===== */
	mp_window = glfwCreateWindow(
        window_create_info.window_width,
        window_create_info.window_height, 
        window_create_info.p_window_title, 
        nullptr, nullptr
    );

	if(!mp_window) {
		glfwTerminate();
		throw std::runtime_error("Failed to initialize window.");
	};

	glfwMakeContextCurrent(mp_window);
	/* ======================================= */
	
	/* ===== Configuration de Glew ===== */
	glewExperimental = GL_TRUE;
	if(glewInit() != GLEW_OK) {
		glfwTerminate();
		throw std::runtime_error("Failed to initialize GLEW.");
	};
	/* ================================= */

	glfwSetInputMode(mp_window, GLFW_STICKY_KEYS, GL_TRUE);

    std::cout << "OpenGL 3.3 window initialized." << std::endl;
}

void COpenGL33Window::Release() {

	if(m_initialized) {
		glfwTerminate();
		mp_window = nullptr;
		m_initialized = false;
		std::cout << "OpenGL 3.3 window released." << std::endl;
	}

}

} //!namespace Ge
