#ifndef _UNIVERSE_GL_PROGRAM_MANAGER_HPP
#define _UNIVERSE_GL_PROGRAM_MANAGER_HPP 
#include <GL/glew.h>
#include <SDL.h>

namespace Universe
{
  class GLProgramManager
  {
	public:
	  GLuint compileProgram(const std::string& vertexPath,const std::string& fragmentPath);
	private:
	  const std::string sourceDir_;
	  const std::string loadSource(const std::string& path);
  }
};
#endif /* GL_PROGRAM_MANAGER_HPP */
