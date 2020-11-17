#include <gflags/gflags.h>

#include <iostream>
#include <sstream>
#include <bitset>
#include "boost/locale/encoding.hpp"
#include "boost/locale/encoding_errors.hpp"
#include "boost/regex/pending/unicode_iterator.hpp"


DEFINE_string(t, "", "plain/cipher-text to encrypt/decrypt");

int main(int argc, char** argv) {
  gflags::SetUsageMessage("encrypt/decrypt message with reverse cipher");
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  for(unsigned int i = 0; i < FLAGS_t.size(); i++) {
    std::cout << FLAGS_t[i] << " " << sizeof(FLAGS_t[i]) << " " << int(FLAGS_t[i]) << " " << std::bitset<8>(FLAGS_t[i]) << " ";
  }
  std::cout << "\n";

  for (boost::u8_to_u32_iterator<std::string::iterator> it(FLAGS_t.begin()), end(FLAGS_t.end()); it != end; ++it) {
    std::cout << "\"" << *it << "\", ";
  }
  std::cout << std::endl;
  std::cout << boost::locale::conv::from_utf<char>(FLAGS_t, "UTF-8", boost::locale::conv::method_type::stop) << std::endl;

  std::string latin1_string = boost::locale::conv::from_utf(FLAGS_t,"UTF-8");
  std::string utf8_string = boost::locale::conv::to_utf<char>(latin1_string,"UTF-8");  
  std::wstring wide_string = boost::locale::conv::to_utf<wchar_t>(latin1_string,"UTF-8");
  std::string utf8_string2 = boost::locale::conv::utf_to_utf<char>(wide_string);

  std::cout << latin1_string << " " << utf8_string  << " " << utf8_string2 << std::endl;
  return 0;

}
