#ifndef NEOSTAR_WINDOW_H
#define TOMATO_WINDOW_H

#include "GLFW/glfw3.h"

namespace neostar {
class Window {
 public:
  struct window_parameter {
    uint32_t width, height;
    const char *title;
    void (*func)();
  };

  void create_window(window_parameter wp) {
    init_window(wp.width, wp.height, wp.title);
    main_loop(wp.func);
    close_window();
  }

 private:
  GLFWwindow *Window;

  void init_window(int width, int height, const char *title) {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
  }
  void main_loop(void (*func)()) {
    while (!glfwWindowShouldClose(Window)) {
      glfwPollEvents();
      func();
    }
  }
  void close_window() {
    glfwDestroyWindow(Window);

    glfwTerminate();
  }
};
}  // namespace neostar

#endif