#include "../include/GLFW/glfw3.h"
#include "window/createwindow.h"

using namespace neostar;

namespace neostar {
class main {
  public:
   void create_main_window() {
    Window main_window;
    main_window.create_window({1280, 720, "NeoStar", window_running_static});
   }
  private:
   static void window_running_static() {
    
   }
};
}  // namespace neostar

int main(int argc, char** argv) {
  neostar::main Main;
  Main.create_main_window();

  return 0;
}