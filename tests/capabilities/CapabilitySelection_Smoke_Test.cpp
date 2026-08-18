#include <cassert>

#include "core/capabilities/CapabilitySelection.h"

int main() {
    using gcfios::core::capabilities::CapabilitySelectionResult;
    using gcfios::core::capabilities::SelectionReason;
    using gcfios::core::capabilities::SelectionStatus;

    constexpr CapabilitySelectionResult empty{};
    static_assert(!empty.IsValid());
    static_assert(!empty.IsSelected());
    static_assert(empty.Status() == SelectionStatus::NotSelected);

    constexpr CapabilitySelectionResult selected =
        CapabilitySelectionResult::Selected(1001, 2001);

    static_assert(selected.IsValid());
    static_assert(selected.IsSelected());
    static_assert(selected.Requirement() == 1001);
    static_assert(selected.Capability() == 2001);
    static_assert(selected.Status() == SelectionStatus::Selected);
    static_assert(selected.Reason() == SelectionReason::Selected);

    constexpr CapabilitySelectionResult none =
        CapabilitySelectionResult::NotSelected(
            1002,
            SelectionReason::NoCompatibleCapability);

    static_assert(none.IsValid());
    static_assert(!none.IsSelected());
    static_assert(none.Requirement() == 1002);
    static_assert(none.Capability() == 0);
    static_assert(none.Status() == SelectionStatus::NotSelected);
    static_assert(none.Reason() == SelectionReason::NoCompatibleCapability);

    constexpr CapabilitySelectionResult ambiguous =
        CapabilitySelectionResult::NotSelected(
            1003,
            SelectionReason::AmbiguousCandidates);

    static_assert(ambiguous.IsValid());
    static_assert(!ambiguous.IsSelected());

    assert(selected.IsValid());
    assert(none.IsValid());
    assert(ambiguous.IsValid());

    return 0;
}
