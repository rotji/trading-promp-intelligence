#include <cassert>

#include "core/Core.h"

int main() {
    using gcfios::core::context::Context;
    using gcfios::core::infrastructure::assertions::Assert;
    using gcfios::core::lifecycle::State;
    using gcfios::core::services::logging::LogEntry;
    using gcfios::core::services::logging::Severity;

    Context context{};
    assert(!context.IsInitialized());

    context.initialization_state =
        gcfios::core::context::InitializationState::Initialized;
    assert(context.IsInitialized());

    gcfios::core::lifecycle::Lifecycle lifecycle{};
    assert(lifecycle.state == State::Created);
    assert(lifecycle.TransitionTo(State::Initializing));
    assert(lifecycle.TransitionTo(State::Initialized));

    LogEntry entry{Severity::Info, "core", "integration smoke test"};
    assert(entry.severity == Severity::Info);

    Assert(true);

    return 0;
}
