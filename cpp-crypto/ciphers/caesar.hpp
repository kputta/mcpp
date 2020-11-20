#pragma once
#include <codecvt>
#include <locale>

#include "ciphers/cipher.hpp"

namespace crypto {

/*
 Code points can be between 0x0 and 0x10FFFF in hexadecimal or between 0 and
 1114111 in decimal As such unicode code points can be represented by 21 bits.
 21 bits can have a min value of 0 and a max value of 2097151 in decimal.
 1111XXXX 10XXXXXX 10XXXXXX 10XXXXXX
 4 + 6 + 6 + 6 = 21 bits
 some are invalid
 char32_t is unsgined and value range 0 to 1114111
*/
class Caesar : Cipher {
 public:
  Caesar(int key) : Cipher(), key_(key) {}
  std::string encrypt(std::string_view plaintext);
  std::string decrypt(std::string_view ciphertext);
  void set_key(int key) { key_ = key; }
  static constexpr int kMaxKey = 1114111;

 private:
  int key_;
  std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> code_convertor_;
};
}  // namespace crypto
