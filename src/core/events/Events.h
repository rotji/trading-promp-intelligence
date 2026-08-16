#pragma once

#include <cstdint>

#include "core/foundation/Foundation_Types.h"

namespace gcfios::core::events {

using EventId = gcfios::foundation::Identifier;
using EventType = std::uint32_t;

class EventHeader final {
public:
    constexpr EventHeader(EventId id, EventType type, gcfios::foundation::Identifier source) noexcept
        : id_(id), type_(type), source_(source) {}

    constexpr EventId Id() const noexcept {
        return id_;
    }

    constexpr EventType Type() const noexcept {
        return type_;
    }

    constexpr gcfios::foundation::Identifier Source() const noexcept {
        return source_;
    }

private:
    EventId id_{};
    EventType type_{};
    gcfios::foundation::Identifier source_{};
};

} // namespace gcfios::core::events
