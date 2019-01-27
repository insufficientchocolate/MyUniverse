#include "window_manager.hpp"
#include <chrono>
#include <stdexcept>
#include "error.hpp"
#include "main_render.hpp"

namespace Universe::Graphic {
WindowManager::WindowManager(SDL_Window* window)
    : window_(window), running_(true) {
  startRenderingThread();
}
void WindowManager::startRenderingThread() {
  std::thread t([&] {
    MainRender render(window_);
    while (running_) {
      render.render();
      SDL_GL_SwapWindow(window_);
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  });
  t.detach();
}
}  // namespace Universe::Graphic
