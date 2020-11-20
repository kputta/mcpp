#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <iomanip>
 
// utility function for output
void hex_print(const std::string& s)
{
    std::cout << std::hex << std::setfill('0');
    for(unsigned char c : s)
        std::cout << std::setw(2) << static_cast<int>(c) << ' ';
    std::cout << std::dec << '\n';
}
 
int main()
{

  std::string plaintext = "Hello World! 😝";
  // from_bytes: byte_string to wide_string
  // to_bytes: wide_string to byte_string
  std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv_;
  std::cout << "byte_string_len: " << plaintext.size() << ", wide_string_len: " << conv_.from_bytes(plaintext).size() << "\n"; 
  
  // wide character data
    std::wstring wstr =  L"z\u00df\u6c34\U0001f34c"; // or L"zß水🍌"
 
    // wide to UTF-8
    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv1;
    std::string u8str = conv1.to_bytes(wstr);
    std::cout << "UTF-8 conversion produced " << u8str.size() << " bytes:\n";
    hex_print(u8str);
 
    // wide to UTF-16le
    std::wstring_convert<std::codecvt_utf16<wchar_t, 0x10ffff, std::little_endian>> conv2;
    std::string u16str = conv2.to_bytes(wstr);
    std::cout << "UTF-16le conversion produced " << u16str.size() << " bytes:\n";
    hex_print(u16str);


    /*
    std::locale::global(std::locale("en_US.utf8"));
    auto& f = std::use_facet<std::codecvt<wchar_t, char, std::mbstate_t>>(std::locale());
    std::wstring internal = L"z\u00df\u6c34\U0001f34c"; // L"zß水🍌"
 
    // note that the following can be done with wstring_convert
    std::mbstate_t mb{}; // initial shift state
    std::string external(internal.size() * f.max_length(), '\0'); 
    const wchar_t* from_next;
    char* to_next;
    f.out(mb, &internal[0], &internal[internal.size()], from_next,
              &external[0], &external[external.size()], to_next);
    // error checking skipped for brevity
    external.resize(to_next - &external[0]);
 
    std::cout << "The string in narrow multibyte encoding: " << external << '\n';
    */
}
