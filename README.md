# mcpp: modern c++ projects


## Setup
- Style Guide:
  - Clang-format Supports 5 or more style guides, LLVM(default), Google, Chromium, Mozilla, WebKit etc.
  -  In this project [Google style guide](`https://google.github.io/styleguide/cppguide.html) is enabled (in emacs, using [emacs lisp file](https://raw.githubusercontent.com/google/styleguide/gh-pages/google-c-style.el)) while writing the code, although they have some very opiniated things about column width, templates and exceptions.

  - We can create a .clang-format file in top-directory and install a pre-commit hook to run clang-format command before git commit on all changed cpp and hpp files.
	  
	  `clang-format -style=Google -dump-config > .clang-format`

- Compiling and Linking:
	- CMake: CMake is cross-platform project build tool kit, essentially it creates a MakeFile.
	- Makefile is simply a DAG describing necessary pre-requistics and recipes to build set of targets.
	- CMakeLists.txt are written to use 10.2.0 g++/gcc versions with CXX20 standard, (using -std=c++20).
 - Structure:
	 - Each project has set of sub-directories under main project directory, example: 
	    cpp-project is the main project directory and under that ciphers and ciphers-code are project sub-directories.
	- Aim is to make static libraries out of these projects and combine with any external libraries (commonly used across all projects) to create an executable target, defined in apps folder.
	- Additionally a test directory is also a parent folder whose sub-directories contains project based test sub-folders.
 
## Projects
- crypto-cpp: c++ implementation of problems defined in [[https://github.com/arahimian/py-crypto]]
	- Iteration 1:
		- Built intial framework under cpp-crypto/ciphers
		- Added reverse algorithm as first cipher.
	 
## Build Apps:
- crypto-cpp:
	-  reverse-cipher:
		-	It uses external gflag library which is included in this repo as an external submodule (external folder).
		-	It uses one internal static library `libCiphers.a`
			-	`cmake -H. -Bbuild`
				-	Uses defined CMakeLists.txt and create build directory with relevant CMakeFiles, lib, lib and a MakeFile
			-	 `cd build; make reverse-cipher`
				-	 Compiles, links and creates following targets in build directory:
					-	 external/gflags/libgflags_nothreads.a
					-	 lib/libCiphers.a
					-	 bin/reverse-cipher

## Usage:
- crypto-cpp:
	- reverse-cipher:
		- `./bin/reverse-cipher  --help`
			- `-d` (convert ciphertext to plaintext) type: bool default: false
			- `-e` (convert plaintext to ciphertext) type: bool default: false
			- `-t` (plain/cipher-text to encrypt/decrypt) type: string default: ""
		- `./bin/reverse-cipher -e -t Fsdgsdg`

