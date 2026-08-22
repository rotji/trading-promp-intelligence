#include <cassert>

#include "core/execution/ExecutionInvocation.h"

using namespace gcfios::core::execution;
using gcfios::core::capabilities::CapabilityAuthorization;
using gcfios::core::capabilities::CapabilitySelectionResult;

constexpr ExecutionContract kExecution{2001, ExecutionIntent::Execute, ExecutionState::Created};
constexpr CapabilitySelectionResult kSelection = CapabilitySelectionResult::Selected(3001, 4001);
constexpr CapabilityAuthorization kAuthorization = CapabilityAuthorization::Authorized(kSelection);
constexpr ExecutionAdmission kAdmission = ExecutionAdmission::Admit(kAuthorization, kExecution);
constexpr ExecutionDispatch kDispatch =
    ExecutionDispatch::Prepare(kAuthorization, kAdmission, kExecution);
constexpr ExecutionRouting kRouting = ExecutionRouting::Prepare(kDispatch, kExecution, 5001);

static_assert(kAdmission.IsValid());
static_assert(kDispatch.IsValid());
static_assert(kRouting.IsValid());
static_assert(kRouting.IsRoutable());

constexpr ExecutionInvocation kInvocable =
    ExecutionInvocation::Prepare(kRouting, kExecution);
static_assert(kInvocable.IsValid());
static_assert(kInvocable.IsInvocable());
static_assert(kInvocable.Execution() == 2001);
static_assert(kInvocable.Capability() == 4001);
static_assert(kInvocable.Target() == 5001);
static_assert(kInvocable.Reason() == InvocationReason::Invocable);

constexpr ExecutionInvocation kInvalidRouting =
    ExecutionInvocation::Prepare(ExecutionRouting{}, kExecution);
static_assert(kInvalidRouting.IsValid());
static_assert(!kInvalidRouting.IsInvocable());
static_assert(kInvalidRouting.Reason() == InvocationReason::RoutingNotValid);

constexpr ExecutionContract kOtherExecution{2002, ExecutionIntent::Execute, ExecutionState::Created};
constexpr ExecutionInvocation kIdentityMismatch =
    ExecutionInvocation::Prepare(kRouting, kOtherExecution);
static_assert(kIdentityMismatch.IsValid());
static_assert(!kIdentityMismatch.IsInvocable());
static_assert(kIdentityMismatch.Reason() == InvocationReason::ExecutionIdentityMismatch);

constexpr ExecutionContract kAcceptedExecution{2001, ExecutionIntent::Execute, ExecutionState::Accepted};
constexpr ExecutionInvocation kStateRejected =
    ExecutionInvocation::Prepare(kRouting, kAcceptedExecution);
static_assert(kStateRejected.IsValid());
static_assert(!kStateRejected.IsInvocable());
static_assert(kStateRejected.Reason() == InvocationReason::ExecutionStateNotInvocable);

constexpr ExecutionContract kInvalidExecution{0, ExecutionIntent::Execute, ExecutionState::Created};
constexpr ExecutionInvocation kExecutionRejected =
    ExecutionInvocation::Prepare(kRouting, kInvalidExecution);
static_assert(!kExecutionRejected.IsValid());
static_assert(!kExecutionRejected.IsInvocable());
static_assert(kExecutionRejected.Reason() == InvocationReason::ExecutionNotValid);

int main() {
    const auto invocable = ExecutionInvocation::Prepare(kRouting, kExecution);
    assert(invocable.IsValid());
    assert(invocable.IsInvocable());
    assert(invocable.Execution() == 2001);
    assert(invocable.Capability() == 4001);
    assert(invocable.Target() == 5001);

    const auto invalid_routing = ExecutionInvocation::Prepare(ExecutionRouting{}, kExecution);
    assert(invalid_routing.IsValid());
    assert(!invalid_routing.IsInvocable());
    assert(invalid_routing.Reason() == InvocationReason::RoutingNotValid);

    return 0;
}
