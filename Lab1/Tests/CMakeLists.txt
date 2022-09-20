enable_testing()
include(GoogleTest)

add_executable(tests tests.cpp)
target_link_libraries(tests GTest::gtest_main)

gtest_discover_tests(tests)