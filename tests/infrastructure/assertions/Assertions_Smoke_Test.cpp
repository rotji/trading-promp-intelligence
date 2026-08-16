#include <cassert>

#include "core/infrastructure/assertions/Assertions.h"

int main() {
    using gcfios::core::infrastructure::assertions::Assert;

    Assert(true);
    assert(true);

    return 0;
}
