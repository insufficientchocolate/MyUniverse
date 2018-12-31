#ifndef _UNIVERSE_ERROR_H_
#define _UNIVERSE_ERROR_H_
#include <stdexcept>
#include <string>
#include <vector>

namespace Universe::Errors {
class Error : public std::runtime_error {
 public:
  Error(const std::string& category);
  Error(const std::string& category, const std::string& what);
  Error(const std::string& category, const char* what);
  Error(const std::vector<std::string> categories);
  Error(const std::vector<std::string> categories, const std::string& what);
  Error(const std::vector<std::string> categories, const char* what);
  const std::string& getCategory() const noexcept;
  virtual const char* what() const noexcept;

 private:
  const std::string category_;
};
};  // namespace Universe::Errors

#endif