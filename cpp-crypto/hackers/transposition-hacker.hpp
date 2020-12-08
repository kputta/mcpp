#pragma once

#include <algorithm>
#include <unordered_set>

#include "ciphers/transposition.hpp"
#include "hackers/hacker.hpp"

namespace crypto {
class TranspositionHacker : public Hacker<Transposition::TranspositionKey> {
 public:
  TranspositionHacker(Dictionary dict);
  ~TranspositionHacker(){};
  Transposition::TranspositionKey hack(std::string_view ciphertext);

 private:
  bool exists(const std::string& word) {
    return (words_by_length_.find(word) != words_by_length_.end());
  }

  std::unordered_set<std::string> words_by_length_;
  std::string_view pdelimiter_ = " ";
};
}  // namespace crypto
