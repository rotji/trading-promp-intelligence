#include <cassert>

#include "core/capabilities/CapabilityAuthorization.h"

int main() {
    using gcfios::core::capabilities::AuthorizationReason;
    using gcfios::core::capabilities::AuthorizationStatus;
    using gcfios::core::capabilities::CapabilityAuthorization;
    using gcfios::core::capabilities::CapabilitySelectionResult;
    using gcfios::core::capabilities::SelectionReason;

    constexpr CapabilityAuthorization empty{};
    static_assert(!empty.IsValid());
    static_assert(!empty.IsAuthorized());
    static_assert(empty.Status() == AuthorizationStatus::Denied);

    constexpr CapabilitySelectionResult selected =
        CapabilitySelectionResult::Selected(1001, 2001);

    constexpr CapabilityAuthorization authorized =
        CapabilityAuthorization::Authorized(selected);

    static_assert(authorized.IsValid());
    static_assert(authorized.IsAuthorized());
    static_assert(authorized.Requirement() == 1001);
    static_assert(authorized.Capability() == 2001);
    static_assert(authorized.Status() == AuthorizationStatus::Authorized);
    static_assert(authorized.Reason() == AuthorizationReason::Authorized);

    constexpr CapabilityAuthorization denied =
        CapabilityAuthorization::Denied(
            selected,
            AuthorizationReason::DeniedByAuthority);

    static_assert(denied.IsValid());
    static_assert(!denied.IsAuthorized());
    static_assert(denied.Requirement() == 1001);
    static_assert(denied.Capability() == 2001);
    static_assert(denied.Status() == AuthorizationStatus::Denied);
    static_assert(denied.Reason() == AuthorizationReason::DeniedByAuthority);

    constexpr CapabilitySelectionResult not_selected =
        CapabilitySelectionResult::NotSelected(
            1002,
            SelectionReason::NoCompatibleCapability);

    constexpr CapabilityAuthorization invalid_selection =
        CapabilityAuthorization::Authorized(not_selected);

    static_assert(!invalid_selection.IsAuthorized());
    static_assert(invalid_selection.Status() == AuthorizationStatus::Denied);
    static_assert(invalid_selection.Reason() == AuthorizationReason::SelectionNotValid);

    assert(authorized.IsValid());
    assert(denied.IsValid());
    assert(!invalid_selection.IsAuthorized());

    return 0;
}
