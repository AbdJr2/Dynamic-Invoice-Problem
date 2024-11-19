# What Is This Folder

This folder contains a main abstract class called print_strategy.h where we print a string
However, we want to make it such that the printing medium differs each time. That is why there is a dynamic loader that could load this class for other classes based on the file it reads from. 

 # Compilation
 
 To compile these files and allow them to be linked as different printing startegies, copy the following code:

g++ -shared -fPIC console_print_strategy.cpp -o libconsolestrategy.so
g++ -shared -fPIC file_print_strategy.cpp -o libfilestrategy.so


Now in the text file that will be passed to the dynamic loader. Based on the strategy we want, just put the following in it:

./libconsolestrategy.so

This will enablle console strategy


### Note: file print strategy prints by default to "output.txt"

#### Final File Compilation:

g++ -o main main.cpp Printer.cpp DynamicLoader.cpp -ldl
