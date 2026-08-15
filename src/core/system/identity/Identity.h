#pragma once

#include <cstdint>
#include <string_view>

#include "core/foundation/Foundation_Types.h"

namespace gcfios::core::system::identity {

struct Identity {
    foundation::Identifier platform_id{};
    foundation::Identifier product_family_id{};
    std::string_view platform_name{};
};

} // namespace gcfios::core::system::identity
