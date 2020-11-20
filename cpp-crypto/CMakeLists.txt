# build libraries including ciphers / math / util etc ...

# utils
FILE(GLOB UTILS_SOURCE utils-code/*.cpp)
add_library(Utils STATIC ${UTILS_SOURCE})
target_include_directories(Utils PUBLIC . ${Boost_INCLUDE_DIRS})
set_target_properties(Utils
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# ciphers
FILE(GLOB CIPHERS_SOURCE ciphers-code/*.cpp)
add_library(Ciphers STATIC ${CIPHERS_SOURCE})
target_include_directories(Ciphers PUBLIC . ${Boost_INCLUDE_DIRS})
set_target_properties(Ciphers
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# hackers
FILE(GLOB HACKERS_SOURCE hackers-code/*.cpp)
add_library(Hackers STATIC ${HACKERS_SOURCE})
target_include_directories(Hackers PUBLIC . ${Boost_INCLUDE_DIRS})
target_link_libraries(Hackers Utils Ciphers)
set_target_properties(Hackers
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
