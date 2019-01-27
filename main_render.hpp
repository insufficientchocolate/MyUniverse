#ifndef _MY_UNIVERSE_MAIN_RENDER_H
#define _MY_UNIVERSE_MAIN_RENDER_H
#include <GL/glew.h>
#include <SDL.h>
#include <SDL2/SDL_opengl.h>

namespace Universe {
class MainRender {
 public:
  MainRender(SDL_Window* window);
  void render();

 private:
  void drawTriangle();
  void initContext(SDL_Window* window);
  void clean();
  GLuint vao_;
  GLuint triangleBuffer_;
};
}  // namespace Universe
#endif
