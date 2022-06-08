/*
   • file : COpenGL33Renderer.hpp
   • date : 08/06/2022
   • project : Engine
   • author : Brohoya
*/

#ifndef GAME_ENGINE_C_OPENGL_33_RENDERER__
#define GAME_ENGINE_C_OPENGL_33_RENDERER__

#include "Rendering/Renderer/IRenderer.hpp"
#include "Rendering/Renderer/OpenGL33/COpenGL33Renderer.hpp"

namespace Ge
{
    class COpenGL33Renderer : public IRenderer
    {
        public: 
            ~IRenderer     () override;
            void Initialize(const SRendererCreateInfo& renderer_create_info) final;
            void Release   () final;

        private :
            COpenGL33Renderer m_window;

    };
} // !namespace Ge



#endif // !GAME_ENGINE_C_OPENGL_33_RENDERER__