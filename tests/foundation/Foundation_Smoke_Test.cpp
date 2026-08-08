#include <cassert>

#include "core/foundation/Foundation_Status.h"

int main() {
    using gcfios::foundation::IsFailure;
    using gcfios::foundation::IsSuccess;
    using gcfios::foundation::Status;

    assert(IsSuccess(Status::Success));
    assert(IsFailure(Status::Failure));
    assert(!IsFailure(Status::Success));
    assert(!IsSuccess(Status::Failure));

    return 0;
}
