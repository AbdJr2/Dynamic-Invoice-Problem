# Improtant Read Out

This project was meant to solve the Dynamic Invoice Problem (which turned out to be filtering results problem). It is described in one of the text files. 

However, i wanted to reach an extendable approach. So i wanted to make printing the invoice easy to transfer to any medium (console, file, probably add file formats later on) which lead to creating an SPI (Serial Peripheral Interface). 

So i kept it as it got really complex and caused many issues especially in compilation, and i went on and created a different repository for the Dynamic Invoice Problem. 

## Navigating Through the Files:

Well, i tried to perform some organizations in the file such as making all the reading file related functions in a different folder (directory). But with the library files (.so) and executables, it still looks complex to look at. 
In main we look at the text folder in order to get the correct format we want to use, and in that text file we have the library name (which means we can accept any compiled library that extends ***from print_strategy.h***. This file is basically 
an interface but we don't have interfaces in C++, we have Pure Virtual Functions instead. 

Now implemented libraries that are there as an example are: console_print_strategy, and file_print_strategy. 

The file (or class) that connects all of those together is the ***dynamic_loader*** class. This takes in the string we read from the file, looks for the library that has that name, then craates an object of that type. 
