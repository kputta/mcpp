#pragma once

#include <algorithm>
#include <vector>

#include "ciphers/caesar.hpp"
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

class CaesarHacker : public Hacker<Caesar::CaesarKey> {
 public:
  CaesarHacker(Dictionary dict);
  ~CaesarHacker(){};
  Caesar::CaesarKey hack(std::string_view ciphertext);

 private:
  bool exists(const std::string& word) {
#if USE_VECTOR == 0
    return (std::find(words_by_length_.begin(), words_by_length_.end(), word) !=
            words_by_length_.end());
#elif USE_VECTOR == 1
    auto& group = words_by_length_[word.size()];
    return (std::find(group.begin(), group.end(), word) != group.end());
#else
    return (words_by_length_.find(word) != words_by_length_.end());
#endif
  }

  /*
    vector O(N), ordered_set O(log N), unordered_set O(1)
    complexity ignores constant factors and different containers
    have various traversal overheads.
    contiguous memory, hash function
    but elements are not added/deleted
    cache misses and branch predictions are same for vector unordered_map
   */
#if USE_VECTOR == 0
  std::vector<std::string> words_by_length_;
#elif USE_VECTOR == 1
  std::map<int, std::vector<std::string> > words_by_length_;
#else
  std::unordered_set<std::string> words_by_length_;
#endif
  std::string_view pdelimiter_ = " ";
};
}  // namespace crypto
