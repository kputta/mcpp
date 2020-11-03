#include "reverse.hpp"

#include <algorithm>

using namespace std;
namespace crypto {

// TODO: check string view (read-only)
// TODO: copy + reverse together
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
