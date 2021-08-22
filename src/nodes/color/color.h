#pragma once

#include <cstdint>

#include "nodes/shared/color.h"

namespace texturegenerator::nodes::color {
    void run(const shared::color& color, int32_t origin, uint32_t frame_width, uint32_t frame_height);
}
