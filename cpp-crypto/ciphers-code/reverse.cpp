#include "reverse.hpp"

#include <algorithm>

namespace crypto {

/*
  Note: Reverse only works for ASCII set for now.
  std::reverse_copy invoked with standard std::string iterators (as in
  this example) will simply reverse the code units of a string and not
  necessarily the characters (depending on the encoding). For example a UTF-8
  encoded string that contains multibyte characters would not be reversed
  correctly by this function as the multibyte sequences would also be reversed
  making them invalid.
*/

std::string Reverse::encrypt(std::string_view plaintext) {
  std::string ciphertext;
  ciphertext.resize(plaintext.size());
  std::reverse_copy(plaintext.begin(), plaintext.end(), ciphertext.begin());
  return ciphertext;
}

std::string Reverse::decrypt(std::string_view ciphertext) {
  std::string plaintext;
  plaintext.resize(ciphertext.size());
  std::reverse_copy(ciphertext.begin(), ciphertext.end(), plaintext.begin());
  return plaintext;
}

}  // namespace crypto
