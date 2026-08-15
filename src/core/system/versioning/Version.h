#pragma once

#include <cstdint>

namespace gcfios::core::system::versioning {

struct Version {
    std::uint32_t major{};
    std::uint32_t minor{};
    std::uint32_t patch{};
};

constexpr bool operator==(const Version&, const Version&) noexcept = default;

} // namespace gcfios::core::system::versioning
