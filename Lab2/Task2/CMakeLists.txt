add_executable(Lab2 main.cpp ReaderSource.cpp Auto.cpp)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Source.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})