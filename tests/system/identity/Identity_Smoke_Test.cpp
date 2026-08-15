#include <cassert>
#include <string_view>

#include "core/system/identity/Identity.h"

int main() {
    using gcfios::core::system::identity::Identity;

    constexpr Identity identity{
        1,
        2,
        std::string_view{"GCFIOS"}
    };

    static_assert(identity.platform_id == 1);
    static_assert(identity.product_family_id == 2);

    assert(identity.platform_id == 1);
    assert(identity.product_family_id == 2);
    assert(identity.platform_name == "GCFIOS");

    return 0;
}
