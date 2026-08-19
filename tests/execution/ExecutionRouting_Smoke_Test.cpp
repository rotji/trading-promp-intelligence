#include <cassert>

#include "core/execution/ExecutionRouting.h"

using namespace gcfios::core::execution;
using gcfios::core::capabilities::CapabilityAuthorization;
using gcfios::core::capabilities::CapabilitySelectionResult;

constexpr ExecutionContract kExecution{2001, ExecutionIntent::Execute, ExecutionState::Created};
constexpr CapabilitySelectionResult kSelection = CapabilitySelectionResult::Selected(3001, 4001);
constexpr CapabilityAuthorization kAuthorization = CapabilityAuthorization::Authorized(kSelection);
constexpr ExecutionAdmission kAdmission = ExecutionAdmission::Admitted(2001);
constexpr ExecutionDispatch kDispatch =
    ExecutionDispatch::Prepare(kAuthorization, kAdmission, kExecution);

static_assert(kDispatch.IsValid());
static_assert(kDispatch.IsDispatchable());

constexpr ExecutionRouting kRoutable = ExecutionRouting::Prepare(kDispatch, kExecution, 5001);
static_assert(kRoutable.IsValid());
static_assert(kRoutable.IsRoutable());
static_assert(kRoutable.Execution() == 2001);
static_assert(kRoutable.Capability() == 4001);
static_assert(kRoutable.Target() == 5001);
static_assert(kRoutable.Reason() == RoutingReason::Routable);

constexpr ExecutionRouting kNoTarget = ExecutionRouting::Prepare(kDispatch, kExecution, 0);
static_assert(kNoTarget.IsValid());
static_assert(!kNoTarget.IsRoutable());
static_assert(kNoTarget.Reason() == RoutingReason::TargetNotValid);

constexpr ExecutionContract kOtherExecution{2002, ExecutionIntent::Execute, ExecutionState::Created};
constexpr ExecutionRouting kIdentityMismatch =
    ExecutionRouting::Prepare(kDispatch, kOtherExecution, 5001);
static_assert(kIdentityMismatch.IsValid());
static_assert(!kIdentityMismatch.IsRoutable());
static_assert(kIdentityMismatch.Reason() == RoutingReason::ExecutionIdentityMismatch);

constexpr ExecutionRouting kInvalidDispatch =
    ExecutionRouting::Prepare(ExecutionDispatch{}, kExecution, 5001);
static_assert(kInvalidDispatch.IsValid());
static_assert(!kInvalidDispatch.IsRoutable());
static_assert(kInvalidDispatch.Reason() == RoutingReason::DispatchNotValid);

int main() {
    const auto routable = ExecutionRouting::Prepare(kDispatch, kExecution, 5001);
    assert(routable.IsValid());
    assert(routable.IsRoutable());
    assert(routable.Execution() == 2001);
    assert(routable.Capability() == 4001);
    assert(routable.Target() == 5001);

    const auto no_target = ExecutionRouting::Prepare(kDispatch, kExecution, 0);
    assert(no_target.IsValid());
    assert(!no_target.IsRoutable());
    assert(no_target.Reason() == RoutingReason::TargetNotValid);

    return 0;
}
