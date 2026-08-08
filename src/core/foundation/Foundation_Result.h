#pragma once

#include "Foundation_Error.h"
#include "Foundation_Status.h"

namespace gcfios::foundation {

struct Result {
    Status status{Status::Success};
    Error error{};

    constexpr bool Succeeded() const noexcept {
        return IsSuccess(status);
    }

    constexpr bool Failed() const noexcept {
        return IsFailure(status);
    }

    static constexpr Result Success() noexcept {
        return {Status::Success, {}};
    }

    static Result Failure(int code, const char* message) {
        return {Status::Failure, {code, message ? message : ""}};
    }
};

} // namespace gcfios::foundation
