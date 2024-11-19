#pragma once
#include <string>
#include <memory>
#ifdef _WIN32
#include <windows.h>
#include <stdexcept>
#else
#include <dlfcn.h>
#endif
#include "print_strategy.h"

class DynamicLoader {
public:
    static std::shared_ptr<PrintStrategy> load_strategy(const std::string& libraryPath);
};