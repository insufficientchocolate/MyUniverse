#ifndef _UNIVERSE_SDL_ERROR_H_
#define _UNIVERSE_SDL_ERROR_H_
#include <stdexcept>
#include "error.hpp"

namespace Universe {
namespace Errors {
class SDLError : public Error {
 public:
  SDLError(const std::string& category);
};
};  // namespace Errors
};  // namespace Universe

#endif