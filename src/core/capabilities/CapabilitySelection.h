#pragma once

#include <cstdint>

#include "core/capabilities/Capability.h"
#include "core/capabilities/CapabilityRequirement.h"

namespace gcfios::core::capabilities {

enum class SelectionStatus : std::uint8_t {
    NotSelected = 0,
    Selected = 1
};

enum class SelectionReason : std::uint8_t {
    None = 0,
    Selected = 1,
    InvalidRequirement = 2,
    NoCompatibleCapability = 3,
    AmbiguousCandidates = 4
};

// Universal capability selection result V1.
// This represents an externally made selection outcome. It does not discover,
// match, rank, select, load, invoke, or execute capabilities.
class CapabilitySelectionResult final {
public:
    constexpr CapabilitySelectionResult() noexcept = default;

    constexpr CapabilitySelectionResult(
        CapabilityRequirementId requirement_id,
        CapabilityId capability_id,
        SelectionStatus status,
        SelectionReason reason) noexcept
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

    constexpr SelectionStatus Status() const noexcept {
        return status_;
    }

    constexpr SelectionReason Reason() const noexcept {
        return reason_;
    }

    constexpr bool IsSelected() const noexcept {
        return status_ == SelectionStatus::Selected;
    }

    constexpr bool IsValid() const noexcept {
        if (requirement_id_ == 0) {
            return false;
        }

        if (status_ == SelectionStatus::Selected) {
            return capability_id_ != 0 && reason_ == SelectionReason::Selected;
        }

        return status_ == SelectionStatus::NotSelected &&
               capability_id_ == 0 &&
               reason_ != SelectionReason::None &&
               reason_ != SelectionReason::Selected;
    }

    static constexpr CapabilitySelectionResult Selected(
        CapabilityRequirementId requirement_id,
        CapabilityId capability_id) noexcept {
        return {requirement_id,
                capability_id,
                SelectionStatus::Selected,
                SelectionReason::Selected};
    }

    static constexpr CapabilitySelectionResult NotSelected(
        CapabilityRequirementId requirement_id,
        SelectionReason reason) noexcept {
        return {requirement_id,
                0,
                SelectionStatus::NotSelected,
                reason};
    }

    friend constexpr bool operator==(
        const CapabilitySelectionResult&,
        const CapabilitySelectionResult&) noexcept = default;

private:
    CapabilityRequirementId requirement_id_{};
    CapabilityId capability_id_{};
    SelectionStatus status_{SelectionStatus::NotSelected};
    SelectionReason reason_{SelectionReason::None};
};

} // namespace gcfios::core::capabilities
