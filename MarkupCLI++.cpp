#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

std::string toLower(std::string text) {
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}

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

    for (int i = 2; i < argc - 1; i++) {
        std::string flag = toLower(argv[i]);

        if (flag == "--header" ) {
            file << "# " << argv[i + 1] << std::endl;
        } else if (flag == "--text") {
            file << argv[i + 1] << std::endl;
        }
    }

    file.close();

    std::cout << "Saved to " << argv[1] << std::endl;

    std::cout << "input file: " << argv[1] << std::endl;
    return 0;
}   