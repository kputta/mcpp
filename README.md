# mcpp: modern c++ projects


## Setup
- Style Guide:
  - Clang-format Supports 5 or more style guides, LLVM(default), Google, Chromium, Mozilla, WebKit etc and in this project Google style guide is enabled while writing the code, although they have some very opiniated things about column width, templates and exceptions. 
  - Also we create a .clang-format file in top-directory and a pre-commit hook is installed to run clang-format command on all changed cpp and hpp files.
	  
	  `clang-format -style=llvm -dump-config > .clang-format`

- Compiling and Linking:
	- CMake: CMake is cross-platform project build tool kit, essentially it creates a MakeFile.
	- Makefile is a simply DAG describing necessary pre-requistics and receipts to build set of targets.
	- CMakeLists.txt are written to use 10.2.0 g++/gcc versions with CXX20 standard, (using -std=c++20).
 - Structure:
	 - Each project has set of sub-directories under main project directory, example: 
	    cpp-project is the main project directory and under that ciphers and ciphers-code are project sub-directories.
	- Aim is to make static libraries out of this projects and combine with any external libraries (mostly common across all projects) to create an executable target, define in apps folder.
	- Additionally a test directory is also parent folder which sub-directories containing proeject based tests.
 
## Projects
- crypto-cpp: c++ implementation of problems defined in [[https://github.com/arahimian/py-crypto]]
	- Iteration 1:
		- Built intial framework under cpp-crypto/ciphers
		- Added reverse algorithm as first cipher.
	 
## Build Apps:
- crypto-cpp:
	-  reverse-cipher:
		-	It uses external gflag library which is included as submodule in this project (external folder).
		-	It uses one internal static library 
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

