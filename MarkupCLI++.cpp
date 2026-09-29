#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "src/string_utils.h"
#include "src/table_flag.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Input file not found" << std::endl;
        return 1;
    }

    if (argc < 3) {
        std::cout << "Error: Provide the file name and the header content." << std::endl;
        return 1;
    }

    if (argc < 4) {
        std::cout << "Error: Provide the file name and the header content." << std::endl;
        return 1;
    }

    for (int i = 2; i < argc; i++) {
        std::string flag = toLower(argv[i]);
        if (flag == "--overwrite-file") {
            std::ofstream file(argv[1]);
        } 
    }


    std::ofstream file(argv[1], std::ios::app);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file for writing (check permissions)." << std::endl;
        return 1;
    }

    for (int i = 2; i < argc; i++) {
        std::string flag = toLower(argv[i]);

        if (flag == "--header" ) {
            if (i + 1 >= argc)
            {
                std::cout << "Error: --header requires a value." << std::endl;
                return 1;
            }
            file << "# " << argv[i + 1] << std::endl;
        } else if (flag == "--text") {
            if (i + 1 >= argc)
            {
                std::cout << "Error: --text requires a value." << std::endl;
                return 1;
            }
            file << argv[i + 1] << "\n" << std::endl;
        } else if (flag == "--note") {
            if (i + 1 >= argc)
            {
                std::cout << "Error: --note requires a value." << std::endl;
                return 1;
            }
            file << "> [!NOTE]\n> " << argv[i + 1] <<  "\n" << std::endl;
        } else if (flag == "--important") {
            if (i + 1 >= argc)
            {
                std::cout << "Error: --important requires a value." << std::endl;
                return 1;
            }
            file << "> [!IMPORTANT]\n> " << argv[i + 1] << "\n" << std::endl;
        } else if (flag == "--tip") {
            if (i + 1 >= argc)
            {
                std::cout << "Error: --tip requires a value." << std::endl;
                return 1;
            }
            file << "> [!TIP]\n> " << argv[i + 1] << "\n" << std::endl;
        } else if (flag == "--image") {
            if (i + 2 >= argc) {
                std::cout << "Error: --image required both a description and a link/path." << std::endl;
                return 1;
        }
        file << "![" << argv[i + 1] << "]" << "(" << argv[i + 2] << ")" << std::endl;
        }
        else if (flag == "--link")
        {
            if (i + 2 >= argc)
            {
                std::cout << "Error: --link required both a description and a link/path." << std::endl;
                return 1;
            }
            file << "[" << argv[i + 1] << "]" << "(" << argv[i + 2] << ")" << std::endl;
        }
        else if (flag == "--warning") {
            if (i + 1 >= argc)
            {
                std::cout << "Error: --warning requires a value." << std::endl;
                return 1;
            }
            file << "> [!WARNING]\n >" << argv[i + 1] << "\n"
                 << std::endl;
        }
        else if (flag == "--caution") {
            if (i + 1 >= argc)
            {
                std::cout << "Error: --caution requires a value." << std::endl;
                return 1;
            }
            file << "> [!CAUTION]\n> " << argv[i + 1] << "\n"
                 << std::endl;
        } else if (flag == "--table") {
            if (i + 1 >= argc) {
                std::cout << "Error: --table requires a confirmation value. Please write --table yes" << std::endl;
                return 1;
            }
            std::string confirmation = toLower(argv[i + 1]);
            if (confirmation != "yes") {
                std::cout << "Error: --table requires a confirmation value. Please write --table yes" << std::endl;
                return 1;
            }

            buildTable(file);
        }
    }

    file.close();

    std::cout << "Saved to " << argv[1] << std::endl;

    std::cout << "input file: " << argv[1] << std::endl;
    return 0;
}   