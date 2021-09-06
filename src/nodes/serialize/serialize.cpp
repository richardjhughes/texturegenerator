#include "serialize.h"

namespace texturegenerator::nodes::serialize {
    std::optional<serialize::socket_list> serialize::run(glm::vec4,
                                                         uint32_t , uint32_t ,
                                                         const shared::graph::parameters& ,
                                                         const socket_list&) noexcept
    {
        return {};
    }
}
