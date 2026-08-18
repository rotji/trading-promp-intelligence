#pragma once

#include <cstdint>

namespace gcfios::core::state {

using StateValue = std::uint32_t;

class State final {
public:
    constexpr explicit State(StateValue value = 0) noexcept
        : value_(value) {}

    constexpr StateValue Value() const noexcept {
        return value_;
    }

    constexpr bool IsValid() const noexcept {
        return value_ != 0;
    }

    friend constexpr bool operator==(const State&, const State&) noexcept = default;

private:
    StateValue value_{};
};

class StateTransition final {
public:
    constexpr StateTransition(State previous, State next) noexcept
        : previous_(previous), next_(next) {}

    constexpr State Previous() const noexcept {
        return previous_;
    }

    constexpr State Next() const noexcept {
        return next_;
    }

    constexpr bool IsValid() const noexcept {
        return previous_.IsValid() && next_.IsValid() && previous_ != next_;
    }

private:
    State previous_{};
    State next_{};
};

} // namespace gcfios::core::state
