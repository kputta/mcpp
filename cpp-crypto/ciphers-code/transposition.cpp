#include "ciphers/transposition.hpp"

namespace crypto {
std::string Transposition::encrypt(std::string_view plaintext) {
  WideString plaintext32{code_convertor_.from_bytes(plaintext.begin())};
  auto num_cols = std::ceil(plaintext32.size() / (float)key_.first);
  int pad_len = num_cols * key_.first - plaintext32.size();
  plaintext32.append(maxpadstr_.substr(0, pad_len));
  return code_convertor_.to_bytes(transpose(plaintext32, key_.first, num_cols));
}

std::string Transposition::decrypt(std::string_view ciphertext) {
  WideString ciphertext32{code_convertor_.from_bytes(ciphertext.begin())};
  auto num_rows = std::ceil(ciphertext32.size() / (float)key_.first);
  ciphertext32 = truncate(transpose(ciphertext32, num_rows, key_.first));
  return code_convertor_.to_bytes(ciphertext32);
}

}  // namespace crypto
