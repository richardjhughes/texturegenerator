#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace texturegenerator {
    class runner {
    public:
        runner(std::vector<std::string> args) noexcept
            : _args(std::move(args))
        {}

        [[nodiscard]]
        const std::vector<std::string>& args() noexcept {
            return this->_args;
        }

    private:
        std::vector<std::string> _args;
    };
}
