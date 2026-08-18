#pragma once

#include <cstdint>

#include "core/foundation/Foundation_Types.h"
#include "core/system/versioning/Version.h"

namespace gcfios::core::capabilities {

using CapabilityRequirementId = gcfios::foundation::Identifier;
using RequiredCapabilityKind = std::uint32_t;

// Universal capability requirement V1.
// This expresses what a consumer requires; it does not discover, match,
// select, register, load, invoke, or execute a capability.
class CapabilityRequirement final {
public:
    constexpr CapabilityRequirement() noexcept = default;

    constexpr CapabilityRequirement(
        CapabilityRequirementId id,
        RequiredCapabilityKind kind,
        gcfios::core::system::versioning::Version minimum_version = {}) noexcept
        : id_(id), kind_(kind), minimum_version_(minimum_version) {}

    constexpr CapabilityRequirementId Id() const noexcept {
        return id_;
    }

    constexpr RequiredCapabilityKind Kind() const noexcept {
        return kind_;
    }

    constexpr gcfios::core::system::versioning::Version MinimumVersion() const noexcept {
        return minimum_version_;
    }

    constexpr bool HasMinimumVersion() const noexcept {
        return minimum_version_.major != 0 ||
               minimum_version_.minor != 0 ||
               minimum_version_.patch != 0;
    }

    constexpr bool IsValid() const noexcept {
        return id_ != 0 && kind_ != 0;
    }

    friend constexpr bool operator==(const CapabilityRequirement&, const CapabilityRequirement&) noexcept = default;

private:
    CapabilityRequirementId id_{};
    RequiredCapabilityKind kind_{};
    gcfios::core::system::versioning::Version minimum_version_{};
};

} // namespace gcfios::core::capabilities
