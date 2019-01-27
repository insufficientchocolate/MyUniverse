#include "gl_program_manager.hpp"
#include <vector>

namespace Universe
{
  GLProgramManager::GLProgramManager(const std::string& shaderDirectory): sourceDir_(shaderDirectory)
  {}

  static GLuint compileShader(char const ** source,GLenum shaderType) {
	GLuint shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, source, nullptr);
	glCompileShader(shader);
	GLint result;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	if (result != GL_TRUE) {
	  GLint logLength;
	  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
	  std::vector<char> errorMessage(logLength + 1);
	  glGetShaderInfoLog(shader, logLength,nullptr, &errorMessage[0]);
	  throw Error("OpenGL", errorMessage);
	}
  }

  GLuint GLProgramManager::compileProgram(const std::string& vertexPath,const std::string& fragmentPath)
  {
	std::string sources = loadSource(vertexPath);
	char const *vectorSourcePointer = sources.c_str();
	glShaderSource(vShader, 1,&vectorSourcePointer, NULL)
	glCompileShader(vShader);
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &result);

  }

  const std::string loadSource(const std::string& path)
  {
  }
}
