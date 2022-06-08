# Settings
include_directories(${CMAKE_SOURCE_DIR}/Engine/Header)

# Files
file(GLOB_RECURSE ENGINE_SOURCES *.cpp *.c)
file(GLOB_RECURSE ENGINE_HEADERS *.hpp *.h *.inl)

add_executable(Engine ${ENGINE_SOURCES} ${ENGINE_SOURCES} "main.cpp" "Rendering/Renderer/IWindow.cpp" "Rendering/Renderer/OpenGL33/COpenGL33Window.cpp" "Rendering/Renderer/IRenderer.cpp" "Rendering/Renderer/OpenGL33/COpenGL33Renderer.cpp" "Rendering/IRenderingEngine.cpp")
target_link_libraries(Engine glfw3 glew32)