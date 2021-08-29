#pragma once

#include <cstdint>

namespace texturegenerator::shared::graphics {
    struct color {
        uint8_t r {0};
        uint8_t g {0};
        uint8_t b {0};
        uint8_t a {0};
    };

    static inline bool operator ==(const color& lhs, const color& rhs) {
        return lhs.r == rhs.r &&
               lhs.g == rhs.g &&
               lhs.b == rhs.b &&
               lhs.a == rhs.a;
    }

    static inline bool operator !=(const color& lhs, const color& rhs) {
        return !(lhs == rhs);
    }
}
