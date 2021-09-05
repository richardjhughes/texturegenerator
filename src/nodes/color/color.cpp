#include "color.h"

namespace texturegenerator::nodes::color {
    std::optional<color::socket_list> color::run(glm::vec4, uint32_t , uint32_t , const socket_list&) noexcept
    {
        return {};
    }
}
