/*
   • file : COpenGL33Renderer.cpp
   • date : 08/06/2022
   • project : Engine
   • author : Brohoya
*/

#include <iostream>
#include "Rendering/Renderer/OpenGL33/COpenGL33Renderer.hpp"

namespace Ge
{
    void COpenGL33Renderer::Initialize(const SRendererCreateInfo& renderer_create_info) 
    {
        if(m_initialized) {
            Release();
        }

        m_initialized = true;
        m_window.Initialize(*renderer_create_info.p_window_create_info);
        mp_window = &m_window;

        std::cout << "OpenGL 3.3 renderer initialized." << std::endl;
    }

    void COpenGL33Renderer::Release() 
    {
        if(m_initialized) {
            m_window.Release();
            mp_window     = nullptr;
            m_initialized = false;

            std::cout << "OpenGL 3.3 renderer released." << std::endl;
        }
    }
} // !namespace Ge
