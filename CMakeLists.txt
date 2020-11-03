# build executable defined in apps

# here is the fast way
# /usr/local/Cellar/gcc/10.2.0/bin/g++ -std=c++20 -c cpp-crypto/ciphers-code/reverse.cpp -I cpp-crypto/ciphers
# /usr/local/Cellar/gcc/10.2.0/bin/g++ -std=c++20 apps/reverse-cipher.cpp -I cpp-crypto/ciphers reverse.o

# version & standards
cmake_minimum_required(VERSION 3.18.4)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# enable verbose
set(CMAKE_VERBOSE_MAKEFILE ON)

# set compilers
set(CMAKE_C_COMPILIER "gcc-10")
set(CMAKE_CXX_COMPILIER "g++-10")
set(CMAKE_CXX_FLAGS "-std=c++20")

# compilers flags
add_compile_options(-Wall -Wextra -Wpedantic)
# target_compile_features

# set the project name
project(cpp-crypto VERSION 1.0)

# target reverse-cipher
# if we build .a independently then we should provide path to find it
## find_library(CiphersLib Ciphers HINTS cpp-crypto/build/lib REQUIRED)
## target_link_libraries(reverse-cipher ${CiphersLib})
add_subdirectory(external/gflags)
add_subdirectory(cpp-crypto)
add_executable(reverse-cipher "apps/reverse-cipher.cpp")
target_include_directories(reverse-cipher PUBLIC cpp-crypto/ciphers)
target_link_libraries(reverse-cipher Ciphers gflags::gflags)
set_target_properties(reverse-cipher
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  )
