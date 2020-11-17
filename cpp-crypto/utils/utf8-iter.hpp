#pragma once

#include <string>

// borrowed from: http://www.nubaria.com/en/blog/?p=371

namespace utils {
class Utf8Iterator {
 public:
  Utf8Iterator(std::string::const_iterator it);
  Utf8Iterator(const Utf8Iterator& source);
  Utf8Iterator& operator=(const Utf8Iterator& rhs);
  ~Utf8Iterator();

  Utf8Iterator& operator++();
  Utf8Iterator operator++(int);
  Utf8Iterator& operator--();
  Utf8Iterator operator--(int);
  char32_t operator*() const;

  bool operator==(const Utf8Iterator& rhs) const;
  bool operator!=(const Utf8Iterator& rhs) const;
  bool operator==(std::string::iterator rhs) const;
  bool operator==(std::string::const_iterator rhs) const;
  bool operator!=(std::string::iterator rhs) const;
  bool operator!=(std::string::const_iterator rhs) const;

 private:
  std::string::const_iterator iterator_;
};
}  // namespace utils
