#include "main_render.hpp"
#include <SDL.h>
#include "sdl_error.hpp"

namespace Universe {
static const GLfloat bufferData[] = {
    -1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
};
MainRender::MainRender(SDL_Window* window) { initContext(window); }

void MainRender::initContext(SDL_Window* window) {
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, true);
  SDL_GLContext gContext = SDL_GL_CreateContext(window);
  if (gContext == nullptr) {
    throw Universe::Errors::SDLError{"OpenGL"};
  }
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    throw Universe::Errors::Error{"GLEW"};
  }
  glClearColor(0, 1, 0, 1);
  glGenVertexArrays(1, &vao_);
  glBindVertexArray(vao_);
  glGenBuffers(1, &triangleBuffer_);
  glBindBuffer(GL_ARRAY_BUFFER, triangleBuffer_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(bufferData), bufferData, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void MainRender::render() { drawTriangle(); }

void MainRender::drawTriangle() {
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, triangleBuffer_);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glDisableVertexAttribArray(0);
}
};  // namespace Universe
