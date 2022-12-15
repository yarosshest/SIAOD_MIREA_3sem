add_executable(
        ThirdTask
        main.cpp
        BinWriter/BinWriter.cpp
        Auto.cpp
        HashMap/HeshTable.cpp
#        HashMap/testHeshT.cpp
        Manager/Manager.cpp
        )
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/txt.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)