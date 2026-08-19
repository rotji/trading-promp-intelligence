#include <cassert>

#include "core/capabilities/CapabilityAuthorization.h"
#include "core/execution/Execution.h"
#include "core/execution/ExecutionAdmission.h"
#include "core/execution/ExecutionDispatch.h"

int main() {
    using gcfios::core::capabilities::AuthorizationReason;
    using gcfios::core::capabilities::CapabilityAuthorization;
    using gcfios::core::capabilities::CapabilitySelectionResult;
    using gcfios::core::execution::DispatchReason;
    using gcfios::core::execution::DispatchStatus;
    using gcfios::core::execution::ExecutionAdmission;
    using gcfios::core::execution::ExecutionContract;
    using gcfios::core::execution::ExecutionDispatch;
    using gcfios::core::execution::ExecutionIntent;
    using gcfios::core::execution::ExecutionState;

    constexpr ExecutionDispatch empty{};
    static_assert(!empty.IsValid());
    static_assert(!empty.IsDispatchable());
    static_assert(empty.Status() == DispatchStatus::Rejected);

    constexpr CapabilitySelectionResult selected =
        CapabilitySelectionResult::Selected(1001, 2001);
    constexpr CapabilityAuthorization authorized =
        CapabilityAuthorization::Authorized(selected);
    constexpr ExecutionContract created_execution{
        3001,
        ExecutionIntent::Execute,
        ExecutionState::Created};
    constexpr ExecutionAdmission admitted =
        ExecutionAdmission::Admit(authorized, created_execution);

    constexpr ExecutionDispatch dispatchable =
        ExecutionDispatch::Prepare(authorized, admitted, created_execution);

    static_assert(dispatchable.IsValid());
    static_assert(dispatchable.IsDispatchable());
    static_assert(dispatchable.Execution() == 3001);
    static_assert(dispatchable.Capability() == 2001);
    static_assert(dispatchable.Status() == DispatchStatus::Dispatchable);
    static_assert(dispatchable.Reason() == DispatchReason::Dispatchable);

    constexpr CapabilityAuthorization denied =
        CapabilityAuthorization::Denied(
            selected,
            AuthorizationReason::DeniedByAuthority);
    constexpr ExecutionDispatch authorization_rejected =
        ExecutionDispatch::Prepare(denied, admitted, created_execution);

    static_assert(authorization_rejected.IsValid());
    static_assert(!authorization_rejected.IsDispatchable());
    static_assert(authorization_rejected.Reason() ==
                  DispatchReason::AuthorizationNotValid);

    constexpr ExecutionAdmission rejected_admission =
        ExecutionAdmission::Admit(denied, created_execution);
    constexpr ExecutionDispatch admission_rejected =
        ExecutionDispatch::Prepare(authorized, rejected_admission, created_execution);

    static_assert(admission_rejected.IsValid());
    static_assert(!admission_rejected.IsDispatchable());
    static_assert(admission_rejected.Reason() ==
                  DispatchReason::AdmissionNotValid);

    constexpr ExecutionContract mismatched_execution{
        3002,
        ExecutionIntent::Execute,
        ExecutionState::Created};
    constexpr ExecutionDispatch identity_rejected =
        ExecutionDispatch::Prepare(authorized, admitted, mismatched_execution);

    static_assert(identity_rejected.IsValid());
    static_assert(!identity_rejected.IsDispatchable());
    static_assert(identity_rejected.Reason() ==
                  DispatchReason::ExecutionIdentityMismatch);

    constexpr ExecutionContract accepted_execution{
        3001,
        ExecutionIntent::Execute,
        ExecutionState::Accepted};
    constexpr ExecutionAdmission accepted_admission =
        ExecutionAdmission::Admit(authorized, accepted_execution);
    constexpr ExecutionDispatch state_rejected =
        ExecutionDispatch::Prepare(authorized, accepted_admission, accepted_execution);

    static_assert(state_rejected.IsValid());
    static_assert(!state_rejected.IsDispatchable());
    static_assert(state_rejected.Reason() ==
                  DispatchReason::AdmissionNotValid);

    constexpr ExecutionContract invalid_execution{
        0,
        ExecutionIntent::Execute,
        ExecutionState::Created};
    constexpr ExecutionDispatch execution_rejected =
        ExecutionDispatch::Prepare(authorized, admitted, invalid_execution);

    static_assert(execution_rejected.IsValid());
    static_assert(!execution_rejected.IsDispatchable());
    static_assert(execution_rejected.Reason() ==
                  DispatchReason::ExecutionNotValid);

    assert(dispatchable.IsValid());
    assert(authorization_rejected.IsValid());
    assert(admission_rejected.IsValid());
    assert(identity_rejected.IsValid());
    assert(state_rejected.IsValid());
    assert(execution_rejected.IsValid());

    return 0;
}
