#pragma once

#include <cassert>

namespace gcfios::core::infrastructure::assertions {

inline void Assert(bool condition) noexcept {
    assert(condition);
}

} // namespace gcfios::core::infrastructure::assertions
