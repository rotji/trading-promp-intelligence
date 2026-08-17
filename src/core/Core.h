#pragma once

#include "core/events/Events.h"
#include "core/execution/Execution.h"
#include "core/foundation/Foundation_Error.h"
#include "core/foundation/Foundation_Result.h"
#include "core/foundation/Foundation_Status.h"
#include "core/foundation/Foundation_Types.h"
#include "core/infrastructure/assertions/Assertions.h"
#include "core/services/logging/Logging.h"
#include "core/system/context/Context.h"
#include "core/system/identity/Identity.h"
#include "core/system/lifecycle/Lifecycle.h"
#include "core/system/versioning/Version.h"

namespace gcfios::core {

// Stable public aggregation boundary for the universal core, events, and
// execution contracts. This header exposes established contracts without
// introducing runtime behavior or client-specific dependencies.

} // namespace gcfios::core
