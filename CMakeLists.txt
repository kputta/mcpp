# build executable defined in apps

# here is the fast way
# /usr/local/Cellar/gcc/10.2.0/bin/g++ -std=c++20 -c cpp-crypto/ciphers-code/reverse.cpp -I cpp-crypto/ciphers
# /usr/local/Cellar/gcc/10.2.0/bin/g++ -std=c++20 apps/reverse-cipher.cpp -I cpp-crypto/ciphers reverse.o

# version & standards
cmake_minimum_required(VERSION 3.18.4)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set compilers
set(CMAKE_C_COMPILIER "/usr/local/Cellar/gcc/10.2.0/bin/gcc-10")
set(CMAKE_CXX_COMPILIER "/usr/local/Cellar/gcc/10.2.0/bin/g++-10")
set(CMAKE_CXX_FLAGS "-std=c++20")

# set the project name
project(cpp-crypto VERSION 1.0)

# target cipher-reverse
add_subdirectory(cpp-crypto)
add_executable(cipher-reverse
  "apps/reverse-cipher.cpp")
target_include_directories(cipher-reverse
  PUBLIC
  cpp-crypto/ciphers)
find_library(CiphersLib
  Ciphers
  HINTS
  cpp-crypto/build/lib REQUIRED)
target_link_libraries(cipher-reverse
  ${CiphersLib})
set_target_properties(cipher-reverse
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  )
