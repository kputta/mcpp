#include "hackers/transposition-hacker.hpp"

#include <algorithm>
#include <boost/algorithm/string.hpp>  // Include for boost::to_lower
#include <boost/algorithm/string/classification.hpp>  // Include boost::for is_any_of
#include <boost/algorithm/string/split.hpp>  // Include for boost::split
#include <locale>

namespace crypto {

TranspositionHacker::TranspositionHacker(Dictionary d) {
  load_words_um(d, words_by_length_);
}

Transposition::TranspositionKey TranspositionHacker::hack(std::string_view ciphertext) {
  int mxn = ciphertext.size();
  std::string pad = " ";
  Transposition::TranspositionKey key{std::make_pair(1, pad)};
  unsigned int max_score = 0;
  Transposition decryptor{key};
  std::vector<std::string> words;
  for (int i = 1; i < mxn; i++) {
    if (mxn % i == 0) {
      decryptor.set_key(std::make_pair(i, pad));
      unsigned int score = 0;
      boost::split(words, decryptor.decrypt(ciphertext),
                   boost::is_any_of(pdelimiter_), boost::token_compress_on);
      for (const auto& it : words) {
        if (exists(boost::algorithm::to_lower_copy(it))) {
          score += 1;
        }
      }
      if (score > 0) {
        if (score > max_score) {
          key = std::make_pair(i, pad);
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
  }
  return key;
}

}  // namespace crypto
