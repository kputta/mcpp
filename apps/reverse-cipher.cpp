#include <iostream>
#include "reverse.hpp"


int main(int argv, char** argc) {
  auto cipher = crypto::Reverse("kputta");
  std::cout << cipher.encrypt("Hello World") << " "
            << cipher.decrypt("Kaushik Putta") << "\n";
}
