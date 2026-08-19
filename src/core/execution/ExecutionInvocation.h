#pragma once

#include <cstdint>

#include "core/execution/Execution.h"
#include "core/execution/ExecutionRouting.h"

namespace gcfios::core::execution {

enum class InvocationStatus : std::uint8_t {
    Rejected = 0,
    Invocable = 1
};

enum class InvocationReason : std::uint8_t {
    None = 0,
    Invocable = 1,
    RoutingNotValid = 2,
    ExecutionNotValid = 3,
    ExecutionIdentityMismatch = 4,
    ExecutionStateNotInvocable = 5,
    ExecutionIntentNotInvocable = 6
};

// Universal execution invocation handoff contract V1.
// This confirms that an already-routable execution may be handed to a future
// runtime invoker. It does not invoke, schedule, queue, allocate, transport,
// execute, retry, cancel, persist, or mutate any input or lifecycle state.
class ExecutionInvocation final {
public:
    constexpr ExecutionInvocation() noexcept = default;

    constexpr ExecutionInvocation(
        ExecutionId execution_id,
        gcfios::core::capabilities::CapabilityId capability_id,
        RuntimeTargetId target_id,
        InvocationStatus status,
        InvocationReason reason) noexcept
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
    constexpr InvocationStatus Status() const noexcept { return status_; }
    constexpr InvocationReason Reason() const noexcept { return reason_; }

    constexpr bool IsInvocable() const noexcept {
        return status_ == InvocationStatus::Invocable;
    }

    constexpr bool IsValid() const noexcept {
        if (execution_id_ == 0) {
            return false;
        }

        if (status_ == InvocationStatus::Invocable) {
            return capability_id_ != 0 && target_id_ != 0 &&
                   reason_ == InvocationReason::Invocable;
        }

        return status_ == InvocationStatus::Rejected &&
               reason_ != InvocationReason::None &&
               reason_ != InvocationReason::Invocable;
    }

    static constexpr ExecutionInvocation Prepare(
        const ExecutionRouting& routing,
        const ExecutionContract& execution) noexcept {
        if (!routing.IsValid() || !routing.IsRoutable()) {
            return {execution.Id(),
                    routing.Capability(),
                    routing.Target(),
                    InvocationStatus::Rejected,
                    InvocationReason::RoutingNotValid};
        }

        if (execution.Id() == 0) {
            return {execution.Id(),
                    routing.Capability(),
                    routing.Target(),
                    InvocationStatus::Rejected,
                    InvocationReason::ExecutionNotValid};
        }

        if (routing.Execution() != execution.Id()) {
            return {execution.Id(),
                    routing.Capability(),
                    routing.Target(),
                    InvocationStatus::Rejected,
                    InvocationReason::ExecutionIdentityMismatch};
        }

        if (execution.State() != ExecutionState::Created) {
            return {execution.Id(),
                    routing.Capability(),
                    routing.Target(),
                    InvocationStatus::Rejected,
                    InvocationReason::ExecutionStateNotInvocable};
        }

        if (execution.Intent() != ExecutionIntent::Execute) {
            return {execution.Id(),
                    routing.Capability(),
                    routing.Target(),
                    InvocationStatus::Rejected,
                    InvocationReason::ExecutionIntentNotInvocable};
        }

        return {execution.Id(),
                routing.Capability(),
                routing.Target(),
                InvocationStatus::Invocable,
                InvocationReason::Invocable};
    }

    friend constexpr bool operator==(
        const ExecutionInvocation&,
        const ExecutionInvocation&) noexcept = default;

private:
    ExecutionId execution_id_{};
    gcfios::core::capabilities::CapabilityId capability_id_{};
    RuntimeTargetId target_id_{};
    InvocationStatus status_{InvocationStatus::Rejected};
    InvocationReason reason_{InvocationReason::None};
};

} // namespace gcfios::core::execution
