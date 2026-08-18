#include <cassert>

#include "core/state/State.h"

int main() {
    using gcfios::core::state::State;
    using gcfios::core::state::StateTransition;

    constexpr State invalid{};
    constexpr State one{1};
    constexpr State one_copy{1};
    constexpr State two{2};

    static_assert(!invalid.IsValid());
    static_assert(one.IsValid());
    static_assert(one == one_copy);
    static_assert(one != two);
    static_assert(one.Value() == 1);

    static_assert(StateTransition{one, two}.IsValid());
    static_assert(!StateTransition{one, one}.IsValid());
    static_assert(!StateTransition{invalid, two}.IsValid());
    static_assert(!StateTransition{one, invalid}.IsValid());

    constexpr StateTransition transition{one, two};
    assert(transition.Previous() == one);
    assert(transition.Next() == two);
    assert(transition.IsValid());

    return 0;
}
