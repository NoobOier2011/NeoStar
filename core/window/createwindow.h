#ifndef NEOSTAR_WINDOW_H
#define TOMATO_WINDOW_H

#include <iostream>
#include "GLFW/glfw3.h"

namespace neostar {
class Window {
 public:
  struct window_parameter {
    uint32_t width, height;
    const char *title;
    void (*func)();
  };

  bool create_window(window_parameter wp) {
    if (!check_window()) return false;
    init_window(wp.width, wp.height, wp.title);
    main_loop(wp.func);
    close_window();
    return true;
  }

 private:
  GLFWwindow *Window;

  bool check_window() {
    if (getenv("DISPLAY") == nullptr) {
      std::cerr << "No display server found, skipping window creation!" << std::endl;
      return false;
    }
    
    std::cerr << "Display server found!" << std::endl;
    return true;
  }

  void init_window(int width, int height, const char *title) {
    glfwInit();

    // glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    // glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    glfwMakeContextCurrent(Window);
  }

  void main_loop(void (*func)()) {
    while (!glfwWindowShouldClose(Window)) {
      glfwPollEvents();
      func();
      
      glfwSwapBuffers(Window);
    }
  }
  void close_window() {
    glfwDestroyWindow(Window);

    glfwTerminate();
  }
};
}  // namespace neostar

#endif