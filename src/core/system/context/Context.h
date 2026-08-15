#pragma once

#include "core/system/identity/Identity.h"
#include "core/system/versioning/Version.h"

namespace gcfios::core::system::context {

enum class InitializationState {
    Uninitialized,
    Initialized
};

struct Context {
    identity::Identity identity{};
    versioning::Version version{};
    InitializationState initialization_state{InitializationState::Uninitialized};

    constexpr bool IsInitialized() const noexcept {
        return initialization_state == InitializationState::Initialized;
    }
};

} // namespace gcfios::core::system::context
