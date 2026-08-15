#include <cassert>

#include "core/system/versioning/Version.h"

int main() {
    using gcfios::core::system::versioning::Version;

    constexpr Version current{1, 2, 3};
    constexpr Version same{1, 2, 3};
    constexpr Version different{1, 2, 4};

    static_assert(current == same);
    static_assert(!(current == different));

    assert(current.major == 1);
    assert(current.minor == 2);
    assert(current.patch == 3);

    return 0;
}
