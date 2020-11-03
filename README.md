# cpp-crypto
c++ implementation of problems defined in https://github.com/arahimian/py-crypto 

## Setup
- Style Guide:
  - Clang-format Supports 5 or more style guides, LLVM(default), Google, Chromium, Mozilla, WebKit etc and in this project Google style guide is enabled while writing the code, although they have some very opiniated things about column width, templates and exceptions. 
  - Also we create a .clang-format file 
	  - clang-format -style=llvm -dump-config > .clang-format)) 
  - Additionally as code is written, it is suggested to enable google-c-style in emacs, it is strongly opiniated on templates and exception usages, this project uses google style guide (https://raw.githubusercontent.com/google/styleguide/gh-pages/google-c-style.el)

- Compiling and Linking:
  Make tool uses Makefile to build executables
  Makefile is a simply DAG describing necessary and all compilations & linkings
  
  g++ main.cpp
  g++ -c main.cpp; g++ main.o
  g++ main.o -lm (libm)
	Clang offers more advantages for the construction of large projects while GCC is always advantageous in performance optimization.
	- GCC: 
	- Clang(LLVM): Clang is a C, C++, Objective-C, Objective-C++ compiler that is compiled in C++ based on LLVM and released under the Apache 2.0 license.
   
- Libraries: 

- Makefile:
  Rule consists for 3 things, (target, pre-reqs, receipe)
  
## Projects
- crypto-cpp: 
	- objectives:
		- provide the medium to exchange messages between two parties.
		- define api to access 
		- include multiple algorithms to perform encrypt & decrypt

	

## Usage

## 
