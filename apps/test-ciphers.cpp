#include <gflags/gflags.h>

#include <iostream>
#include <sstream>
#include <bitset>
#include "ciphers/reverse.hpp"

DEFINE_string(t, "", "plain/cipher-text to encrypt/decrypt");
DEFINE_bool(v, false, "print details");

int main(int argc, char** argv) {
  gflags::SetUsageMessage("encrypt/decrypt message with reverse cipher");
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  // reverse-cipher
  crypto::Reverse encrypt{};
  crypto::Reverse decrypt{};

  std::string ciphertext = encrypt.encrypt(FLAGS_t);
  std::string plaintext = decrypt.decrypt(ciphertext);

  if (FLAGS_t.compare(plaintext) == 0) {
    std::cout << "\nReverse-Cipher: Success" << std::endl;
  } else {
    std::cout << "\nReverse-Cipher: Failed" << std::endl;
  }

  if (FLAGS_v) {
    std::cout << "input: \n";
    for(unsigned int i = 0; i < FLAGS_t.size(); i++) {
      std::cout << FLAGS_t[i] << " " << sizeof(FLAGS_t[i]) << " " << int(FLAGS_t[i]) << " " << std::bitset<8>(FLAGS_t[i]) << " ";
    }
    std::cout << "\nconverted ciphertext bytes: \n";
    for(unsigned int i = 0; i < ciphertext.size(); i++) {
      std::cout << ciphertext[i] << " " << sizeof(ciphertext[i]) << " " << int(ciphertext[i]) << " " << std::bitset<8>(ciphertext[i]) << " ";
    }
    std::cout << "\nretrieved plaintext bytes: \n";
    for(unsigned int i = 0; i < plaintext.size(); i++) {
      std::cout << plaintext[i] << " " << sizeof(plaintext[i]) << " " << int(plaintext[i]) << " " << std::bitset<8>(plaintext[i]) << " ";
    }
    std::cout << "\n";
  }
  return 0;
}
