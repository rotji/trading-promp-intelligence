#include "core/execution/ExecutionLifecycle.h"

#include <cassert>

using namespace gcfios::core::execution;

int main() {
    constexpr ExecutionLifecycle created{};
    static_assert(created.State() == ExecutionState::Created);
    static_assert(created.CanTransitionTo(ExecutionState::Accepted));
    static_assert(created.CanTransitionTo(ExecutionState::Failed));
    static_assert(!created.CanTransitionTo(ExecutionState::Succeeded));

    constexpr ExecutionLifecycle accepted{ExecutionState::Accepted};
    static_assert(accepted.CanTransitionTo(ExecutionState::Succeeded));
    static_assert(accepted.CanTransitionTo(ExecutionState::Failed));
    static_assert(!accepted.CanTransitionTo(ExecutionState::Created));

    constexpr ExecutionLifecycle succeeded{ExecutionState::Succeeded};
    static_assert(!succeeded.CanTransitionTo(ExecutionState::Created));
    static_assert(!succeeded.CanTransitionTo(ExecutionState::Failed));

    ExecutionLifecycle lifecycle{};
    assert(lifecycle.TransitionTo(ExecutionState::Accepted));
    assert(lifecycle.State() == ExecutionState::Accepted);
    assert(lifecycle.TransitionTo(ExecutionState::Succeeded));
    assert(lifecycle.State() == ExecutionState::Succeeded);
    assert(!lifecycle.TransitionTo(ExecutionState::Failed));
    assert(lifecycle.State() == ExecutionState::Succeeded);

    ExecutionLifecycle failed{};
    assert(failed.TransitionTo(ExecutionState::Failed));
    assert(failed.State() == ExecutionState::Failed);
    assert(!failed.TransitionTo(ExecutionState::Accepted));

    return 0;
}
