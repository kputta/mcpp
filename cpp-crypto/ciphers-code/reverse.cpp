#include "reverse.hpp"

#include <algorithm>

namespace crypto {

// TODO: check string view (read-only)
// TODO: copy + reverse together
std::string Reverse::encrypt(const std::string& plaintext) {
  std::string ciphertext(plaintext);
  std::reverse(ciphertext.begin(), ciphertext.end());
  return ciphertext;
}

std::string Reverse::decrypt(const std::string& ciphertext) {
  std::string plaintext(ciphertext);
  std::reverse(plaintext.begin(), plaintext.end());
  return plaintext;
}

}  // namespace crypto
