/*
   • file : IRenderer.cpp
   • date : 01/06/2022
   • project : Engine
   • author : Brohoya
*/

#include "Rendering/Renderer/IRenderer.hpp"

namespace Ge
{

   IWindow* IRenderer::GetWindow() {
      return mp_window;
   };

} // !namespace Ge
