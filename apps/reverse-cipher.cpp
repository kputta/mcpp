#include <iostream>
#include <gflags/gflags.h>
#include "reverse.hpp"

DEFINE_string(t, "", "plain/cipher-text to encrypt/decrypt");
DEFINE_bool(e, false, "convert plaintext to ciphertext");
DEFINE_bool(d, false, "convert ciphertext to plaintext");

int main(int argc, char** argv) {
  gflags::SetUsageMessage("encrypt/decrypt message with reverse cipher");
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  auto cipher = crypto::Reverse("");
  if (FLAGS_e) {
    std::cout << "Ciphertext: " << cipher.encrypt(FLAGS_t) << "\n";
  }
  if (FLAGS_d) {
    std::cout << "Plaintext: " << cipher.decrypt(FLAGS_t) << "\n";
  }
  return 0;
}
