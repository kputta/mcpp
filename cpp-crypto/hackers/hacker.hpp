#pragma once

#include <iostream>
#include <string>

#include "utils/loader.hpp"

// branching based on istype
#define USE_VECTOR 1

namespace crypto {

// enum class limits the scope
// needs explicit cast to convert
// underlying type is int
// enum class Dictionary: std::uint32_t (default is int)
enum class Dictionary {
  kGoogle1000English = 0,
  kNorvig10000English,
};

// instead of explicity casting
// following template functions takes enum and returns its value
// during the complite time, so can be used with templates
template <typename E>
constexpr auto toUType(E enumerator) noexcept {
  return static_cast<std::underlying_type_t<E>>(enumerator);
}

// why inline, because defination becomes a symbol in the object file and symbol
// can only be defined once
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
void load_words_um(Dictionary, std::unordered_set<std::string>&);
void load_words_uv(Dictionary, std::vector<std::string>&);

template <class CipherKey>
class Hacker {
 public:
  Hacker() {}
  virtual ~Hacker(){};
  virtual CipherKey hack(std::string_view ciphertext) = 0;
};
}  // namespace crypto
