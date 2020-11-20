#include "ciphers/caesar.hpp"

namespace crypto {
std::string Caesar::encrypt(std::string_view plaintext) {
  std::u32string plaintext32{code_convertor_.from_bytes(plaintext.begin())};
  for (auto& c: plaintext32) {
    c = (c + key_) % kMaxKey;
  }
  return code_convertor_.to_bytes(plaintext32);
}

std::string Caesar::decrypt(std::string_view ciphertext) {
  std::u32string ciphertext32{code_convertor_.from_bytes(ciphertext.begin())};
  for (auto& c: ciphertext32) {
    c = (key_ > c) ? (kMaxKey - (key_ - c) % kMaxKey) : ((c - key_) % kMaxKey);
  }
  return code_convertor_.to_bytes(ciphertext32);
}

}  // namespace crypto
