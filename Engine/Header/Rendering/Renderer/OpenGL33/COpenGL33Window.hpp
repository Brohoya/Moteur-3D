/*
   • file : COpenGL33Window.hpp
   • date : 31/05/2022
   • project : Engine
   • author : Brohoya
*/

#ifndef ORDINAL_ENGINE_C_OPEN_GL_33_WINDOW_HPP_
#define ORDINAL_ENGINE_C_OPEN_GL_33_WINDOW_HPP_

#include "Rendering/Renderer/IWindow.hpp"

namespace Ge 
{

class COpenGL33Window : public IWindow
{
    public:
        ~COpenGL33Window() override;
        void Initialize(const SWindowCreateInfo& window_create_info) final;
        void Release() final;

};

};

#endif // !ORDINAL_ENGINE_C_OPEN_GL_33_WINDOW_HPP_
