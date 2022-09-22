enable_testing()
include(GoogleTest)

add_executable(tests1Lab tests.cpp)
target_link_libraries(tests1Lab GTest::gtest_main)

gtest_discover_tests(tests1Lab)