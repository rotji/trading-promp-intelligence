#include <cassert>

#include "core/system/context/Context.h"

int main() {
    using gcfios::core::system::context::Context;
    using gcfios::core::system::context::InitializationState;

    constexpr Context uninitialized{};
    static_assert(!uninitialized.IsInitialized());

    Context initialized{};
    initialized.initialization_state = InitializationState::Initialized;

    assert(initialized.IsInitialized());
    assert(!uninitialized.IsInitialized());

    return 0;
}
