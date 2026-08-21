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
constexpr ExecutionAdmission kAdmission = ExecutionAdmission::Admit(2001);
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

    constexpr Lifecycle lifecycle = Lifecycle::Create();
    static_assert(lifecycle.IsValid());
    static_assert(lifecycle.CurrentState() == State::Constructed);

    constexpr Context context = Context::Create();
    static_assert(context.IsValid());
    static_assert(context.State() == InitializationState::Created);

    constexpr EventHeader event_header{1001, EventType::System};
    static_assert(event_header.IsValid());
    static_assert(event_header.id == 1001);
    static_assert(event_header.type == EventType::System);

    constexpr LogEntry log_entry{Severity::Info, 1001, "root-verification"};
    static_assert(log_entry.IsValid());
    static_assert(log_entry.severity == Severity::Info);
    static_assert(log_entry.event_id == 1001);
    static_assert(log_entry.message == "root-verification");

    constexpr ExecutionIntent intent = ExecutionIntent::Execute;
    static_assert(intent == ExecutionIntent::Execute);

    constexpr InvocationReason invocation_reason = InvocationReason::Dispatchable;
    static_assert(invocation_reason == InvocationReason::Dispatchable);

    constexpr ExecutionInvocation invocation =
        ExecutionInvocation::Prepare(kRouting, kExecution);
    static_assert(invocation.IsValid());
    static_assert(invocation.Execution() == 2001);
    static_assert(invocation.Capability() == 4001);
    static_assert(invocation.Target() == 5001);
    static_assert(invocation.Reason() == InvocationReason::Dispatchable);

    assert(version == Version{0, 1, 0});
    assert(identity.platform_id == 42);
    assert(identity.product_family_id == 7);
    assert(identity.platform_name == "GCFIOS");
    assert(lifecycle.IsValid());
    assert(context.IsValid());
    assert(event_header.IsValid());
    assert(log_entry.IsValid());
    assert(kSelection.IsSelected());
    assert(kAuthorization.IsAuthorized());
    assert(kAdmission.IsAdmitted());
    assert(kDispatch.IsDispatchable());
    assert(kRouting.IsRoutable());
    assert(invocation.IsValid());

    return 0;
}
