#include "file_print_strategy.h"

void FilePrintStrategy::print(const std::string& message) {
    std::ofstream file("output.txt", std::ios::app);
    file << message << std::endl;
}