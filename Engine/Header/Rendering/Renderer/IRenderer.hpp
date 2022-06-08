/*
   • file : IRenderer.hpp
   • date : 01/06/2022
   • project : Engine
   • author : Brohoya
*/

#ifndef ORDINAL_ENGINE_I_RENDERER_HPP_
#define ORDINAL_ENGINE_I_RENDERER_HPP_

#include "Rendering/Renderer/IWindow.hpp"

namespace Ge
{
    // Renderers 
    enum ERendererType 
    {
        OpenGL33,
        OpenGL45,
        Vulkan
    };

    struct SRendererCreateInfo
    {
        ERendererType e_renderer_type;
        SWindowCreateInfo* p_window_create_info;
    };
        
    class IRenderer {
        public: 
            virtual     ~IRenderer()  = default;
            virtual void Initialize(const SRendererCreateInfo& renderer_create_info) = 0;
            virtual void Release()    = 0;

            IWindow* GetWindow();
            
        protected:
            bool     m_initialized = false;
            IWindow* mp_window     = nullptr;
    };

} // !namespace Ge


#endif // !ORDINAL_ENGINE_I_RENDERER_HPP_