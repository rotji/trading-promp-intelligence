#include <cassert>

#include "core/Core.h"

int main() {
    using gcfios::core::system::context::Context;
    using gcfios::core::system::context::InitializationState;
    using gcfios::core::system::identity::Identity;
    using gcfios::core::system::lifecycle::Lifecycle;
    using gcfios::core::system::lifecycle::State;
    using gcfios::core::services::logging::LogEntry;
    using gcfios::core::services::logging::Severity;
    using gcfios::core::system::versioning::Version;

    constexpr Version version{0, 1, 0};
    static_assert(version == Version{0, 1, 0});

    constexpr Identity identity{42, 7, "GCFIOS"};
    static_assert(identity.platform_id == 42);
    static_assert(identity.product_family_id == 7);
    static_assert(identity.platform_name == "GCFIOS");

    Context context{identity, version, InitializationState::Initialized};
    assert(context.IsInitialized());
    assert(context.identity.platform_id == 42);
    assert(context.version == version);

    Lifecycle lifecycle{};
    assert(lifecycle.state == State::Created);
    assert(lifecycle.TransitionTo(State::Initializing));
    assert(lifecycle.TransitionTo(State::Initialized));
    assert(lifecycle.TransitionTo(State::Running));
    assert(lifecycle.TransitionTo(State::Stopping));
    assert(lifecycle.TransitionTo(State::Stopped));
    assert(!lifecycle.TransitionTo(State::Running));

    constexpr LogEntry entry{Severity::Info, "root-verification", "ok"};
    assert(entry.severity == Severity::Info);
    assert(entry.source != nullptr);
    assert(entry.message != nullptr);

    return 0;
}
