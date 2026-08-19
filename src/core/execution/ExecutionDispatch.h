#pragma once

#include <cstdint>

#include "core/capabilities/CapabilityAuthorization.h"
#include "core/execution/Execution.h"
#include "core/execution/ExecutionAdmission.h"

namespace gcfios::core::execution {

enum class DispatchStatus : std::uint8_t {
    Rejected = 0,
    Dispatchable = 1
};

enum class DispatchReason : std::uint8_t {
    None = 0,
    Dispatchable = 1,
    AuthorizationNotValid = 2,
    AdmissionNotValid = 3,
    ExecutionNotValid = 4,
    ExecutionIdentityMismatch = 5,
    ExecutionStateNotDispatchable = 6
};

// Universal execution dispatch handoff contract V1.
// This represents whether an admitted execution has a structurally valid
// dispatch intent. It does not schedule, queue, allocate, invoke, execute,
// retry, cancel, persist, or mutate any input.
class ExecutionDispatch final {
public:
    constexpr ExecutionDispatch() noexcept = default;

    constexpr ExecutionDispatch(
        ExecutionId execution_id,
        gcfios::core::capabilities::CapabilityId capability_id,
        DispatchStatus status,
        DispatchReason reason) noexcept
        : execution_id_(execution_id),
          capability_id_(capability_id),
          status_(status),
          reason_(reason) {}

    constexpr ExecutionId Execution() const noexcept {
        return execution_id_;
    }

    constexpr gcfios::core::capabilities::CapabilityId Capability() const noexcept {
        return capability_id_;
    }

    constexpr DispatchStatus Status() const noexcept {
        return status_;
    }

    constexpr DispatchReason Reason() const noexcept {
        return reason_;
    }

    constexpr bool IsDispatchable() const noexcept {
        return status_ == DispatchStatus::Dispatchable;
    }

    constexpr bool IsValid() const noexcept {
        if (execution_id_ == 0) {
            return false;
        }

        if (status_ == DispatchStatus::Dispatchable) {
            return capability_id_ != 0 && reason_ == DispatchReason::Dispatchable;
        }

        return status_ == DispatchStatus::Rejected &&
               reason_ != DispatchReason::None &&
               reason_ != DispatchReason::Dispatchable;
    }

    static constexpr ExecutionDispatch Prepare(
        const gcfios::core::capabilities::CapabilityAuthorization& authorization,
        const ExecutionAdmission& admission,
        const ExecutionContract& execution) noexcept {
        if (!authorization.IsValid() || !authorization.IsAuthorized() ||
            authorization.Capability() == 0) {
            return {execution.Id(),
                    authorization.Capability(),
                    DispatchStatus::Rejected,
                    DispatchReason::AuthorizationNotValid};
        }

        if (!admission.IsValid() || !admission.IsAdmitted()) {
            return {execution.Id(),
                    authorization.Capability(),
                    DispatchStatus::Rejected,
                    DispatchReason::AdmissionNotValid};
        }

        if (execution.Id() == 0) {
            return {execution.Id(),
                    authorization.Capability(),
                    DispatchStatus::Rejected,
                    DispatchReason::ExecutionNotValid};
        }

        if (admission.Execution() != execution.Id()) {
            return {execution.Id(),
                    authorization.Capability(),
                    DispatchStatus::Rejected,
                    DispatchReason::ExecutionIdentityMismatch};
        }

        if (execution.State() != ExecutionState::Created) {
            return {execution.Id(),
                    authorization.Capability(),
                    DispatchStatus::Rejected,
                    DispatchReason::ExecutionStateNotDispatchable};
        }

        return {execution.Id(),
                authorization.Capability(),
                DispatchStatus::Dispatchable,
                DispatchReason::Dispatchable};
    }

    friend constexpr bool operator==(
        const ExecutionDispatch&,
        const ExecutionDispatch&) noexcept = default;

private:
    ExecutionId execution_id_{};
    gcfios::core::capabilities::CapabilityId capability_id_{};
    DispatchStatus status_{DispatchStatus::Rejected};
    DispatchReason reason_{DispatchReason::None};
};

} // namespace gcfios::core::execution
