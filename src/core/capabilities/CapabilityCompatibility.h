#pragma once

#include <cstdint>

#include "core/capabilities/Capability.h"
#include "core/capabilities/CapabilityRequirement.h"

namespace gcfios::core::capabilities {

enum class CompatibilityStatus : std::uint8_t {
    Incompatible = 0,
    Compatible = 1
};

enum class CompatibilityReason : std::uint8_t {
    Compatible = 0,
    InvalidCapability = 1,
    InvalidRequirement = 2,
    CapabilityKindMismatch = 3,
    CapabilityVersionTooLow = 4
};

// Universal capability compatibility V1.
// Evaluates only already-known descriptor and requirement data. It does not
// discover, register, select, rank, load, invoke, or execute capabilities.
class CapabilityCompatibility final {
public:
    constexpr CapabilityCompatibility() noexcept = default;

    constexpr CapabilityCompatibility(
        CapabilityId capability_id,
        CapabilityRequirementId requirement_id,
        CompatibilityStatus status,
        CompatibilityReason reason) noexcept
        : capability_id_(capability_id),
          requirement_id_(requirement_id),
          status_(status),
          reason_(reason) {}

    constexpr CapabilityId Capability() const noexcept {
        return capability_id_;
    }

    constexpr CapabilityRequirementId Requirement() const noexcept {
        return requirement_id_;
    }

    constexpr CompatibilityStatus Status() const noexcept {
        return status_;
    }

    constexpr CompatibilityReason Reason() const noexcept {
        return reason_;
    }

    constexpr bool IsCompatible() const noexcept {
        return status_ == CompatibilityStatus::Compatible;
    }

    constexpr bool IsValid() const noexcept {
        return capability_id_ != 0 && requirement_id_ != 0;
    }

    static constexpr CapabilityCompatibility Evaluate(
        const CapabilityDescriptor& capability,
        const CapabilityRequirement& requirement) noexcept {
        if (!capability.IsValid()) {
            return {capability.Id(), requirement.Id(),
                    CompatibilityStatus::Incompatible,
                    CompatibilityReason::InvalidCapability};
        }

        if (!requirement.IsValid()) {
            return {capability.Id(), requirement.Id(),
                    CompatibilityStatus::Incompatible,
                    CompatibilityReason::InvalidRequirement};
        }

        if (capability.Kind() != requirement.Kind()) {
            return {capability.Id(), requirement.Id(),
                    CompatibilityStatus::Incompatible,
                    CompatibilityReason::CapabilityKindMismatch};
        }

        if (requirement.HasMinimumVersion() &&
            IsVersionLess(capability.Version(), requirement.MinimumVersion())) {
            return {capability.Id(), requirement.Id(),
                    CompatibilityStatus::Incompatible,
                    CompatibilityReason::CapabilityVersionTooLow};
        }

        return {capability.Id(), requirement.Id(),
                CompatibilityStatus::Compatible,
                CompatibilityReason::Compatible};
    }

private:
    static constexpr bool IsVersionLess(
        gcfios::core::system::versioning::Version lhs,
        gcfios::core::system::versioning::Version rhs) noexcept {
        if (lhs.major != rhs.major) return lhs.major < rhs.major;
        if (lhs.minor != rhs.minor) return lhs.minor < rhs.minor;
        return lhs.patch < rhs.patch;
    }

    CapabilityId capability_id_{};
    CapabilityRequirementId requirement_id_{};
    CompatibilityStatus status_{CompatibilityStatus::Incompatible};
    CompatibilityReason reason_{CompatibilityReason::InvalidCapability};
};

} // namespace gcfios::core::capabilities
