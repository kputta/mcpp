#pragma once
#include <codecvt>
#include <locale>
#include <cmath>
#include "ciphers/cipher.hpp"

namespace crypto {
// AOS or SOA
// Armadillo/eigen (pybind) (boost linalg -> uBLAS)

class Transposition : public Cipher {
 public:
  using TranspositionKey = std::pair<int32_t, std::string>;
  Transposition(TranspositionKey key) : Cipher() {
    set_key(key);
  }

  std::string encrypt(std::string_view plaintext);
  std::string decrypt(std::string_view ciphertext);
  void set_key(TranspositionKey key) {
    key_ = key;
    padstr_ = code_convertor_.from_bytes(key_.second);
    auto dv = std::div(key_.first, padstr_.size());
    while(dv.quot--) {
      maxpadstr_.append(padstr_);
    }
    maxpadstr_.append(padstr_.substr(0, dv.rem));
  }

 private:
  inline WideString transpose(WideString text, int num_rows, int num_cols) {
    WideStringStream ttext;
    for(size_t i = 0; i < text.size(); i++) {
      auto dv = std::div(i, num_rows);
      ttext << text[dv.quot + dv.rem * num_cols];
    }
    return ttext.str();
  }

  inline WideString truncate(WideString text) {
    for(int i = maxpadstr_.size(); i > 0; i--) {
      if (text.substr(text.size() - i) == maxpadstr_.substr(0, i)) {
        return text.substr(0, text.size() - i);
      }
    }
    return text;
  }
 
  TranspositionKey key_;
  WideString padstr_;
  WideString maxpadstr_;
  std::wstring_convert<std::codecvt_utf8<WideChar>, WideChar> code_convertor_;
};
}  // namespace crypto
