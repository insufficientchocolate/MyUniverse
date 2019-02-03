#include <SDL.h>
#include <sstream>
#include <universe/engine/sdl_error.hpp>

namespace Universe::Errors {
static const char* kSDLCategory = "SDL";
SDLError::SDLError(const std::string& category)
    : Error({kSDLCategory, category}, SDL_GetError()){};
};  // namespace Universe::Errors
