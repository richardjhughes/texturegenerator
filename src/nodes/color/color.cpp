#include <iostream>

#include "color.h"

namespace texturegenerator::nodes::color {
    color::socket_list color::run(glm::vec4 , uint32_t , uint32_t , const socket_list& )
    {
        return {};
    }
}
