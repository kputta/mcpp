#include "utils/utf8-iter.hpp"

namespace utils {

const unsigned char kFirstBitMask = 128;  // 1000000
const unsigned char kSecondBitMask = 64;  // 0100000
const unsigned char kThirdBitMask = 32;   // 0010000
const unsigned char kFourthBitMask = 16;  // 0001000
const unsigned char kFifthBitMask = 8;    // 0000100

Utf8Iterator::Utf8Iterator(std::string::const_iterator it) : iterator_(it) {}

Utf8Iterator::Utf8Iterator(const Utf8Iterator& source)
    : iterator_(source.iterator_) {}

Utf8Iterator& Utf8Iterator::operator=(const Utf8Iterator& rhs) {
  iterator_ = rhs.iterator_;
  return *this;
}

Utf8Iterator::~Utf8Iterator() {}

Utf8Iterator& Utf8Iterator::operator++() {
  char firstByte = *iterator_;
  std::string::difference_type offset = 1;
  // This means the first byte has a value greater than 127, and so is beyond
  // the ASCII range.
  if (firstByte & kFirstBitMask) {
    // This means that the first byte has a value greater than 224, and so it
    // must be at least a three-octet code point.
    if (firstByte & kThirdBitMask) {
      // This means that the first byte has a value greater than 240, and so it
      // must be a four-octet code point.
      if (firstByte & kFourthBitMask) {
        offset = 4;
      } else {
        offset = 3;
      }
    } else {
      offset = 2;
    }
  }

  iterator_ += offset;
  return *this;
}

Utf8Iterator Utf8Iterator::operator++(int) {
  Utf8Iterator temp = *this;
  ++(*this);
  return temp;
}

Utf8Iterator& Utf8Iterator::operator--() {
  --iterator_;
  // This means that the previous byte is not an ASCII character.
  if (*iterator_ & kFirstBitMask) {
    --iterator_;
    if ((*iterator_ & kSecondBitMask) == 0) {
      --iterator_;
      if ((*iterator_ & kSecondBitMask) == 0) {
        --iterator_;
      }
    }
  }
  return *this;
}

Utf8Iterator Utf8Iterator::operator--(int) {
  Utf8Iterator temp = *this;
  --(*this);
  return temp;
}

char32_t Utf8Iterator::operator*() const {
  char32_t codePoint = 0;
  char firstByte = *iterator_;
  // This means the first byte has a value greater than 127, and so is beyond
  // the ASCII range.
  if (firstByte & kFirstBitMask) {
    // This means that the first byte has a value greater than 191, and so it
    // must be at least a three-octet code point.
    if (firstByte & kThirdBitMask) {
      // This means that the first byte has a value greater than 224, and so it
      // must be a four-octet code point.
      if (firstByte & kFourthBitMask) {
        codePoint = (firstByte & 0x07) << 18;
        char secondByte = *(iterator_ + 1);
        codePoint += (secondByte & 0x3f) << 12;
        char thirdByte = *(iterator_ + 2);
        codePoint += (thirdByte & 0x3f) << 6;
        ;
        char fourthByte = *(iterator_ + 3);
        codePoint += (fourthByte & 0x3f);
      } else {
        codePoint = (firstByte & 0x0f) << 12;
        char secondByte = *(iterator_ + 1);
        codePoint += (secondByte & 0x3f) << 6;
        char thirdByte = *(iterator_ + 2);
        codePoint += (thirdByte & 0x3f);
      }
    } else {
      codePoint = (firstByte & 0x1f) << 6;
      char secondByte = *(iterator_ + 1);
      codePoint += (secondByte & 0x3f);
    }
  } else {
    codePoint = firstByte;
  }
  return codePoint;
}

bool Utf8Iterator::operator==(const Utf8Iterator& rhs) const {
  return iterator_ == rhs.iterator_;
}

bool Utf8Iterator::operator!=(const Utf8Iterator& rhs) const {
  return iterator_ != rhs.iterator_;
}

bool Utf8Iterator::operator==(std::string::iterator rhs) const {
  return iterator_ == rhs;
}

bool Utf8Iterator::operator==(std::string::const_iterator rhs) const {
  return iterator_ == rhs;
}

bool Utf8Iterator::operator!=(std::string::iterator rhs) const {
  return iterator_ != rhs;
}

bool Utf8Iterator::operator!=(std::string::const_iterator rhs) const {
  return iterator_ != rhs;
}
}  // namespace utils
