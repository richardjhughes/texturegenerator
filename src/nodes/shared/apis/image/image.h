#pragma once

#include <vector>
#include <cstdint>
#include <optional>

#include "nodes/shared/graphics/color.h"

namespace texturegenerator::shared::apis::image {
    std::optional<std::vector<std::byte>> serialize_image(std::vector<graphics::color>& pixels,
                                                          uint32_t width, uint32_t height) noexcept;
}
