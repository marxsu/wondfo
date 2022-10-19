#################################################################################################
## File created by QxEntityEditor 1.2.6 (2022/10/18 16:53) : please, do NOT modify this file ! ##
#################################################################################################

cmake_minimum_required(VERSION 3.1)

project(LBP LANGUAGES CXX)

if(NOT TARGET QxOrm)
   add_subdirectory("D:/QxEntityEditor/QxOrmDll/" ./QxOrm)
endif() # NOT TARGET QxOrm

include("D:/QxEntityEditor/QxOrmDll/QxOrm.cmake")

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_DEBUG_POSTFIX "d")

set(LBP_HEADERS
    ./include/LBP_precompiled_header.gen.h
    ./include/LBP_export.gen.h
    ./include/history.gen.h
    ./include/sample.gen.h
    ./custom/include/history.h
    ./custom/include/sample.h
   )

if(_QX_UNITY_BUILD)

   set(LBP_SRCS ./src/LBP_all.gen.cpp)

else() # _QX_UNITY_BUILD

   set(LBP_SRCS
       ./src/history.gen.cpp
       ./src/sample.gen.cpp
       ./custom/src/history.cpp
       ./custom/src/sample.cpp
       ./src/LBP_main.gen.cpp
      )

endif() # _QX_UNITY_BUILD

add_library(LBP SHARED ${LBP_SRCS} ${LBP_HEADERS})

target_compile_definitions(LBP PRIVATE -D_BUILDING_LBP)

if(COMMAND target_precompile_headers)
   target_precompile_headers(LBP PRIVATE ./include/LBP_precompiled_header.gen.h)
endif() # (COMMAND target_precompile_headers)

target_link_libraries(LBP ${QX_LIBRARIES} QxOrm)

set_target_properties(LBP PROPERTIES
                      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      ARCHIVE_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      ARCHIVE_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                     )

qx_auto_source_group("${LBP_SRCS};${LBP_HEADERS}")
