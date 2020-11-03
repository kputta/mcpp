// expanded header path
#include <gflags/gflags.h>

#include <iostream>

#include "ciphers/reverse.hpp"

DEFINE_string(t, "", "plain/cipher-text to encrypt/decrypt");
DEFINE_bool(e, false, "convert plaintext to ciphertext");
DEFINE_bool(d, false, "convert ciphertext to plaintext");

int main(int argc, char** argv) {
  gflags::SetUsageMessage("encrypt/decrypt message with reverse cipher");
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  // TODO: why curly braces are better ?
  crypto::Reverse cipher("");
  if (FLAGS_e) {
    std::cout << "Ciphertext: " << cipher.encrypt(FLAGS_t) << std::endl;
  }
  if (FLAGS_d) {
    std::cout << "Plaintext: " << cipher.decrypt(FLAGS_t) << std::endl;
  }
  return 0;
}
