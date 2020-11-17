#include <gflags/gflags.h>

#include <bitset>
#include <iostream>
#include <sstream>

#include "utils/unicode.hpp"
#include "utils/utf8-iter.hpp"

DEFINE_string(t, "", "plain/cipher-text to encrypt/decrypt");

int main(int argc, char** argv) {
  gflags::SetUsageMessage("encrypt/decrypt message with reverse cipher");
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  for (unsigned int i = 0; i < FLAGS_t.size(); i++) {
    std::cout << FLAGS_t[i] << " " << sizeof(FLAGS_t[i]) << " "
              << int(FLAGS_t[i]) << " " << std::bitset<8>(FLAGS_t[i]) << " ";
  }
  std::cout << "\n";

  bool found = false;
  for (utils::Utf8Iterator codePointIterator(FLAGS_t.begin());
       !found && codePointIterator != FLAGS_t.end(); ++codePointIterator) {
    found = *codePointIterator >= 0x0C00 && *codePointIterator <= 0x0C7F;
  }
  if (found) {
    std::cout << "Found telugu characters in the text" << std::endl;
  }
  return 0;
}
