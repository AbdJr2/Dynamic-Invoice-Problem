#include <iostream>
#include <fstream>
#include "invoice_printer.h"
#include "Print Strategy Library/dynamic_loader.h"

int main() {
    InvoicePrinter printer;

    // Read strategy from config file
    std::ifstream configFile("print_config.txt");
    std::string strategyLibrary;
    std::getline(configFile, strategyLibrary);
    try {
        auto strategy = DynamicLoader::load_strategy(strategyLibrary);
        printer.set_strategy(strategy);
        printer.print("Hello, World!");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}