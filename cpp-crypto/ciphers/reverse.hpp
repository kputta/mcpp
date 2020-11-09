#pragma once

#include "cipher.hpp"

namespace crypto {
class Reverse : Cipher {
 public:
  Reverse() : Cipher() {}
  std::string encrypt(std::string_view plaintext);
  std::string decrypt(std::string_view ciphertext);
};
}  // namespace crypto
