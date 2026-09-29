#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>  

std::vector<std::string> splitByComma(std::string text)
{
    std::stringstream ss(text);
    std::string value;
    std::vector<std::string> values;

    while (std::getline(ss, value, ',')) {
        values.push_back(value);
    }

    return values;
}

void buildTable(std::ofstream& file) {

    std::vector <std::string> headers;
    std::string headerInput;

    do {
        std::cout << "Enter column header (or press Enter to finish): ";
        std::getline(std::cin, headerInput);

        if (!headerInput.empty()) {
            headers.push_back(headerInput);
        }
    } while (!headerInput.empty());

    std::vector<std::vector<std::string>> colums;
        for (int i = 0; i < headers.size(); i++) {
            std::cout << "Enter value for '" << headers[i] << "' (comma separated): ";
            std::getline(std::cin, headerInput);
            std::vector<std::string> values = splitByComma(headerInput);
            colums.push_back(values);
        }

        // std::cout << "\n------ Headers and values ----------\n" << std::endl;
        for (int c = 0; c < colums.size(); c++) {
            // std::cout << headers[c] << ": ";
            for (int v = 0; v < colums[c].size(); v++) {
                // std::cout << "[" << colums[c][v] << "] ";
            }
            // std::cout << std::endl;
        }

        int maxRows = 0;
        for (int c = 0; c < colums.size(); c++) {
            if (colums[c].size() > maxRows) {
                maxRows = colums[c].size();
            }
        }
            // std::cout << "\n------ Values ----------\n" << std::endl;
            // std::cout << "Max rows: " << maxRows << std::endl;


        std::vector<std::vector<std::string>> tableRows;
        for (int i = 0; i < maxRows; i++) {
            std::vector<std::string> row;

            for (int c = 0; c < colums.size(); c++) {
                if (i < colums[c].size()) {
                    row.push_back(colums[c][i]);
                } else {
                    row.push_back("");
                }
            }
            tableRows.push_back(row);
        }

        for (int c = 0; c < tableRows.size(); c++) {
                for (int v = 0; v < tableRows[c].size(); v++) {
                    // std::cout << "[" << tableRows[c][v] << "] "; 
                }
                // std::cout << std::endl;
        }

        std::vector<int> columnWidth;

        for (int c = 0; c < headers.size(); c++)
        {
            int width = headers[c].length();
            for (int r = 0; r < tableRows.size(); r++)
            {
                if (tableRows[r][c].length() > width)
                {
                    width = tableRows[r][c].length();
                }
            }
            columnWidth.push_back(width);
        }

        std::cout << "\033[1m\n--- Markdown table ---\033[0m" << std::endl;

        for (int i = 0; i < headers.size(); i++) {
            std::cout << "| \033[1m\033[31m" << std::left << std::setw(columnWidth[i]) << headers[i] << "\033[0m\033[0m ";
        }
        std::cout << "|" << std::endl;


        for (int c = 0; c < headers.size(); c++) {
            std::cout << "| " << std::string(columnWidth[c], '-') << " ";
        }
        std::cout << "|" << std::endl;

        for (int r = 0; r < tableRows.size(); r++) {
            for (int c = 0; c < tableRows[r].size(); c++) {
                std::cout << "|\033[33m " << std::left << std::setw(columnWidth[c]) << tableRows[r][c] << "\033[0m ";
            }
            std::cout << "|" << std::endl;
        }

        file << "\n";

        for (int i = 0; i < headers.size(); i++) {
            file << "| " << headers[i] << " ";
        }
        file << "|" << std::endl;

        for (int c = 0; c < headers.size(); c++) {
            file << "| --- ";
        }
        file << "|" << std::endl;

        for (int r = 0; r < tableRows.size(); r++) {
            for (int c = 0; c < tableRows[r].size(); c++) {
                file << "| " << tableRows[r][c] << " ";
            }
            file << "|" << std::endl;
        }

        return;
}
