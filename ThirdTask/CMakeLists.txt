add_executable(ThirdTask main.cpp BinWriter.cpp Auto.cpp HashMap/HeshTable.cpp Data.cpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/txt.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)