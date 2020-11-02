#include <string>

using namespace std;

namespace crypto {
class Cipher {
 public:
  Cipher(const string& key) : key(key) {}
  virtual string encrypt(const string& plaintext) = 0;
  virtual string decrypt(const string& ciphertext) = 0;
 protected:
  string key;
};
}
