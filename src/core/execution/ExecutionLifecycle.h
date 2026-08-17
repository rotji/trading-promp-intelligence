#pragma once

#include "core/execution/Execution.h"

namespace gcfios::core::execution {

// Universal execution lifecycle contract V1.
// This defines valid state progression only; it does not execute work,
// schedule work, retry, cancel, or orchestrate execution.
class ExecutionLifecycle final {
public:
    constexpr explicit ExecutionLifecycle(ExecutionState state = ExecutionState::Created) noexcept
        : state_(state) {}

    static constexpr bool IsValidTransition(
        ExecutionState from,
        ExecutionState to) noexcept {
        switch (from) {
        case ExecutionState::Created:
            return to == ExecutionState::Accepted || to == ExecutionState::Failed;
        case ExecutionState::Accepted:
            return to == ExecutionState::Succeeded || to == ExecutionState::Failed;
        case ExecutionState::Succeeded:
            return false;
        case ExecutionState::Failed:
            return false;
        }

        return false;
    }

    constexpr ExecutionState State() const noexcept {
        return state_;
    }

    constexpr bool CanTransitionTo(ExecutionState next) const noexcept {
        return IsValidTransition(state_, next);
    }

    constexpr bool TransitionTo(ExecutionState next) noexcept {
        if (!CanTransitionTo(next)) {
            return false;
        }

        state_ = next;
        return true;
    }

private:
    ExecutionState state_{ExecutionState::Created};
};

} // namespace gcfios::core::execution
