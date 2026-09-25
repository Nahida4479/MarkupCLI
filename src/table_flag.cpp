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

    std::vector<std::vector<std::string>> rows;
    std::string addAnother;

    do {
        std::vector<std::string> row;

        for (int i = 0; i < headers.size(); i++) {
            std::cout << "Enter value for '" << headers[i] << "': ";
            std::getline(std::cin, headerInput);
            row.push_back(headerInput);
        }

        rows.push_back(row);

        std::cout << "\n--- Curent table ---" << std::endl;
        for (int r = 0; r < rows.size(); r++) {
            for (int c = 0; c < rows[r].size(); c++) {
                std::cout << headers[c] << ": " << rows[r][c] << "  ";
            }
            std::cout << "\n--------------------" << std::endl;
        }

        std::cout << "Add another row? (y/n): ";
        std::getline(std::cin, addAnother);
    } while (addAnother == "y");

    return 0;
}
