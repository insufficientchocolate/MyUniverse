#include "window_manager.hpp"
#include <GL/glew.h>
#include <OpenGL/gl.h>
#include <chrono>
#include <stdexcept>
#include "error.hpp"
#include "sdl_error.hpp"

namespace Universe::Graphic {
WindowManager::WindowManager(SDL_Window* window)
    : window_(window), running_(true) {
  startRenderingThread();
}
void WindowManager::renderingLoop() { glClear(GL_COLOR_BUFFER_BIT); }
void WindowManager::startRenderingThread() {
  std::thread t([&] {
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, true);
    SDL_GLContext gContext = SDL_GL_CreateContext(window_);
    if (gContext == nullptr) {
      throw Universe::Errors::SDLError{"OpenGL"};
    }
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
      throw Universe::Errors::Error{"GLEW"};
    }
    glClearColor(0, 1, 0, 1);
    while (running_) {
      renderingLoop();
      SDL_GL_SwapWindow(window_);
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  });
  t.detach();
}
}  // namespace Universe::Graphic