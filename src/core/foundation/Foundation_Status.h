#pragma once

namespace gcfios::foundation {

enum class Status {
    Success,
    Failure
};

constexpr bool IsSuccess(Status status) noexcept {
    return status == Status::Success;
}

constexpr bool IsFailure(Status status) noexcept {
    return status == Status::Failure;
}

} // namespace gcfios::foundation
