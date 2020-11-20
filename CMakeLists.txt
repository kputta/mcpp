# version & standards
cmake_minimum_required(VERSION 3.18.4)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the project name
project(mcpp VERSION 1.0)

# enable verbose
set(CMAKE_VERBOSE_MAKEFILE OFF)

# set compilers
set(CMAKE_C_COMPILIER "gcc-10")
set(CMAKE_CXX_COMPILIER "g++-10")
set(CMAKE_CXX_FLAGS "-std=c++20")

# compilers flags
# add_compile_options(-Wall -Wextra -Wpedantic -Wno)
add_compile_options(-Wall -Wextra -Wpedantic)

# build type [Debug, Release, RelWithDebInfo, MinSizeRel]
message("Generated with config types: ${CMAKE_CONFIGURATION_TYPES}")

# boost library
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(BOOST_ROOT "/usr/local/Cellar/boost/1.74.0")
find_package(Boost 1.74.0 COMPONENTS thread locale system filesystem regex REQUIRED)
if (Boost_FOUND)
  message("boost lib: ${Boost_LIBRARIES}")
  message("boost inc: ${Boost_INCLUDE_DIRS}")
endif()

# external libraries(submodules): gflags 
add_subdirectory(external/gflags)

# repo libraries(sub-dirs): cpp-crypto
add_subdirectory(cpp-crypto)


# targets:
add_executable(test-ciphers "apps/test-ciphers.cpp")
target_include_directories(test-ciphers PUBLIC cpp-crypto ${Boost_INCLUDE_DIRS})
target_link_libraries(test-ciphers Ciphers gflags::gflags ${Boost_LIBRARIES})
set_target_properties(test-ciphers
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  )

add_executable(test-boost-locale "apps/test-boost-locale.cpp")
target_include_directories(test-boost-locale PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(test-boost-locale gflags::gflags ${Boost_LIBRARIES})
set_target_properties(test-boost-locale
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  )

add_executable(test-locale "apps/test-locale.cpp")
target_include_directories(test-locale PUBLIC)
target_link_libraries(test-locale gflags::gflags)
set_target_properties(test-locale
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  )

add_executable(test-utils "apps/test-utils.cpp")
target_include_directories(test-utils PUBLIC cpp-crypto)
target_link_libraries(test-utils Utils gflags::gflags)
set_target_properties(test-utils
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  )

add_executable(test-hackers "apps/test-hackers.cpp")
target_include_directories(test-hackers PUBLIC cpp-crypto)
target_link_libraries(test-hackers Hackers Utils gflags::gflags)
set_target_properties(test-hackers
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  )

ADD_CUSTOM_TARGET(debug
  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
  COMMENT "Creating the executable in the debug mode.")

ADD_CUSTOM_TARGET(release
  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
  COMMENT "Creating the executable in the release mode.")
