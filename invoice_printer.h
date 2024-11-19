#ifndef INVOICE_PRINTER_H
#define INVOICE_PRINTER_H

#include <iostream>
#include <memory>
#include <string>
#include "Print Strategy Library/print_strategy.h"

class InvoicePrinter {

public:
    void set_strategy(std::shared_ptr<PrintStrategy> new_strategy);

    void print(const std::string& message);
private:
    std::shared_ptr<PrintStrategy> strategy;
};


#endif

