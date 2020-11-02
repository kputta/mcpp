# build libraries including ciphers / math / util etc ...

# version & standards
cmake_minimum_required(VERSION 3.18.4)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set compilers
set(CMAKE_C_COMPILIER "/usr/local/Cellar/gcc/10.2.0/bin/gcc-10")
set(CMAKE_CXX_COMPILIER "/usr/local/Cellar/gcc/10.2.0/bin/g++-10")
set(CMAKE_CXX_FLAGS "-std=c++20")

project(ciphers VERSION 1.0)

# ciphers
FILE(GLOB CIPHERS_SOURCE ciphers-code/*.cpp)
add_library(Ciphers STATIC ${CIPHERS_SOURCE})
set_target_properties(Ciphers
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
