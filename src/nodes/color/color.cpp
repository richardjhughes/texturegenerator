#include <iostream>

#include "color.h"

namespace texturegenerator::nodes::color {
    void run(const shared::color& , int32_t , uint32_t , uint32_t ) {
        std::cout << "Color\n";
    }
}
