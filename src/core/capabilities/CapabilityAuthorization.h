#pragma once

#include <cstdint>

#include "core/capabilities/CapabilitySelection.h"

namespace gcfios::core::capabilities {

enum class AuthorizationStatus : std::uint8_t {
    Denied = 0,
    Authorized = 1
};

enum class AuthorizationReason : std::uint8_t {
    None = 0,
    Authorized = 1,
    SelectionNotValid = 2,
    DeniedByAuthority = 3
};

// Universal capability authorization decision V1.
// This represents an externally made authorization outcome for a selected
// capability. It does not discover, match, select, load, invoke, or execute.
class CapabilityAuthorization final {
public:
    constexpr CapabilityAuthorization() noexcept = default;

    constexpr CapabilityAuthorization(
        CapabilityRequirementId requirement_id,
        CapabilityId capability_id,
        AuthorizationStatus status,
        AuthorizationReason reason) noexcept
        : requirement_id_(requirement_id),
          capability_id_(capability_id),
          status_(status),
          reason_(reason) {}

    constexpr CapabilityRequirementId Requirement() const noexcept {
        return requirement_id_;
    }

    constexpr CapabilityId Capability() const noexcept {
        return capability_id_;
    }

    constexpr AuthorizationStatus Status() const noexcept {
        return status_;
    }

    constexpr AuthorizationReason Reason() const noexcept {
        return reason_;
    }

    constexpr bool IsAuthorized() const noexcept {
        return status_ == AuthorizationStatus::Authorized;
    }

    constexpr bool IsValid() const noexcept {
        if (requirement_id_ == 0) {
            return false;
        }

        if (status_ == AuthorizationStatus::Authorized) {
            return capability_id_ != 0 && reason_ == AuthorizationReason::Authorized;
        }

        return status_ == AuthorizationStatus::Denied &&
               capability_id_ != 0 &&
               reason_ != AuthorizationReason::None &&
               reason_ != AuthorizationReason::Authorized;
    }

    static constexpr CapabilityAuthorization Authorized(
        const CapabilitySelectionResult& selection) noexcept {
        if (!selection.IsValid() || !selection.IsSelected()) {
            return {selection.Requirement(),
                    selection.Capability(),
                    AuthorizationStatus::Denied,
                    AuthorizationReason::SelectionNotValid};
        }

        return {selection.Requirement(),
                selection.Capability(),
                AuthorizationStatus::Authorized,
                AuthorizationReason::Authorized};
    }

    static constexpr CapabilityAuthorization Denied(
        const CapabilitySelectionResult& selection,
        AuthorizationReason reason) noexcept {
        return {selection.Requirement(),
                selection.Capability(),
                AuthorizationStatus::Denied,
                reason};
    }

    friend constexpr bool operator==(
        const CapabilityAuthorization&,
        const CapabilityAuthorization&) noexcept = default;

private:
    CapabilityRequirementId requirement_id_{};
    CapabilityId capability_id_{};
    AuthorizationStatus status_{AuthorizationStatus::Denied};
    AuthorizationReason reason_{AuthorizationReason::None};
};

} // namespace gcfios::core::capabilities
