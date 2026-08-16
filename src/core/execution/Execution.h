#pragma once

#include "core/foundation/Foundation_Types.h"

namespace gcfios::core::execution {

using ExecutionId = gcfios::foundation::Identifier;

// Execution intent is deliberately minimal in V1. It describes intent only;
// it does not schedule, execute, retry, cancel, or orchestrate work.
enum class ExecutionIntent {
    Execute
};

// Execution state is descriptive contract data only. V1 does not implement
// state transitions or an execution runtime.
enum class ExecutionState {
    Created,
    Accepted,
    Succeeded,
    Failed
};

// Immutable, client-independent representation of an execution contract.
// Ownership is value-based: the contract owns its scalar identity, intent,
// and state and exposes no mutable references or runtime handles.
class ExecutionContract final {
public:
    constexpr ExecutionContract(
        ExecutionId id,
        ExecutionIntent intent,
        ExecutionState state) noexcept
        : id_(id), intent_(intent), state_(state) {}

    constexpr ExecutionId Id() const noexcept {
        return id_;
    }

    constexpr ExecutionIntent Intent() const noexcept {
        return intent_;
    }

    constexpr ExecutionState State() const noexcept {
        return state_;
    }

private:
    ExecutionId id_{};
    ExecutionIntent intent_{ExecutionIntent::Execute};
    ExecutionState state_{ExecutionState::Created};
};

} // namespace gcfios::core::execution
