#include <cassert>

#include "core/capabilities/CapabilityAuthorization.h"
#include "core/execution/Execution.h"
#include "core/execution/ExecutionAdmission.h"

int main() {
    using gcfios::core::capabilities::AuthorizationReason;
    using gcfios::core::capabilities::CapabilityAuthorization;
    using gcfios::core::capabilities::CapabilitySelectionResult;
    using gcfios::core::execution::AdmissionReason;
    using gcfios::core::execution::AdmissionStatus;
    using gcfios::core::execution::ExecutionAdmission;
    using gcfios::core::execution::ExecutionContract;
    using gcfios::core::execution::ExecutionIntent;
    using gcfios::core::execution::ExecutionState;

    constexpr ExecutionAdmission empty{};
    static_assert(!empty.IsValid());
    static_assert(!empty.IsAdmitted());
    static_assert(empty.Status() == AdmissionStatus::Rejected);

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

    static_assert(admitted.IsValid());
    static_assert(admitted.IsAdmitted());
    static_assert(admitted.Execution() == 3001);
    static_assert(admitted.Status() == AdmissionStatus::Admitted);
    static_assert(admitted.Reason() == AdmissionReason::Admitted);

    constexpr CapabilityAuthorization denied =
        CapabilityAuthorization::Denied(
            selected,
            AuthorizationReason::DeniedByAuthority);

    constexpr ExecutionAdmission authorization_rejected =
        ExecutionAdmission::Admit(denied, created_execution);

    static_assert(authorization_rejected.IsValid());
    static_assert(!authorization_rejected.IsAdmitted());
    static_assert(authorization_rejected.Reason() ==
                  AdmissionReason::AuthorizationNotValid);

    constexpr ExecutionContract accepted_execution{
        3002,
        ExecutionIntent::Execute,
        ExecutionState::Accepted};

    constexpr ExecutionAdmission state_rejected =
        ExecutionAdmission::Admit(authorized, accepted_execution);

    static_assert(state_rejected.IsValid());
    static_assert(!state_rejected.IsAdmitted());
    static_assert(state_rejected.Reason() ==
                  AdmissionReason::ExecutionStateNotAdmissible);

    constexpr ExecutionContract invalid_execution{
        0,
        ExecutionIntent::Execute,
        ExecutionState::Created};

    constexpr ExecutionAdmission execution_rejected =
        ExecutionAdmission::Admit(authorized, invalid_execution);

    static_assert(!execution_rejected.IsValid());
    static_assert(!execution_rejected.IsAdmitted());
    static_assert(execution_rejected.Reason() ==
                  AdmissionReason::ExecutionNotValid);

    assert(admitted.IsValid());
    assert(authorization_rejected.IsValid());
    assert(state_rejected.IsValid());
    assert(!execution_rejected.IsValid());

    return 0;
}
