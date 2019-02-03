#ifndef _UNIVERSE_WINDOW_MANAGER_H_
#define _UNIVERSE_WINDOW_MANAGER_H_
#include <SDL.h>
#include <memory>
#include <thread>
namespace Universe::Graphic {
class WindowManager {
 public:
  WindowManager(SDL_Window* window);

 private:
  bool running_;
  void startRenderingThread();
  SDL_Window* window_;
  std::unique_ptr<std::thread> renderingThread_;
};
};  // namespace Universe::Graphic
#endif
