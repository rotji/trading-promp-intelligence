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
constexpr ExecutionAdmission kAdmission =
    ExecutionAdmission::Admit(kAuthorization, kExecution);
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
    static_assert(version.major == 0);
    static_assert(version.minor == 1);
    static_assert(version.patch == 0);

    constexpr Identity identity{42, 7, "GCFIOS"};
    static_assert(identity.platform_id == 42);
    static_assert(identity.product_family_id == 7);
    static_assert(identity.platform_name.size() == 6);
    static_assert(identity.platform_name[0] == 'G');

    constexpr Lifecycle lifecycle{};
    static_assert(lifecycle.state == State::Created);
    static_assert(lifecycle.CanTransitionTo(State::Initializing));
    static_assert(!lifecycle.CanTransitionTo(State::Running));

    constexpr Context context{
        identity,
        version,
        InitializationState::Uninitialized};
    static_assert(!context.IsInitialized());
    static_assert(context.identity.platform_id == 42);
    static_assert(context.version.minor == 1);

    constexpr EventHeader event_header{1001, static_cast<EventType>(1), 42};
    static_assert(event_header.Id() == 1001);
    static_assert(event_header.Type() == static_cast<EventType>(1));
    static_assert(event_header.Source() == 42);

    constexpr LogEntry log_entry{Severity::Info, "root-verification", "root-verification"};
    static_assert(log_entry.severity == Severity::Info);

    constexpr ExecutionIntent intent = ExecutionIntent::Execute;
    static_assert(intent == ExecutionIntent::Execute);

    constexpr InvocationReason invocation_reason = InvocationReason::Invocable;
    static_assert(invocation_reason == InvocationReason::Invocable);

    constexpr ExecutionInvocation invocation =
        ExecutionInvocation::Prepare(kRouting, kExecution);
    static_assert(invocation.IsValid());
    static_assert(invocation.Execution() == 2001);
    static_assert(invocation.Capability() == 4001);
    static_assert(invocation.Target() == 5001);
    static_assert(invocation.Reason() == InvocationReason::Invocable);

    assert(version.major == 0);
    assert(version.minor == 1);
    assert(version.patch == 0);
    assert(identity.platform_id == 42);
    assert(identity.product_family_id == 7);
    assert(identity.platform_name == "GCFIOS");
    assert(lifecycle.state == State::Created);
    assert(lifecycle.CanTransitionTo(State::Initializing));
    assert(!lifecycle.CanTransitionTo(State::Running));
    assert(!context.IsInitialized());
    assert(event_header.Id() == 1001);
    assert(event_header.Type() == static_cast<EventType>(1));
    assert(event_header.Source() == 42);
    assert(log_entry.severity == Severity::Info);
    assert(kSelection.IsSelected());
    assert(kAuthorization.IsAuthorized());
    assert(kAdmission.IsAdmitted());
    assert(kDispatch.IsDispatchable());
    assert(kRouting.IsRoutable());
    assert(invocation.IsValid());

    return 0;
}
