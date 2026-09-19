#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Input file not found" << std::endl;
        return 1;
    }

    std::ofstream file(argv[1]);
    file << "# MarkupCLI++" << std::endl;
    file.close();

    std::cout << "MarkupCLI++ working!" << std::endl;
    std::cout << "input file: " << argv[1] << std::endl;
    return 0;
}