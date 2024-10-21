###############################################

# cmake_minimum_required(VERSION 3.0)
# project (hello)
# add_executable(hello main.c func.c)

###############################################

# cmake_minimum_required(VERSION 3.16)
# project(
#     CMakeSunny
    
#     VERSION 1.0
#     DESCRIPTION "A CMake Tutorial"
#     LANGUAGES CXX
# )

# add_executable(
#     add

#     main.cpp
#     add.cpp
# )

###############################################

# cmake_minimum_required(VERSION 3.16)
# project(
#     CMakeSunny
    
#     VERSION 1.0
#     DESCRIPTION "A CMake Tutorial"
#     LANGUAGES CXX
# )

# add_executable(
#     cmlearn

#     main.cpp
# )


# add_subdirectory(math)
# target_link_libraries(
#     cmlearn 
#     PUBLIC 
#     math
# )
# target_include_directories(
#     cmlearn 
#     PUBLIC
#     "${PROJECT_SOURCE_DIR}/math"
# )


###############################################
###############################################
############################################### vscode 

# # Set the minimum version of CMake that can be used
# cmake_minimum_required(VERSION 3.0)
# # Set the project name
# project (HELLO)
# # Add an executable
# add_executable(hello_cmake main.cpp)

# ###############################################

# # Set the minimum version of CMake that can be used
# cmake_minimum_required(VERSION 3.0)
# #project name
# project(SWAP)
# #head file pat
# include_directories( include )
# #source directory files to var
# add_subdirectory( src DIR_SRCS )
# #add executable file
# add_executable(swap_02 ${TEST_MATH})
# #add link library
# target_link_libraries(${FS_BUILD_BINARY_PREFIX}sqrt ${LIBRARIES})

# ###############################################

# # Set the minimum version of CMake that can be used
# cmake_minimum_required(VERSION 3.0)
# #project name
# project(SWAP_LIBRARY)
# #add compile options
# add_compile_options("-Wall -std=c++11")
# # set - 显式的定义变量
# # 语法：set(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE]])

# #set CMAKE_BUILD_TYPE
# set( CMAKE_BUILD_TYPE Debug )
# # set output binary path
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
# ############################################################
# # Create a library
# ############################################################
# #Generate the static library from the library sources
# add_library( swap_library STATIC src/Swap.cpp )
# target_include_directories( swap_lib PUBLIC ${PROJECT_SOURCE_DIR}/include )
# ############################################################
# # Create an executable
# ############################################################
# # Add an executable with the above sources
# add_executable( swap_01 main.cpp )
# # link the new swap_01 target with the swap_lib target
# target_link_libraries( swap_01 swap_liby )


###############################################
###############################################
###############################################


################################################  三 编译多个源文件

# cmake_minimum_required (VERSION 2.8)

# project (demo)

# add_executable(main main.c testFunc.c)

###############################################

# cmake_minimum_required (VERSION 2.8)

# project (demo)

# aux_source_directory(./ SRC_LIST)

# add_executable(main ${SRC_LIST})

###############################################

# cmake_minimum_required (VERSION 2.8)

# project (demo)

# set( SRC_LIST
# 	 ./main.c
# 	 ./testFunc1.c
# 	 ./testFunc.c)

# add_executable(main ${SRC_LIST})

###############################################

# cmake_minimum_required (VERSION 2.8)

# project (demo)

# include_directories (./test_func test_func1)

# aux_source_directory (./test_func SRC_LIST)
# aux_source_directory (./test_func1 SRC_LIST1)

# add_executable (main main.c ${SRC_LIST} ${SRC_LIST1})

################################################  四 项目级的组织结构

# # 父 CMakeLists.txt
# cmake_minimum_required (VERSION 2.8)

# project (demo)

# add_subdirectory (src)

# #子 src/CMakeLists.txt
# aux_source_directory (./ SRC_LIST)

# include_directories (../include)

# add_executable (main ${SRC_LIST})

# set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# ###############################################
# # 上面  父子 等价于 如下
# cmake_minimum_required (VERSION 2.8)

# project (demo)

# set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# aux_source_directory (./src SRC_LIST)

# include_directories (./include)

# add_executable (main ${SRC_LIST})

################################################  五 动态库和静态库的编译控制
# 生成：库文件
cmake_minimum_required (VERSION 3.5)

project (demo)

set (SRC_LIST ${PROJECT_SOURCE_DIR}/testFunc/testFunc.c)

add_library (testFunc_shared SHARED ${SRC_LIST})
add_library (testFunc_static STATIC ${SRC_LIST})

set_target_properties (testFunc_shared PROPERTIES OUTPUT_NAME "testFunc")
set_target_properties (testFunc_static PROPERTIES OUTPUT_NAME "testFunc")

set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


###############################################
# 使用：链接库文件
cmake_minimum_required (VERSION 3.5)

project (demo)


set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set (SRC_LIST ${PROJECT_SOURCE_DIR}/src/main.c)

# find testFunc.h
include_directories (${PROJECT_SOURCE_DIR}/testFunc/inc)

find_library(TESTFUNC_LIB testFunc HINTS ${PROJECT_SOURCE_DIR}/testFunc/lib)

add_executable (main ${SRC_LIST})

target_link_libraries (main ${TESTFUNC_LIB})


################################################  六 条件编译 

# ./CMakeLists.txt
cmake_minimum_required (VERSION 2.8)

project (demo)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_compile_options(-std=c++11 -Wall) 

add_executable(main main.cpp)

# src/CMakeLists.txt
cmake_minimum_required (VERSION 3.5)

add_executable(main1 main1.c)

if (MYDEBUG)
    add_executable(main2 main2.c)
else()
    message(STATUS "Currently is not in debug mode")    
endif()

###############################################
cmake_minimum_required(VERSION 3.5)

project(demo)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

option(WWW1 "print one message" OFF)
option(WWW2 "print another message" OFF)

if (WWW1)
    add_definitions(-DWWW1)
endif()

if (WWW2)
    add_definitions(-DWWW2)
endif()

add_executable(main main.c)

###############################################