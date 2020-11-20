#include "ciphers/reverse.hpp"

#include <algorithm>

namespace crypto {
std::string Reverse::encrypt(std::string_view plaintext) {
  std::u32string plaintext32{conv_.from_bytes(plaintext.begin())};
  std::u32string ciphertext32;
  ciphertext32.resize(plaintext32.size());
  std::reverse_copy(plaintext32.begin(), plaintext32.end(),
                    ciphertext32.begin());
  return conv_.to_bytes(ciphertext32);
}

std::string Reverse::decrypt(std::string_view ciphertext) {
  std::u32string ciphertext32{conv_.from_bytes(ciphertext.begin())};
  std::u32string plaintext32;
  plaintext32.resize(ciphertext32.size());
  std::reverse_copy(ciphertext32.begin(), ciphertext32.end(),
                    plaintext32.begin());
  return conv_.to_bytes(plaintext32);
}

}  // namespace crypto
