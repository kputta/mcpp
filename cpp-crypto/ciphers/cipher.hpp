#pragma once

#include <iostream>
#include <string>

namespace crypto {
class Cipher {
 public:
  Cipher() {}
  virtual ~Cipher(){};
  virtual std::string encrypt(std::string_view plaintext) = 0;
  virtual std::string decrypt(std::string_view ciphertext) = 0;
};
}  // namespace crypto
