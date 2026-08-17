#pragma once

#include <cstdint>
#include <string_view>

#include "core/foundation/Foundation_Types.h"
#include "core/system/versioning/Version.h"

namespace gcfios::core::capabilities {

using CapabilityId = gcfios::foundation::Identifier;
using CapabilityKind = std::uint32_t;

// Universal capability descriptor V1.
// This describes a capability only; it does not discover, register, load,
// execute, or persist capabilities.
class CapabilityDescriptor final {
public:
    constexpr CapabilityDescriptor(
        CapabilityId id,
        CapabilityKind kind,
        gcfios::core::system::versioning::Version version,
        std::string_view name) noexcept
        : id_(id), kind_(kind), version_(version), name_(name) {}

    constexpr CapabilityId Id() const noexcept {
        return id_;
    }

    constexpr CapabilityKind Kind() const noexcept {
        return kind_;
    }

    constexpr gcfios::core::system::versioning::Version Version() const noexcept {
        return version_;
    }

    constexpr std::string_view Name() const noexcept {
        return name_;
    }

    constexpr bool IsValid() const noexcept {
        return id_ != 0 && kind_ != 0 && !name_.empty();
    }

private:
    CapabilityId id_{};
    CapabilityKind kind_{};
    gcfios::core::system::versioning::Version version_{};
    std::string_view name_{};
};

} // namespace gcfios::core::capabilities
