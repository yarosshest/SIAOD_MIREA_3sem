add_executable(Lab2 main.cpp ReaderSource.cpp Auto.cpp BinWriter.cpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)