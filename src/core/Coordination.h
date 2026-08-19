#pragma once

#include "core/events/Events.h"
#include "core/execution/ExecutionDispatch.h"

namespace gcfios::core {

// Contract-only aggregation boundary for Universal Core coordination.
// This header introduces no runtime behavior, ownership, or orchestration.
struct Coordination final {
    using EventContract = events::EventHeader;
    using ExecutionDispatchContract = execution::ExecutionDispatch;
};

} // namespace gcfios::core
