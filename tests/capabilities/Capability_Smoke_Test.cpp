#include <cassert>

#include "core/capabilities/Capability.h"

using gcfios::core::capabilities::CapabilityDescriptor;

constexpr CapabilityDescriptor kCapability{
    42,
    7,
    {1, 0, 0},
    "example.capability"};

static_assert(kCapability.Id() == 42);
static_assert(kCapability.Kind() == 7);
static_assert(kCapability.Version().major == 1);
static_assert(kCapability.Version().minor == 0);
static_assert(kCapability.Version().patch == 0);
static_assert(kCapability.Name() == "example.capability");
static_assert(kCapability.IsValid());

int main() {
    assert(kCapability.Id() == 42);
    assert(kCapability.Kind() == 7);
    assert(kCapability.Name() == "example.capability");
    assert(kCapability.IsValid());

    constexpr CapabilityDescriptor invalid{0, 0, {1, 0, 0}, ""};
    static_assert(!invalid.IsValid());
    assert(!invalid.IsValid());

    return 0;
}
