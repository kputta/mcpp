#include <gflags/gflags.h>

#include <bitset>
#include <iostream>
#include <sstream>

#include "ciphers/caesar.hpp"
#include "ciphers/reverse.hpp"
#include "ciphers/transposition.hpp"

DEFINE_string(t, "Hello World! 🤯", "plain/cipher-text to encrypt/decrypt");
DEFINE_bool(v, false, "print details");
DEFINE_int32(ck, 3, "key for caesar cipher");
DEFINE_string(tk, "3:Oh!", "key for transposition cipher");

void test_reverse(std::string_view text, bool verbose) {
  crypto::Reverse encrypt{};
  crypto::Reverse decrypt{};

  std::string ciphertext = encrypt.encrypt(text);
  std::string plaintext = decrypt.decrypt(ciphertext);

  if (text.compare(plaintext) == 0) {
    std::cout << "\nReverse-Cipher: Success (ciphertext: " << ciphertext
              << ")\n";
  } else {
    std::cout << "\nReverse-Cipher: Failed" << std::endl;
  }

  if (verbose) {
    std::cout << "converted ciphertext bytes: ";
    for (unsigned int i = 0; i < ciphertext.size(); i++) {
      std::cout << ciphertext[i] << " " << std::bitset<8>(ciphertext[i]) << " ";
    }
    std::cout << "\nretrieved plaintext bytes: ";
    for (unsigned int i = 0; i < plaintext.size(); i++) {
      std::cout << plaintext[i] << " " << std::bitset<8>(plaintext[i]) << " ";
    }
    std::cout << "\n";
  }
}

void test_caesar(std::string_view text, bool verbose, int key) {
  crypto::Caesar encrypt{key};
  crypto::Caesar decrypt{key};

  std::string ciphertext = encrypt.encrypt(text);
  std::string plaintext = decrypt.decrypt(ciphertext);

  if (text.compare(plaintext) == 0) {
    std::cout << "\nCaesar-Cipher: Success (ciphertext: " << ciphertext
              << ")\n";
  } else {
    std::cout << "\nCaesar-Cipher: Failed" << std::endl;
  }

  if (verbose) {
    std::cout << "converted ciphertext bytes: ";
    for (unsigned int i = 0; i < ciphertext.size(); i++) {
      std::cout << ciphertext[i] << " " << std::bitset<8>(ciphertext[i]) << " ";
    }
    std::cout << "\nretrieved plaintext bytes: ";
    for (unsigned int i = 0; i < plaintext.size(); i++) {
      std::cout << plaintext[i] << " " << std::bitset<8>(plaintext[i]) << " ";
    }
    std::cout << "\n";
  }
}

void test_transposition(std::string_view text, bool verbose,
                        std::string key_pair) {
  auto index = key_pair.find(":");
  auto numrows = std::stoi(key_pair.substr(0, key_pair.size() - index));

  crypto::Transposition::TranspositionKey key{
      std::make_pair(numrows, key_pair.substr(index + 1, std::string::npos))};

  crypto::Transposition encrypt{key};
  crypto::Transposition decrypt{key};

  std::string ciphertext = encrypt.encrypt(text);
  std::string plaintext = decrypt.decrypt(ciphertext);

  if (text.compare(plaintext) == 0) {
    std::cout << "\nTransposition-Cipher: Success (ciphertext: " << ciphertext
              << ")\n";
  } else {
    std::cout << "\nTransposition-Cipher: Failed" << std::endl;
  }

  if (verbose) {
    std::cout << "converted ciphertext bytes: ";
    for (unsigned int i = 0; i < ciphertext.size(); i++) {
      std::cout << ciphertext[i] << " " << std::bitset<8>(ciphertext[i]) << " ";
    }
    std::cout << "\nretrieved plaintext bytes: ";
    for (unsigned int i = 0; i < plaintext.size(); i++) {
      std::cout << plaintext[i] << " " << std::bitset<8>(plaintext[i]) << " ";
    }
    std::cout << "\n";
  }
}

int main(int argc, char** argv) {
  gflags::SetUsageMessage("encrypt/decrypt message with reverse cipher");
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  if (FLAGS_v) {
    std::cout << "Input bytes(text size: " << FLAGS_t.size() << "): ";
    for (unsigned int i = 0; i < FLAGS_t.size(); i++) {
      std::cout << FLAGS_t[i] << " " << std::bitset<8>(FLAGS_t[i]) << " ";
    }
  }
  std::cout << std::endl;
  // reverse
  test_reverse(FLAGS_t, FLAGS_v);

  // caesar
  test_caesar(FLAGS_t, FLAGS_v, FLAGS_ck);

  // transposition
  test_transposition(FLAGS_t, FLAGS_v, FLAGS_tk);

  return 0;
}
