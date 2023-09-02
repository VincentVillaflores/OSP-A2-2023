#include <iostream>
#include "../pcb.h"

int main(int argc, char* argv[]) {
    // argc is the number of arguments passed, including the name of the program
    // argv is an array of pointers to null-terminated strings representing the arguments

    // Print the number of arguments
    std::cout << "Number of arguments: " << argc << std::endl;

    // Loop through each argument and print it
    for (int i = 0; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }

    return 0;
}
