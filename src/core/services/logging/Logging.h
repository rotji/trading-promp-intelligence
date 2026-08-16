#pragma once

namespace gcfios::core::services::logging {

enum class Severity {
    Trace,
    Debug,
    Info,
    Warning,
    Error,
    Critical
};

struct LogEntry {
    Severity severity{Severity::Info};
    const char* source{};
    const char* message{};
};

} // namespace gcfios::core::services::logging
