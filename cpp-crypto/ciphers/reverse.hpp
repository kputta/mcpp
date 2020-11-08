#pragma once

#include "cipher.hpp"

namespace crypto {
class Reverse : Cipher {
 public:
  Reverse(const std::string& key) : Cipher(key) {}
  std::string encrypt(const std::string& plaintext);
  std::string decrypt(const std::string& ciphertext);
};
}  // namespace crypto
