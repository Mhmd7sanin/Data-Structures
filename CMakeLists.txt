cmake_minimum_required(VERSION 3.16)

project(algolib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# =========================
# Library (header-only)
# =========================
add_library(algolib INTERFACE)

target_include_directories(algolib INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(MSVC)
    target_compile_options(algolib INTERFACE /W4)
else()
    target_compile_options(algolib INTERFACE -Wall -Wextra -Wpedantic)
endif()

# =========================
# TESTS (auto-scan folder)
# =========================
option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    enable_testing()

    file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp
    )

    foreach(test_file ${TEST_SOURCES})
        get_filename_component(test_name ${test_file} NAME_WE)

        add_executable(${test_name} ${test_file})
        target_link_libraries(${test_name} PRIVATE algolib)

        add_test(NAME ${test_name} COMMAND ${test_name})
    endforeach()
endif()

# =========================
# EXAMPLES
# =========================
option(BUILD_EXAMPLES "Build examples" ON)

if(BUILD_EXAMPLES)
    file(GLOB_RECURSE EXAMPLE_SOURCES CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp
    )

    foreach(example_file ${EXAMPLE_SOURCES})
        get_filename_component(example_name ${example_file} NAME_WE)

        add_executable(${example_name} ${example_file})
        target_link_libraries(${example_name} PRIVATE algolib)
    endforeach()
endif()

# =========================
# BENCHMARKS
# =========================
option(BUILD_BENCHMARKS "Build benchmarks" OFF)

if(BUILD_BENCHMARKS)
    file(GLOB_RECURSE BENCH_SOURCES CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/benchmarks/*.cpp
    )

    foreach(bench_file ${BENCH_SOURCES})
        get_filename_component(bench_name ${bench_file} NAME_WE)

        add_executable(${bench_name} ${bench_file})
        target_link_libraries(${bench_name} PRIVATE algolib)
    endforeach()
endif()