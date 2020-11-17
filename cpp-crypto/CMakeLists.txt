# build libraries including ciphers / math / util etc ...

# ciphers
FILE(GLOB CIPHERS_SOURCE ciphers-code/*.cpp)
add_library(Ciphers STATIC ${CIPHERS_SOURCE})
target_include_directories(Ciphers PUBLIC .)
set_target_properties(Ciphers
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# utils
FILE(GLOB UTILS_SOURCE utils-code/*.cpp)
add_library(Utils STATIC ${UTILS_SOURCE})
target_include_directories(Utils PUBLIC .)
set_target_properties(Utils
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
