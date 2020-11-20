#include "hackers/hacker.hpp"

namespace crypto {

void load_words(Dictionary dictionary, std::map<int, std::vector<std::string>>& container) {
  if (dictionary == Dictionary::kGoogle1000English) {
    utils::load_gte(container);
  } else if (dictionary == Dictionary::kNorvig10000English) {
    utils::load_tkwf(container);
  } else {
    throw "Dictionary not found to load words\n";
  }
}

}
