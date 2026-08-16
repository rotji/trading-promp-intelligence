#include <cassert>

#include "core/events/Events.h"

int main() {
    using gcfios::core::events::EventHeader;
    using gcfios::core::events::EventType;
    using gcfios::foundation::Identifier;

    constexpr Identifier event_id{42};
    constexpr EventType event_type{7};
    constexpr Identifier source_id{99};

    constexpr EventHeader event{event_id, event_type, source_id};

    static_assert(event.Id() == event_id);
    static_assert(event.Type() == event_type);
    static_assert(event.Source() == source_id);

    assert(event.Id() == event_id);
    assert(event.Type() == event_type);
    assert(event.Source() == source_id);

    return 0;
}
