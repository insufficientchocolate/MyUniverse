#include "window_manager.hpp"
#include <GL/glew.h>
#include <OpenGL/gl.h>
#include <stdexcept>
#include "error.hpp"
#include "sdl_error.hpp"

namespace Universe::Graphic {
WindowManager::WindowManager(SDL_Window* window) {
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, true);
  SDL_GLContext gContext = SDL_GL_CreateContext(window);
  if (gContext == nullptr) {
    throw Universe::Errors::SDLError{"OpenGL"};
  }
  SDL_GL_SetSwapInterval(1);
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    throw Universe::Errors::Error{"GLEW"};
  }

  glClearColor(0, 0, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  SDL_GL_SwapWindow(window);
}
};  // namespace Universe::Graphic