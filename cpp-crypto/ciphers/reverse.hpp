#pragma once
#include <codecvt>
#include <locale>
#include "ciphers/cipher.hpp"

namespace crypto {
class Reverse : Cipher {
 public:
  Reverse() : Cipher() {}
  std::string encrypt(std::string_view plaintext);
  std::string decrypt(std::string_view ciphertext);
 private:
  std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv_;
};
}  // namespace crypto
