#include <cassert>

#include "core/capabilities/CapabilityRequirement.h"

int main() {
    using gcfios::core::capabilities::CapabilityRequirement;

    constexpr CapabilityRequirement empty{};
    static_assert(!empty.IsValid());

    constexpr CapabilityRequirement requirement{
        1001,
        42,
        {1, 2, 3}
    };

    static_assert(requirement.IsValid());
    static_assert(requirement.Id() == 1001);
    static_assert(requirement.Kind() == 42);
    static_assert(requirement.HasMinimumVersion());
    static_assert(requirement.MinimumVersion().major == 1);
    static_assert(requirement.MinimumVersion().minor == 2);
    static_assert(requirement.MinimumVersion().patch == 3);

    constexpr CapabilityRequirement same{
        1001,
        42,
        {1, 2, 3}
    };
    static_assert(requirement == same);

    constexpr CapabilityRequirement without_version{1002, 42};
    static_assert(without_version.IsValid());
    static_assert(!without_version.HasMinimumVersion());

    assert(requirement.IsValid());
    assert(without_version.IsValid());

    return 0;
}
