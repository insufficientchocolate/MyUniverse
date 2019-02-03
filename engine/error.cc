#include <universe/engine/error.hpp>
#include <sstream>

namespace Universe::Errors {
static std::string join(std::vector<std::string> categories) {
  std::stringstream ss;
  for (int i = 0; i < categories.size(); i++) {
    if (i != 0) {
      ss << ".";
    }
    ss << categories[i];
  }
  return ss.str();
}
static const char* kReasonMissing = "unknown";
Error::Error(const std::string& category)
    : std::runtime_error(kReasonMissing), category_(category){};
Error::Error(const std::string& category, const std::string& what)
    : std::runtime_error(what), category_(category){};
Error::Error(const std::string& category, const char* what)
    : std::runtime_error(what), category_(category){};
Error::Error(const std::vector<std::string> categories)
    : std::runtime_error(kReasonMissing), category_(join(categories)){};
Error::Error(const std::vector<std::string> categories, const std::string& what)
    : std::runtime_error(what), category_(join(categories)){};
Error::Error(const std::vector<std::string> categories, const char* what)
    : std::runtime_error(what), category_(join(categories)){};
const std::string& Error::getCategory() const noexcept { return category_; }
const char* Error::what() const noexcept {
  std::stringstream ss;
  ss << "category: " << getCategory()
     << " reason: " << std::runtime_error::what();
  return ss.str().c_str();
}
};  // namespace Universe::Errors
