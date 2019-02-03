#ifndef _UNIVERSE_GL_PROGRAM_MANAGER_HPP
#define _UNIVERSE_GL_PROGRAM_MANAGER_HPP
#include <GL/glew.h>
#include <SDL.h>
#include <boost/filesystem.hpp>
#include <string>

namespace Universe {
class GLProgramManager {
 public:
  GLProgramManager(const std::string& shaderDirectory);
  GLuint compileProgram(const std::string& vertexPath,
                        const std::string& fragmentPath) const;

 private:
  const boost::filesystem::path sourceDir_;
  const std::string loadSource(const std::string& path) const;
};
};     // namespace Universe
#endif /* GL_PROGRAM_MANAGER_HPP */
