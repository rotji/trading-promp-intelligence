#include <cassert>

#include "core/capabilities/CapabilityCompatibility.h"

int main() {
    using gcfios::core::capabilities::CapabilityCompatibility;
    using gcfios::core::capabilities::CapabilityDescriptor;
    using gcfios::core::capabilities::CapabilityRequirement;
    using gcfios::core::capabilities::CompatibilityReason;
    using gcfios::core::capabilities::CompatibilityStatus;

    constexpr CapabilityDescriptor capability{
        2001,
        42,
        {2, 1, 0},
        "market-data"
    };

    constexpr CapabilityRequirement compatible_requirement{
        3001,
        42,
        {2, 0, 0}
    };

    constexpr auto compatible = CapabilityCompatibility::Evaluate(
        capability, compatible_requirement);

    static_assert(compatible.IsValid());
    static_assert(compatible.IsCompatible());
    static_assert(compatible.Status() == CompatibilityStatus::Compatible);
    static_assert(compatible.Reason() == CompatibilityReason::Compatible);
    static_assert(compatible.Capability() == 2001);
    static_assert(compatible.Requirement() == 3001);

    constexpr CapabilityRequirement wrong_kind{3002, 7};
    constexpr auto kind_mismatch = CapabilityCompatibility::Evaluate(
        capability, wrong_kind);
    static_assert(!kind_mismatch.IsCompatible());
    static_assert(kind_mismatch.Reason() == CompatibilityReason::CapabilityKindMismatch);

    constexpr CapabilityRequirement newer_requirement{3003, 42, {3, 0, 0}};
    constexpr auto version_mismatch = CapabilityCompatibility::Evaluate(
        capability, newer_requirement);
    static_assert(!version_mismatch.IsCompatible());
    static_assert(version_mismatch.Reason() == CompatibilityReason::CapabilityVersionTooLow);

    constexpr CapabilityRequirement no_minimum{3004, 42};
    constexpr auto no_minimum_result = CapabilityCompatibility::Evaluate(
        capability, no_minimum);
    static_assert(no_minimum_result.IsCompatible());

    constexpr CapabilityDescriptor invalid_capability{0, 42, {2, 1, 0}, "market-data"};
    constexpr auto invalid_capability_result = CapabilityCompatibility::Evaluate(
        invalid_capability, compatible_requirement);
    static_assert(invalid_capability_result.Reason() == CompatibilityReason::InvalidCapability);

    assert(compatible.IsCompatible());
    assert(!kind_mismatch.IsCompatible());
    assert(!version_mismatch.IsCompatible());
    assert(no_minimum_result.IsCompatible());
    assert(!invalid_capability_result.IsCompatible());

    return 0;
}
