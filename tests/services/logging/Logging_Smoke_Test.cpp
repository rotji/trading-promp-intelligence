#include <cassert>

#include "core/services/logging/Logging.h"

int main() {
    using namespace gcfios::core::services::logging;

    constexpr LogEntry entry{
        Severity::Warning,
        "foundation",
        "test message"
    };

    static_assert(entry.severity == Severity::Warning);
    static_assert(entry.source != nullptr);
    static_assert(entry.message != nullptr);

    assert(entry.severity == Severity::Warning);
    assert(entry.source != nullptr);
    assert(entry.message != nullptr);

    return 0;
}
