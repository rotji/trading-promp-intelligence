#include <cassert>

#include "core/Core.h"

int main() {
    using gcfios::core::capabilities::CapabilitySelectionResult;
    using gcfios::core::capabilities::SelectionReason;
    using gcfios::core::events::EventHeader;
    using gcfios::core::events::EventType;
    using gcfios::core::execution::ExecutionContract;
    using gcfios::core::execution::ExecutionIntent;
    using gcfios::core::execution::ExecutionState;
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

    constexpr EventHeader event{1001, static_cast<EventType>(7), 42};
    static_assert(event.Id() == 1001);
    static_assert(event.Type() == static_cast<EventType>(7));
    static_assert(event.Source() == 42);

    constexpr ExecutionContract execution{
        2001,
        ExecutionIntent::Execute,
        ExecutionState::Created};
    static_assert(execution.Id() == 2001);
    static_assert(execution.Intent() == ExecutionIntent::Execute);
    static_assert(execution.State() == ExecutionState::Created);

    constexpr CapabilitySelectionResult selection =
        CapabilitySelectionResult::Selected(3001, 4001);
    static_assert(selection.IsValid());
    static_assert(selection.IsSelected());
    static_assert(selection.Requirement() == 3001);
    static_assert(selection.Capability() == 4001);
    static_assert(selection.Reason() == SelectionReason::Selected);

    return 0;
}
