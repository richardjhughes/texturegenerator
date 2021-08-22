#include <iostream>

#include "version.h"
#include "nodes/create/create.h"

int main(int, char*[]) {
    std::cout << "Runner\n" << PROJECT_NAME << " " << PROJECT_VERSION;

    test();

    return 0;
}
