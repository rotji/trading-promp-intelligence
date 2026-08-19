#pragma once

#include <cstdint>

#include "core/execution/Execution.h"
#include "core/execution/ExecutionDispatch.h"
#include "core/foundation/Foundation_Types.h"

namespace gcfios::core::execution {

using RuntimeTargetId = gcfios::foundation::Identifier;

enum class RoutingStatus : std::uint8_t {
    Rejected = 0,
    Routable = 1
};

enum class RoutingReason : std::uint8_t {
    None = 0,
    Routable = 1,
    DispatchNotValid = 2,
    ExecutionNotValid = 3,
    TargetNotValid = 4,
    ExecutionIdentityMismatch = 5
};

// Universal execution routing handoff contract V1.
// This binds an already-dispatchable execution to an explicitly supplied
// runtime target. It does not discover targets, schedule, queue, allocate,
// transport, invoke, execute, retry, cancel, persist, or mutate any input.
class ExecutionRouting final {
public:
    constexpr ExecutionRouting() noexcept = default;

    constexpr ExecutionRouting(
        ExecutionId execution_id,
        gcfios::core::capabilities::CapabilityId capability_id,
        RuntimeTargetId target_id,
        RoutingStatus status,
        RoutingReason reason) noexcept
        : execution_id_(execution_id),
          capability_id_(capability_id),
          target_id_(target_id),
          status_(status),
          reason_(reason) {}

    constexpr ExecutionId Execution() const noexcept { return execution_id_; }
    constexpr gcfios::core::capabilities::CapabilityId Capability() const noexcept {
        return capability_id_;
    }
    constexpr RuntimeTargetId Target() const noexcept { return target_id_; }
    constexpr RoutingStatus Status() const noexcept { return status_; }
    constexpr RoutingReason Reason() const noexcept { return reason_; }

    constexpr bool IsRoutable() const noexcept {
        return status_ == RoutingStatus::Routable;
    }

    constexpr bool IsValid() const noexcept {
        if (execution_id_ == 0) {
            return false;
        }

        if (status_ == RoutingStatus::Routable) {
            return capability_id_ != 0 && target_id_ != 0 &&
                   reason_ == RoutingReason::Routable;
        }

        return status_ == RoutingStatus::Rejected &&
               reason_ != RoutingReason::None &&
               reason_ != RoutingReason::Routable;
    }

    static constexpr ExecutionRouting Prepare(
        const ExecutionDispatch& dispatch,
        const ExecutionContract& execution,
        RuntimeTargetId target_id) noexcept {
        if (!dispatch.IsValid() || !dispatch.IsDispatchable() ||
            dispatch.Capability() == 0) {
            return {execution.Id(),
                    dispatch.Capability(),
                    target_id,
                    RoutingStatus::Rejected,
                    RoutingReason::DispatchNotValid};
        }

        if (execution.Id() == 0) {
            return {execution.Id(),
                    dispatch.Capability(),
                    target_id,
                    RoutingStatus::Rejected,
                    RoutingReason::ExecutionNotValid};
        }

        if (dispatch.Execution() != execution.Id()) {
            return {execution.Id(),
                    dispatch.Capability(),
                    target_id,
                    RoutingStatus::Rejected,
                    RoutingReason::ExecutionIdentityMismatch};
        }

        if (target_id == 0) {
            return {execution.Id(),
                    dispatch.Capability(),
                    target_id,
                    RoutingStatus::Rejected,
                    RoutingReason::TargetNotValid};
        }

        return {execution.Id(),
                dispatch.Capability(),
                target_id,
                RoutingStatus::Routable,
                RoutingReason::Routable};
    }

    friend constexpr bool operator==(
        const ExecutionRouting&,
        const ExecutionRouting&) noexcept = default;

private:
    ExecutionId execution_id_{};
    gcfios::core::capabilities::CapabilityId capability_id_{};
    RuntimeTargetId target_id_{};
    RoutingStatus status_{RoutingStatus::Rejected};
    RoutingReason reason_{RoutingReason::None};
};

} // namespace gcfios::core::execution
