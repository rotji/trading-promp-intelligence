#pragma once

namespace gcfios::core::system::lifecycle {

enum class State {
    Created,
    Initializing,
    Initialized,
    Running,
    Stopping,
    Stopped,
    Failed
};

constexpr bool IsValidTransition(State from, State to) noexcept {
    switch (from) {
    case State::Created:
        return to == State::Initializing || to == State::Failed;
    case State::Initializing:
        return to == State::Initialized || to == State::Failed;
    case State::Initialized:
        return to == State::Running || to == State::Stopping || to == State::Failed;
    case State::Running:
        return to == State::Stopping || to == State::Failed;
    case State::Stopping:
        return to == State::Stopped || to == State::Failed;
    case State::Stopped:
        return false;
    case State::Failed:
        return false;
    }

    return false;
}

struct Lifecycle {
    State state{State::Created};

    constexpr bool CanTransitionTo(State next) const noexcept {
        return IsValidTransition(state, next);
    }

    constexpr bool TransitionTo(State next) noexcept {
        if (!CanTransitionTo(next)) {
            return false;
        }

        state = next;
        return true;
    }
};

} // namespace gcfios::core::system::lifecycle
