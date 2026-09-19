#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Input file not found" << std::endl;
        return 1;
    }

    if (argc < 3) {
        std::cout << "Error: Provide the file name and the header content." << std::endl;
        return 1;
    }

    std::ofstream file(argv[1]);

    if (std::string(argv[2]) == "--header") {
        file << "# " << argv[3] << std::endl;
    } else if (std::string(argv[2]) == "--text") {
        file << argv[3] << std::endl;
    }

    file << "# " << argv[2] << std::endl;
    file.close();

    std::cout << "Saved to " << argv[1] << std::endl;

    std::cout << "input file: " << argv[1] << std::endl;
    return 0;
}   