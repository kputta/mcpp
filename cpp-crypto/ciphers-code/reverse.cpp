#include <algorithm>

#include "reverse.hpp"

using namespace std;
namespace crypto {

string Reverse::encrypt(const string& plaintext) {
  string ciphertext(plaintext);
  reverse(ciphertext.begin(), ciphertext.end());
  return ciphertext;
}

string Reverse::decrypt(const string& ciphertext) {
  string plaintext(ciphertext);
  reverse(plaintext.begin(), plaintext.end());
  return plaintext;
}

}  // namespace crypto
