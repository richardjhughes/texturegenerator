#pragma once

#include <cstdint>

namespace texturegenerator::shared::graphics {
    struct color {
        uint8_t r {0};
        uint8_t g {0};
        uint8_t b {0};
        uint8_t a {0};
    };

    static constexpr inline bool operator ==(const color& lhs, const color& rhs) {
        return lhs.r == rhs.r &&
               lhs.g == rhs.g &&
               lhs.b == rhs.b &&
               lhs.a == rhs.a;
    }

    static constexpr inline bool operator !=(const color& lhs, const color& rhs) {
        return !(lhs == rhs);
    }

    namespace colors {
        static constexpr color transparent { 0, 0, 0, 0, };
        static constexpr color black { 0, 0, 0, 255, };
        static constexpr color white { 255, 255, 255, 255, };
        static constexpr color red { 255, 0, 0, 255, };
        static constexpr color green { 0, 255, 0, 255, };
        static constexpr color blue { 0, 0, 255, 255, };
    }
}
