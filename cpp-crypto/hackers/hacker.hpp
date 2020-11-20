#pragma once

#include <iostream>
#include <string>

#include "utils/loader.hpp"

namespace crypto {

enum class Dictionary {
  kGoogle1000English = 0,
  kNorvig10000English,
};

inline std::ostream& operator<<(std::ostream& out, const Dictionary& value) {
  switch (value) {
    case Dictionary::kGoogle1000English:
      out << "Google1000English";
      break;
    case Dictionary::kNorvig10000English:
      out << "Norvig10000English";
      break;
    default:
      out << "Unknown";
      break;
  }
  return out;
}

void load_words(Dictionary, std::map<int, std::vector<std::string>>&);

class Hacker {
 public:
  Hacker() {}
  virtual ~Hacker(){};
  virtual std::string hack(std::string_view ciphertext) = 0;
};
}  // namespace crypto
