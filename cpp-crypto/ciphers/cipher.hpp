#pragma once

#include <string>

// TODO: key defn & requirement is not standard

namespace crypto {
class Cipher {
 public:
  Cipher(const std::string& key) : key(key) {}
  virtual ~Cipher(){};
  virtual std::string encrypt(const std::string& plaintext) = 0;
  virtual std::string decrypt(const std::string& ciphertext) = 0;

 protected:
  std::string key;
};
}  // namespace crypto
