add_executable(Lab2 main.cpp Auto.cpp BinWriter.cpp UI.cpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)