#include <SDL.h>
#include <iostream>


const int kDefaultWindowWidth = 800;
const int kDefaultWindowHeight = 600;

static void mainLoop()
{
		while (true) {
				SDL_Event event;
				while(SDL_WaitEvent(&event)) {
                    std::cout << event.type << std::endl;
						switch (event.type) {
								case SDL_MOUSEMOTION:
										std::cout << "(" << event.motion.x << "," << event.motion.y << ")" << std::endl;
										break;
								case SDL_QUIT:
										return;
						}
				}
		}
		
}

int main(int argc,char** argv)
{
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
		{
				SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
				return 1;
		}
		SDL_Window *mainWindow = SDL_CreateWindow(
						"MyUniverse",
						SDL_WINDOWPOS_CENTERED,
						SDL_WINDOWPOS_CENTERED,
						kDefaultWindowWidth,
						kDefaultWindowHeight,
						SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL
		);
		mainLoop();

		SDL_Quit();
}
