#include <gflags/gflags.h>

#include <bitset>
#include <iostream>
#include <sstream>

#include "ciphers/caesar.hpp"
#include "hackers/caesar-hacker.hpp"

DEFINE_string(t, "Hello World! 🤯", "plaintext to test ciphers");
DEFINE_int32(k, 3, "print details");

void try_caesar(std::string_view text, int key) {
  crypto::Caesar encrypt{key};
  std::string ciphertext = encrypt.encrypt(text);

  crypto::CaesarHacker hacker1{crypto::Dictionary::kGoogle1000English};
  int key1 = hacker1.hack(ciphertext);
  if (key1 >= 0) {
    std::cout << "Probable key for ceasar cipher is " << key1 << "\n";
  }
  crypto::CaesarHacker hacker2{crypto::Dictionary::kNorvig10000English};
  int key2 = hacker2.hack(ciphertext);
  if (key2 >= 0) {
    std::cout << "Probable key for ceasar cipher is " << key2 << "\n";
  }
}

int main(int argc, char** argv) {
  gflags::SetUsageMessage("encrypt/decrypt message with reverse cipher");
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  // caesar
  try_caesar(FLAGS_t, FLAGS_k);
  return 0;
}
