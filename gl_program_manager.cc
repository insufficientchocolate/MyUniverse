#include "gl_program_manager.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include "error.hpp"

namespace Universe {
GLProgramManager::GLProgramManager(const std::string& shaderDirectory)
    : sourceDir_(shaderDirectory) {}

static GLuint compileShader(const std::string& source, GLenum shaderType) {
  GLuint shader = glCreateShader(shaderType);
  char const* sourceChar = source.c_str();
  glShaderSource(shader, 1, &sourceChar, nullptr);
  glCompileShader(shader);
  GLint result;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
  if (result != GL_TRUE) {
    GLint logLength;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> errorMessage(logLength + 1);
    glGetShaderInfoLog(shader, logLength, nullptr, &errorMessage[0]);
    std::string error(errorMessage.begin(), errorMessage.end());
    throw Errors::Error("OpenGL", error);
  }
  return shader;
}

GLuint GLProgramManager::compileProgram(const std::string& vertexPath,
                                        const std::string& fragmentPath) const {
  GLuint vShader = compileShader(loadSource(vertexPath), GL_VERTEX_SHADER);
  GLuint fShader = compileShader(loadSource(fragmentPath), GL_FRAGMENT_SHADER);
  GLuint program = glCreateProgram();
  glAttachShader(program, vShader);
  glAttachShader(program, fShader);
  glLinkProgram(program);

  GLint result;
  glGetProgramiv(program, GL_LINK_STATUS, &result);
  if (result != GL_TRUE) {
    GLint logLength;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> errorMessage(logLength + 1);
    glGetProgramInfoLog(program, logLength, nullptr, &errorMessage[0]);
    std::string error(errorMessage.begin(), errorMessage.end());
    throw Errors::Error("OpenGL", error);
  }
  return program;
}

const std::string GLProgramManager::loadSource(const std::string& path) const {
  std::fstream fin((sourceDir_ / path).native());
  fin.exceptions(std::fstream::badbit);
  std::stringstream ss;
  ss << fin.rdbuf();
  return ss.str();
}
}  // namespace Universe
