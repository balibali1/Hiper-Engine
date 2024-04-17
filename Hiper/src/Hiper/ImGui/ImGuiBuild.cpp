#include "hppch.h"

#define IMGUI_IMPL_OPENGL_LOADER_GLAD

// 编译文件
// 由于使用的ImGui版本为v1.73，文件的位置有所不同
// "example/" -> "backends/"
#include "backends/imgui_impl_opengl3.cpp"
#include "backends/imgui_impl_glfw.cpp"

