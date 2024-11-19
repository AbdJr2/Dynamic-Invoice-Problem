#include "print_strategy.h"
#include <iostream>

class ConsolePrintStrategy : public PrintStrategy {
public:
    void print(const std::string& message);
};

/*
**`extern "C"` Linkage Specification**:
   ```cpp
   extern "C"
   ```
This specifies that the 
createStrategy function should use C 
linkage rather than C++ linkage. 
The primary reason for using `extern "C"` 
is to prevent name mangling, which is a 
process where the C++ compiler generates 
unique names for functions to support 
features like function overloading. 
By using C linkage, the function name 
remains unchanged, making it easier to 
link with code written in other languages 
(such as C) or to dynamically load the 
function at runtime.
*/
extern "C" PrintStrategy* createStrategy() {
    return new ConsolePrintStrategy();
}
