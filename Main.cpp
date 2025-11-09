#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Missing argument\n";
    return 1;
  }

  std::ifstream in(argv[1]);

  if (!in) {
    std::cerr << "Could not open file\n";
    return 1;
  }

  char ch = in.get();

  while (ch != EOF) {
    std::cout << static_cast<char>(ch);
    ch = in.get();
  }

  std::cout << '\n';
  in.close();

  return 0;
}
