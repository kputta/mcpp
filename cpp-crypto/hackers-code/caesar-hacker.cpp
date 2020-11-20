#include "hackers/caesar-hacker.hpp"

#include <algorithm>
#include <boost/algorithm/string.hpp>  // Include for boost::to_lower
#include <boost/algorithm/string/classification.hpp>  // Include boost::for is_any_of
#include <boost/algorithm/string/split.hpp>  // Include for boost::split
#include <locale>

#include "ciphers/caesar.hpp"

namespace crypto {

CaesarHacker::CaesarHacker(Dictionary d) {
  load_words(d, words_by_length_);
  std::cout << "{" << d << ": ";
  for (auto const& [key, val] : words_by_length_) {
    std::cout << key << ": " << val.size() << ", ";
  }
  std::cout << "}\n";
}

int CaesarHacker::hack(std::string_view ciphertext) {
  int key = -1;
  unsigned int max_score = 0;
  Caesar decryptor{0};
  std::vector<std::string> words;
  for (int i = 0; i < Caesar::kMaxKey; i++) {
    unsigned int score = 0;
    decryptor.set_key(i);
    boost::split(words, decryptor.decrypt(ciphertext),
                 boost::is_any_of(pdelimiter_), boost::token_compress_on);
    for (const auto& it : words) {
      if (exists(boost::algorithm::to_lower_copy(it))) {
        score += 1;
        std::cout << "Mapped: " << it << "\n";
      }
    }
    if (score > 0) {
      if (score > max_score) {
        key = i;
        max_score = score;
        if (max_score == words.size()) {
          std::cout << "max score " << max_score << " reached with key: " << i
                    << "\n";
          return key;
        }
      }
      std::cout << "score for key: " << i << " is " << score << "\n";
    }
  }
  return key;
}

}  // namespace crypto
