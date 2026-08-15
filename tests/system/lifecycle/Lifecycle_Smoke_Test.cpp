#include <cassert>

#include "core/system/lifecycle/Lifecycle.h"

int main() {
    using gcfios::core::system::lifecycle::Lifecycle;
    using gcfios::core::system::lifecycle::State;

    Lifecycle lifecycle{};

    assert(lifecycle.state == State::Created);
    assert(lifecycle.CanTransitionTo(State::Initializing));
    assert(lifecycle.TransitionTo(State::Initializing));
    assert(lifecycle.TransitionTo(State::Initialized));
    assert(lifecycle.TransitionTo(State::Running));
    assert(lifecycle.TransitionTo(State::Stopping));
    assert(lifecycle.TransitionTo(State::Stopped));

    assert(!lifecycle.CanTransitionTo(State::Running));
    assert(!lifecycle.TransitionTo(State::Running));

    Lifecycle failed_lifecycle{};
    assert(failed_lifecycle.TransitionTo(State::Failed));
    assert(!failed_lifecycle.CanTransitionTo(State::Running));

    return 0;
}
