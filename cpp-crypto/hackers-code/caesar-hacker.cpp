#include "hackers/caesar-hacker.hpp"

#include <algorithm>
#include <boost/algorithm/string.hpp>  // Include for boost::to_lower
#include <boost/algorithm/string/classification.hpp>  // Include boost::for is_any_of
#include <boost/algorithm/string/split.hpp>  // Include for boost::split
#include <locale>

namespace crypto {

CaesarHacker::CaesarHacker(Dictionary d) {
#if USE_VECTOR == 0
  std::cout << "using 1d-vector\n";
  load_words_uv(d, words_by_length_);
#elif USE_VECTOR == 1
  std::cout << "using 2d-vector\n";
  load_words(d, words_by_length_);
#else
  std::cout << "using unordered_set\n";
  load_words_um(d, words_by_length_);
#endif
}

Caesar::CaesarKey CaesarHacker::hack(std::string_view ciphertext) {
  Caesar::CaesarKey key = -1;
  unsigned int max_score = 0;
  Caesar decryptor{0};
  std::vector<std::string> words;
  for (Caesar::CaesarKey i = 0; i < Caesar::kMaxKey; i++) {
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
