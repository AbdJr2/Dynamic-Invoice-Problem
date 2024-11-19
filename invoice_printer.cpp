#include "invoice_printer.h"

void InvoicePrinter::set_strategy(std::shared_ptr<PrintStrategy> new_strategy) {
    strategy = new_strategy;
}

void InvoicePrinter::print(const std::string& message) {
    strategy->print(message);
}