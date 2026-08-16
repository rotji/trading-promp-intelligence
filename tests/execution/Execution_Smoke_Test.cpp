#include <cassert>

#include "core/execution/Execution.h"

int main() {
    using gcfios::core::execution::ExecutionContract;
    using gcfios::core::execution::ExecutionId;
    using gcfios::core::execution::ExecutionIntent;
    using gcfios::core::execution::ExecutionState;

    constexpr ExecutionId id = 42;
    constexpr ExecutionContract contract{
        id,
        ExecutionIntent::Execute,
        ExecutionState::Created};

    static_assert(contract.Id() == id);
    static_assert(contract.Intent() == ExecutionIntent::Execute);
    static_assert(contract.State() == ExecutionState::Created);

    assert(contract.Id() == id);
    assert(contract.Intent() == ExecutionIntent::Execute);
    assert(contract.State() == ExecutionState::Created);

    return 0;
}
