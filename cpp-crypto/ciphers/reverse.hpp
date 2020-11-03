#pragma once

#include "cipher.hpp"

using namespace std;

namespace crypto {
class Reverse : Cipher {
 public:
  Reverse(const string& key) : Cipher(key) {}
  string encrypt(const string& plaintext);
  string decrypt(const string& ciphertext);
};
}  // namespace crypto
