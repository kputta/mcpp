#include <gflags/gflags.h>

#include <bitset>
#include <iostream>
#include <sstream>

#include "ciphers/caesar.hpp"
#include "hackers/caesar-hacker.hpp"
#include "hackers/transposition-hacker.hpp"

DEFINE_string(t, "Hello World! 🤯", "plaintext to test ciphers");
DEFINE_int32(k, 3, "print details");

void try_caesar(std::string_view ciphertext) {
  crypto::CaesarHacker hacker1{crypto::Dictionary::kGoogle1000English};
  auto start = std::chrono::system_clock::now();
  int key1 = hacker1.hack(ciphertext);
  auto end = std::chrono::system_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::cout << "time taken to hack using goole dictionary: " << elapsed.count() << ". And probable key is " << key1 << "\n";


  crypto::CaesarHacker hacker2{crypto::Dictionary::kNorvig10000English};
  start = std::chrono::system_clock::now();
  int key2 = hacker2.hack(ciphertext);
  end = std::chrono::system_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "time take to hack using norvig dictionary : " << elapsed.count() << ". And probable key is " << key2 << "\n";

}

void try_transposition(std::string_view ciphertext) {
  crypto::TranspositionHacker hacker1{crypto::Dictionary::kGoogle1000English};
  auto start = std::chrono::system_clock::now();
  auto key1 = hacker1.hack(ciphertext);
  auto end = std::chrono::system_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::cout << "time take to hack using google dictionary: " << elapsed.count() << ". And probable key is " << key1.first << " " << key1.second << "\n";

  crypto::TranspositionHacker hacker2{crypto::Dictionary::kNorvig10000English};
  start = std::chrono::system_clock::now();
  auto key2 = hacker2.hack(ciphertext);
  end = std::chrono::system_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "time taken to hack using norvig dictionary: " << elapsed.count() << ". And probable key is " << key2.first << " " << key2.second << "\n";
}

int main(int argc, char** argv) {
  gflags::SetUsageMessage("encrypt/decrypt message with reverse cipher");
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  // caesar
  crypto::Caesar::CaesarKey ck{3};
  crypto::Caesar cc{ck};
  std::string ciphertext = cc.encrypt(FLAGS_t);
  std::cout << "Testing CaesarHacker with cipher-text: " << ciphertext << " generated using key: " << ck << "\n";
  try_caesar(ciphertext);

  // transposition
  crypto::Transposition::TranspositionKey tk{std::make_pair(8, "oh!")};
  crypto::Transposition tc{tk};
  ciphertext = tc.encrypt(FLAGS_t);
  std::cout << "Testing TranspostionHacker with cipher-text: " << ciphertext << " generated using key: " << tk.first << ":"  << tk.second << "\n";
  try_transposition(ciphertext);

  return 0;
}
