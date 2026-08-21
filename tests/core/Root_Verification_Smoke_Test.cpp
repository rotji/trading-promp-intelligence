#include <cassert>

#include "core/Core.h"

using gcfios::core::capabilities::CapabilityAuthorization;
using gcfios::core::capabilities::CapabilitySelectionResult;
using gcfios::core::capabilities::SelectionReason;
using gcfios::core::events::EventHeader;
using gcfios::core::events::EventType;
using gcfios::core::execution::ExecutionAdmission;
using gcfios::core::execution::ExecutionContract;
using gcfios::core::execution::ExecutionDispatch;
using gcfios::core::execution::ExecutionIntent;
using gcfios::core::execution::ExecutionInvocation;
using gcfios::core::execution::ExecutionRouting;
using gcfios::core::execution::ExecutionState;
using gcfios::core::execution::InvocationReason;
using gcfios::core::execution::RoutingReason;
using gcfios::core::services::logging::LogEntry;
using gcfios::core::services::logging::Severity;
using gcfios::core::system::context::Context;
using gcfios::core::system::context::InitializationState;
using gcfios::core::system::identity::Identity;
using gcfios::core::system::lifecycle::Lifecycle;
using gcfios::core::system::lifecycle::State;
using gcfios::core::system::versioning::Version;

namespace {

constexpr CapabilitySelectionResult kSelection =
    CapabilitySelectionResult::Selected(3001, 4001);
constexpr CapabilityAuthorization kAuthorization =
    CapabilityAuthorization::Authorized(kSelection);
constexpr ExecutionContract kExecution{
    2001,
    ExecutionIntent::Execute,
    ExecutionState::Created};
constexpr ExecutionAdmission kAdmission = ExecutionAdmission::Admitted(2001);
constexpr ExecutionDispatch kDispatch =
    ExecutionDispatch::Prepare(kAuthorization, kAdmission, kExecution);
constexpr ExecutionRouting kRouting =
    ExecutionRouting::Prepare(kDispatch, kExecution, 5001);

static_assert(kSelection.IsValid());
static_assert(kSelection.IsSelected());
static_assert(kSelection.Requirement() == 3001);
static_assert(kSelection.Capability() == 4001);
static_assert(kSelection.Reason() == SelectionReason::Selected);

static_assert(kAuthorization.IsValid());
static_assert(kAuthorization.IsAuthorized());
static_assert(kAuthorization.Capability() == 4001);

static_assert(kAdmission.IsValid());
static_assert(kAdmission.IsAdmitted());
static_assert(kAdmission.Execution() == 2001);

static_assert(kDispatch.IsValid());
static_assert(kDispatch.IsDispatchable());
static_assert(kDispatch.Execution() == 2001);
static_assert(kDispatch.Capability() == 4001);

static_assert(kRouting.IsValid());
static_assert(kRouting.IsRoutable());
static_assert(kRouting.Execution() == 2001);
static_assert(kRouting.Capability() == 4001);
static_assert(kRouting.Target() == 5001);
static_assert(kRouting.Reason() == RoutingReason::Routable);

} // namespace

int main() {
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

    assert(kSelection.IsValid());
    assert(kSelection.IsSelected());
    assert(kSelection.Requirement() == 3001);
    assert(kSelection.Capability() == 4001);
    assert(kSelection.Reason() == SelectionReason::Selected);

    assert(kAuthorization.IsValid());
    assert(kAuthorization.IsAuthorized());
    assert(kAuthorization.Capability() == 4001);

    assert(kAdmission.IsValid());
    assert(kAdmission.IsAdmitted());
    assert(kAdmission.Execution() == 2001);

    assert(kDispatch.IsValid());
    assert(kDispatch.IsDispatchable());
    assert(kDispatch.Execution() == 2001);
    assert(kDispatch.Capability() == 4001);

    assert(kRouting.IsValid());
    assert(kRouting.IsRoutable());
    assert(kRouting.Execution() == 2001);
    assert(kRouting.Capability() == 4001);
    assert(kRouting.Target() == 5001);
    assert(kRouting.Reason() == RoutingReason::Routable);

    const auto invocation =
        ExecutionInvocation::Prepare(kRouting, kExecution);
    assert(invocation.IsValid());
    assert(invocation.IsInvocable());
    assert(invocation.Execution() == 2001);
    assert(invocation.Capability() == 4001);
    assert(invocation.Target() == 5001);
    assert(invocation.Reason() == InvocationReason::Invocable);

    static_assert(sizeof(gcfios::core::Coordination::EventContract) > 0);
    static_assert(sizeof(gcfios::core::Coordination::ExecutionDispatchContract) > 0);

    return 0;
}
