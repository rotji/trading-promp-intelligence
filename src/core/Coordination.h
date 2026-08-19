#pragma once

#include "core/events/Event.h"
#include "core/execution/ExecutionDispatch.h"

namespace gcfios::core {

// Contract-only aggregation boundary for Universal Core coordination.
// This header intentionally introduces no runtime behavior or ownership.
struct Coordination {
    using EventContract = events::Event;
    using ExecutionDispatchContract = execution::ExecutionDispatch;
};

} // namespace gcfios::core
