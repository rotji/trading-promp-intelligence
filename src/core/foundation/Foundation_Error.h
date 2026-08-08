#pragma once

#include <string>

namespace gcfios::foundation {

struct Error {
    int code{};
    std::string message{};

    constexpr bool IsValid() const noexcept {
        return code != 0;
    }
};

} // namespace gcfios::foundation
