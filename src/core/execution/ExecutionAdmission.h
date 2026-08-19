#pragma once

#include <cstdint>

#include "core/capabilities/CapabilityAuthorization.h"
#include "core/execution/Execution.h"

namespace gcfios::core::execution {

enum class AdmissionStatus : std::uint8_t {
    Rejected = 0,
    Admitted = 1
};

enum class AdmissionReason : std::uint8_t {
    None = 0,
    Admitted = 1,
    AuthorizationNotValid = 2,
    ExecutionNotValid = 3,
    ExecutionStateNotAdmissible = 4
};

// Universal execution admission decision V1.
// This represents whether a valid authorized execution contract may enter
// the execution path. It does not execute, schedule, dispatch, retry,
// cancel, persist, or mutate either input.
class ExecutionAdmission final {
public:
    constexpr ExecutionAdmission() noexcept = default;

    constexpr ExecutionAdmission(
        ExecutionId execution_id,
        AdmissionStatus status,
        AdmissionReason reason) noexcept
        : execution_id_(execution_id),
          status_(status),
          reason_(reason) {}

    constexpr ExecutionId Execution() const noexcept {
        return execution_id_;
    }

    constexpr AdmissionStatus Status() const noexcept {
        return status_;
    }

    constexpr AdmissionReason Reason() const noexcept {
        return reason_;
    }

    constexpr bool IsAdmitted() const noexcept {
        return status_ == AdmissionStatus::Admitted;
    }

    constexpr bool IsValid() const noexcept {
        if (execution_id_ == 0) {
            return false;
        }

        if (status_ == AdmissionStatus::Admitted) {
            return reason_ == AdmissionReason::Admitted;
        }

        return status_ == AdmissionStatus::Rejected &&
               reason_ != AdmissionReason::None &&
               reason_ != AdmissionReason::Admitted;
    }

    static constexpr ExecutionAdmission Admit(
        const gcfios::core::capabilities::CapabilityAuthorization& authorization,
        const ExecutionContract& execution) noexcept {
        if (!authorization.IsValid() || !authorization.IsAuthorized()) {
            return {execution.Id(),
                    AdmissionStatus::Rejected,
                    AdmissionReason::AuthorizationNotValid};
        }

        if (execution.Id() == 0) {
            return {execution.Id(),
                    AdmissionStatus::Rejected,
                    AdmissionReason::ExecutionNotValid};
        }

        if (execution.State() != ExecutionState::Created) {
            return {execution.Id(),
                    AdmissionStatus::Rejected,
                    AdmissionReason::ExecutionStateNotAdmissible};
        }

        return {execution.Id(),
                AdmissionStatus::Admitted,
                AdmissionReason::Admitted};
    }

    friend constexpr bool operator==(
        const ExecutionAdmission&,
        const ExecutionAdmission&) noexcept = default;

private:
    ExecutionId execution_id_{};
    AdmissionStatus status_{AdmissionStatus::Rejected};
    AdmissionReason reason_{AdmissionReason::None};
};

} // namespace gcfios::core::execution
