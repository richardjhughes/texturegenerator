#include <iostream>

#include "version.h"
#include "runner.h"

int main(int argv, char* args[]) {
    std::cout << "Starting runner...\n" << PROJECT_NAME << '\n' << PROJECT_NAME << '\n';

    texturegenerator::runner runner(argv, args);

    std::cout << "Runner complete.\n";

    return 0;
}
