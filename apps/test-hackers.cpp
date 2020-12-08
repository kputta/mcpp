#include <gflags/gflags.h>

#include <bitset>
#include <iostream>
#include <sstream>

#include "ciphers/caesar.hpp"
#include "hackers/caesar-hacker.hpp"

DEFINE_string(t, "Hello World! 🤯", "plaintext to test ciphers");
DEFINE_int32(k, 3, "print details");

void try_caesar(std::string_view text, int key) {
  crypto::Caesar::CaesarKey ck{key};
  crypto::Caesar encrypt{ck};
  std::string ciphertext = encrypt.encrypt(text);

  crypto::CaesarHacker hacker1{crypto::Dictionary::kGoogle1000English};
  auto start = std::chrono::system_clock::now();
  int key1 = hacker1.hack(ciphertext);
  auto end = std::chrono::system_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::cout << "time: " << elapsed.count() << '\n';
  if (key1 >= 0) {
    std::cout << "Probable key for ceasar cipher is " << key1 << "\n";
  }

  crypto::CaesarHacker hacker2{crypto::Dictionary::kNorvig10000English};
  start = std::chrono::system_clock::now();
  int key2 = hacker2.hack(ciphertext);
  end = std::chrono::system_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "time: " << elapsed.count() << '\n';
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
