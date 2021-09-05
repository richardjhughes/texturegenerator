#pragma once

#include <string>
#include <variant>
#include <optional>
#include <unordered_map>

#include "nodes/shared/graphics/color.h"

namespace texturegenerator::shared::graph {
    // Parameters represents what is passed into a node from configurable
    // input. For instance, a parameter could be a color, a position or a
    // string value. This object is NOT thread safe.
    class parameters {
    public:
        using variant_type = std::variant<graphics::color, int>;

        // sets the data
        // any string is allowed as a key
        template <typename T>
        void set(const std::string& key, T data) noexcept {
            this->_data[key] = data;
        }

        template <typename T>
        std::optional<T> get(const std::string& key) const noexcept {
            auto iter = this->_data.find(key);
            if (iter == this->_data.end()) {
                return {};
            }

            try {
                auto value = std::get<T>(iter->second);
                return value;
            }
            catch (const std::exception& ex) {
                return {};
            }
        }
    private:
        std::unordered_map<std::string, variant_type> _data;
    };
}
