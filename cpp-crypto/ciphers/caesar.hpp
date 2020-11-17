#pragma once

#include "cipher.hpp"

namespace crypto {
class Caesar : Cipher {
 public:
  Caesar(int key) : Cipher(), key_(key) {}
  std::string encrypt(std::string_view plaintext);
  std::string decrypt(std::string_view ciphertext);

 private:
  int key_;
};
}  // namespace crypto
