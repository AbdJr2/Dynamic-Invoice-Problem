#include "dynamic_loader.h"

std::shared_ptr<PrintStrategy> DynamicLoader::load_strategy(const std::string& libraryPath) {
        #ifdef _WIN32
                std::wstring wideLibraryPath(libraryPath.begin(), libraryPath.end());
                HMODULE handle = LoadLibrary(wideLibraryPath.c_str());
                if (!handle) {
                    throw std::runtime_error("Failed to load library");
                }
        
                using CreateStrategy = PrintStrategy* (*)();
                CreateStrategy createStrategy = (CreateStrategy)GetProcAddress(handle, "createStrategy");
        
                if (!createStrategy) {
                    FreeLibrary(handle);
                    throw std::runtime_error("Failed to get symbol");
                }
        
                PrintStrategy* strategy = createStrategy();
                return std::shared_ptr<PrintStrategy>(strategy, [handle](PrintStrategy* p) {
                    delete p;
                    FreeLibrary(handle);
                });
        #else
                void* handle = dlopen(libraryPath.c_str(), RTLD_LAZY);
                if (!handle) {
                    throw std::runtime_error(dlerror());
                }
        
                using CreateStrategy = PrintStrategy* (*)();
                CreateStrategy createStrategy = (CreateStrategy)dlsym(handle, "createStrategy");
        
                if (!createStrategy) {
                    dlclose(handle);
                    throw std::runtime_error(dlerror());
                }
        
                PrintStrategy* strategy = createStrategy();
                return std::shared_ptr<PrintStrategy>(strategy, [handle](PrintStrategy* p) {
                    delete p;
                    dlclose(handle);
                });
        #endif
    }