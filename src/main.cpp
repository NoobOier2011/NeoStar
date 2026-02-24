#include "../include/GLFW/glfw3.h"
#include "window/createwindow.h"

using namespace neostar;

namespace neostar {
void window_running_func() {}
}  // namespace neostar

int main(int argc, char** argv) {
  Window main_window;
  main_window.create_window({1280, 720, "NeoStar", neostar::window_running_func});

  return 0;
}