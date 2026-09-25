#include <vector>
#include <string>
#include <iostream>

int main () {

    std::vector <std::string> headers;
    std::string headerInput;

    do {
        std::cout << "Enter column header (or press Enter to finish): ";
        std::getline(std::cin, headerInput);

        if (!headerInput.empty()) {
            headers.push_back(headerInput);
        }
    } while (!headerInput.empty()); 
    return 0;
}
