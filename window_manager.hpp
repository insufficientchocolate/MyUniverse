#ifndef _UNIVERSE_WINDOW_MANAGER_H_
#define _UNIVERSE_WINDOW_MANAGER_H_
#include <SDL.h>
namespace Universe::Graphic {
class WindowManager {
 public:
  WindowManager(SDL_Window* window);
};
};  // namespace Universe::Graphic
#endif