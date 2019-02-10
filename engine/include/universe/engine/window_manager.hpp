#ifndef _UNIVERSE_WINDOW_MANAGER_H_
#define _UNIVERSE_WINDOW_MANAGER_H_
#include <SDL.h>
#include <memory>
#include <thread>
namespace Universe {
namespace Graphic {
class WindowManager {
 public:
  WindowManager(SDL_Window* window);
  void stop() noexcept;
  ~WindowManager() noexcept;

 private:
  bool running_;
  void startRenderingThread();
  SDL_Window* window_;
  std::unique_ptr<std::thread> renderingThread_;
};
};  // namespace Graphic
};  // namespace Universe
#endif
