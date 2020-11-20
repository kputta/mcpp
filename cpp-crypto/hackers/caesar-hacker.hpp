#pragma once

#include <algorithm>
#include <vector>

#include "hackers/hacker.hpp"

namespace crypto {
/*
Given a ciphertext we need to retreive the key used by ceaser cipher.
Assumptions:
- text should be from a language, so we apply against a dictionary of the
language (english/latin ..)
- given a dictionary, we could come up with best guess. ciphertext word may
actually not part of the dictionary, we are looking for key with maximum matches
- we assume words are separated by " " in actual plaintext
- given language we assume range of key is limited to # of chars in that
language

Improvements:
- we probably could stop once we hit a match rate ?
 */

class CaesarHacker {
 public:
  CaesarHacker(Dictionary dict);
  ~CaesarHacker(){};
  int hack(std::string_view ciphertext);

 private:
  bool exists(const std::string& word) {
    auto& group = words_by_length_[word.size()];
    return (std::find(group.begin(), group.end(), word) != group.end());
  }
  std::map<int, std::vector<std::string>> words_by_length_;
  std::string_view pdelimiter_ = " ";
};
}  // namespace crypto
