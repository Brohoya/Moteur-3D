/*
   • file : IWindow.cpp
   • date : 31/05/2022
   • project : Engine
   • author : Brohoya
*/

#include "Rendering/Renderer/IWindow.hpp"

namespace Ge
{
    GLFWwindow* IWindow::GetHandle() {
        return mp_window;
    }
} // !namespace Ge
