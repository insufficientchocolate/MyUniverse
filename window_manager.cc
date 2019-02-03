#include "window_manager.hpp"
#include <chrono>
#include <iostream>
#include <stdexcept>
#include "error.hpp"
#include "main_render.hpp"

namespace Universe::Graphic {
WindowManager::WindowManager(SDL_Window* window)
    : window_(window), running_(true) {
  startRenderingThread();
}
void WindowManager::startRenderingThread() {
  renderingThread_ = std::make_unique<std::thread>([&] {
    try {
      MainRender render(window_);
      while (running_) {
        render.render();
        SDL_GL_SwapWindow(window_);
        std::this_thread::sleep_for(std::chrono::seconds(1));
      }
    } catch (const std::runtime_error& e) {
      std::cout << e.what() << std::endl;
    }
  });
}
}  // namespace Universe::Graphic
