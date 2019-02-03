#include "sdl_error.hpp"
#include <SDL.h>
#include <sstream>

namespace Universe::Errors {
static const char* kSDLCategory = "SDL";
SDLError::SDLError(const std::string& category)
    : Error({kSDLCategory, category}, SDL_GetError()){};
};  // namespace Universe::Errors