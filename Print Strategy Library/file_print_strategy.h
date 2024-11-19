#include "print_strategy.h"
#include <fstream>

class FilePrintStrategy : public PrintStrategy {
public:
    void print(const std::string& message);
};

extern "C" PrintStrategy* createStrategy() {
    return new FilePrintStrategy();
}