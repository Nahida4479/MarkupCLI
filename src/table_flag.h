#ifndef buildTable_h
#define buildTable_h

#include <vector>
#include <string>
#include <fstream>

std::vector<std::string> splitByComma(std::string text);
void buildTable(std::ofstream& file);

#endif