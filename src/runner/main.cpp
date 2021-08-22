#include <iostream>

#include "version.h"
#include "runner.h"

int main(int argv, char* args[]) {
    std::cout << "Starting runner...\n" << PROJECT_NAME << '\n' << PROJECT_NAME << '\n';

    std::vector<std::string> arguments;
    for (auto i {0}; i < argv; ++i) {
        arguments.push_back(args[i]);
    }

    texturegenerator::runner runner(arguments);

    std::cout << "Runner complete.\n";

    return 0;
}
