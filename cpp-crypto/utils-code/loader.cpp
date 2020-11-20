#include "utils/loader.hpp"

#include <boost/algorithm/string.hpp>  // Include for boost::to_lower
#include <fstream>

namespace utils {

constexpr std::string_view data_dir = "/Users/kputta/src/mcpp/cpp-crypto/data";

void load_gte(std::map<int, std::vector<std::string>>& container) {
  std::string path = fs::path(data_dir) / fs::path("google-10000-english.txt");
  std::ifstream infile(path);
  std::string line;
  while (std::getline(infile, line)) {
    container[line.size()].push_back(std::move(line));
  }
}

void load_tkwf(std::map<int, std::vector<std::string>>& container) {
  std::string path = fs::path(data_dir) / fs::path("count_1w100k.txt");
  std::ifstream infile(path);
  std::string line;
  std::string delimiter = "\t";
  while (std::getline(infile, line)) {
    size_t pos = 0;
    if ((pos = line.find(delimiter)) != std::string::npos) {
      container[pos].push_back(
          boost::algorithm::to_lower_copy(line.substr(0, pos)));
    }
  }
}

}  // namespace utils
