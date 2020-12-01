#include "hackers/hacker.hpp"

namespace crypto {

void load_words(Dictionary dictionary,
                std::map<int, std::vector<std::string>>& container) {
  if (dictionary == Dictionary::kGoogle1000English) {
    utils::load_gte(container);
  } else if (dictionary == Dictionary::kNorvig10000English) {
    utils::load_tkwf(container);
  } else {
    throw "Dictionary not found to load words\n";
  }
}

void load_words_um(Dictionary dictionary,
                   std::unordered_set<std::string>& container) {
  if (dictionary == Dictionary::kGoogle1000English) {
    utils::load_gte_um(container);
  } else if (dictionary == Dictionary::kNorvig10000English) {
    utils::load_tkwf_um(container);
  } else {
    throw "Dictionary not found to load words\n";
  }
}

void load_words_uv(Dictionary dictionary,
                   std::vector<std::string>& container) {
  if (dictionary == Dictionary::kGoogle1000English) {
    utils::load_gte_uv(container);
  } else if (dictionary == Dictionary::kNorvig10000English) {
    utils::load_tkwf_uv(container);
  } else {
    throw "Dictionary not found to load words\n";
  }
}

}  // namespace crypto
