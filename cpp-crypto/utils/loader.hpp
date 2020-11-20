#pragma once

#include <iostream>
#include <filesystem>
#include <map>
#include <vector>

namespace utils {

namespace fs = std::filesystem;
/*
Pros of the header-only style:
- Easy to use: No linkage to the libraries or compilation of single compilation units (–> all the single .cpp files) are needed, a simple #include is enough to get it all working
- Templated classes can only be implemented header-only.

Cons of the header-only style:
- For really big projects, compilation time might increase. However, you might really write a lot of code until this gets really noticable

Other:
- if function get_path is defined in loader.hpp, and foo.cpp and bar.cpp both include loader.hpp, then foo.o and bar.o will both include copies of get_path.
When welink those two object files together, the linker will see that the symbol get_path is defined more than once, and won't allow it.
- if you declare the function to be static, then no symbol will be exported
 */

std::string_view get_path(std::string_view);
// https://github.com/first20hours/google-10000-english
void load_gte(std::map<int, std::vector<std::string>>&);
// https://norvig.com/ngrams/
void load_tkwf(std::map<int, std::vector<std::string>>&);

}

