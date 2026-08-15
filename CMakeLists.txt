cmake_minimum_required(VERSION 3.20)

project(GCFIOS VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(gcfios_core INTERFACE)

target_include_directories(gcfios_core
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

enable_testing()

add_executable(gcfios_foundation_smoke_test
    tests/foundation/Foundation_Smoke_Test.cpp
)

target_link_libraries(gcfios_foundation_smoke_test
    PRIVATE
        gcfios_core
)

add_test(
    NAME gcfios_foundation_smoke_test
    COMMAND gcfios_foundation_smoke_test
)

add_executable(gcfios_identity_smoke_test
    tests/system/identity/Identity_Smoke_Test.cpp
)

target_link_libraries(gcfios_identity_smoke_test
    PRIVATE
        gcfios_core
)

add_test(
    NAME gcfios_identity_smoke_test
    COMMAND gcfios_identity_smoke_test
)

add_executable(gcfios_version_smoke_test
    tests/system/versioning/Version_Smoke_Test.cpp
)

target_link_libraries(gcfios_version_smoke_test
    PRIVATE
        gcfios_core
)

add_test(
    NAME gcfios_version_smoke_test
    COMMAND gcfios_version_smoke_test
)
