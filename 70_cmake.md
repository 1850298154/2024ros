# 6.2	语法特性介绍
基本语法格式：指令(参数 1 参数 2...)
参数使用括弧括起
参数之间使用空格或分号分开
指令是大小写无关的，参数和变量是大小写相关的

set(HELLO hello.cpp)
add_executable(hello main.cpp hello.cpp)
ADD_EXECUTABLE(hello main.cpp ${HELLO})



## 6.3.1	重要指令
cmake_minimum_required - 指定CMake的最小版本要求
 
微信公众号 ：VSCode bilibili ：xiaobing1016
 
语法： cmake_minimum_required(VERSION versionNumber [FATAL_ERROR])


project - 定义工程名称，并可指定工程支持的语言
语法： project(projectname [CXX] [C] [ Java])


set - 显式的定义变量
语法：set(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE]])


include_directories - 向工程添加多个特定的头文件搜索路径 --->相当于指定g++编译器的-I参数语法： include_directories([AFTER|BEFORE] [SYSTEM] dir1 dir2 ...)


link_directories - 向工程添加多个特定的库文件搜索路径 --->相当于指定g++编译器的-L参数语法： link_directories(dir1 dir2 ...)


add_library - 生成库文件
语法： add_library(libname [SHARED|STATIC|MODULE] [EXCLUDE_FROM_ALL] source1 source2 ... sourceN)


add_compile_options - 添加编译参数语法：add_compile_options(


1	# 添加编译参数 -Wall -std=c++11 -O2
2	add_compile_options(-Wall -std=c++11 -O2)

- 生成可执行文件
语法：add_executable(exename source1 source2 ... sourceN)

 

配套视频bilibili首发：https://b23.tv/tWqKrC
 

第 25 页，共 30 页
 

 
作者：xiaobing
商务邮箱：zqh0102@foxmail.com
 
微信公众号 ：VSCode bilibili ：xiaobing1016
 

	1	# 编译main.cpp生成可执行文件main
2	add_executable(main main.cpp)	
target_link_libraries - 为 target 添加需要链接的共享库 --->相同于指定g++编译器-l参数语法： target_link_libraries(target library1<debug | optimized> library2...)

1	# 将hello动态库文件链接到可执行文件main
2	target_link_libraries(main hello)


add_subdirectory - 向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制存放的位置
语法： add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL])

1	# 添加src子目录，src中需有一个CMakeLists.txt
2	add_subdirectory(src)


aux_source_directory - 发现一个目录下所有的源代码文件并将列表存储在一个变量中，这个指令临时被用来自动构建源文件列表
语法： aux_source_directory(dir VARIABLE)

1	# 定义SRC变量，其值为当前目录下所有的源代码文件
2	aux_source_directory(. SRC)
3	# 编译SRC变量所代表的源代码文件，生成main可执行文件
4	add_executable(main ${SRC})



6.3.2	CMake常用变量 CMAKE_C_FLAGS gcc编译选项 CMAKE_CXX_FLAGS g++编译选项

1	# 在CMAKE_CXX_FLAGS编译选项后追加-std=c++11
2	set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

CMAKE_BUILD_TYPE 编译类型(Debug, Release)

1	# 设定编译类型为debug，调试时需要选择debug
2	set(CMAKE_BUILD_TYPE Debug)
3	# 设定编译类型为release，发布时需要选择release
4	set(CMAKE_BUILD_TYPE Release)


CMAKE_BINARY_DIR PROJECT_BINARY_DIR
_BINARY_DIR
	1.	这三个变量指代的内容是一致的。xiaobing
2.	如果是 in source build，指的就是工程顶层目录。
3.	如果是 out-of-source 编译,指的是工程编译发生的目录。
 
配套视频bilibili首发：https://b23.tv/tWqKrC
 
第 26 页，共 30 页
 

 
作者：xiaobing
商务邮箱：zqh0102@foxmail.com
 
微信公众号 ：VSCode bilibili ：xiaobing1016
 
4. PROJECT_BINARY_DIR 跟其他指令稍有区别，不过现在，你可以理解为他们是一致的。
CMAKE_SOURCE_DIR PROJECT_SOURCE_DIR
_SOURCE_DIR
1.	这三个变量指代的内容是一致的,不论采用何种编译方式,都是工程顶层目录。
2.	也就是在 in source build时,他跟 CMAKE_BINARY_DIR 等变量一致。
3.	PROJECT_SOURCE_DIR 跟其他指令稍有区别,现在,你可以理解为他们是一致的。


CMAKE_C_COMPILER：指定C编译器 CMAKE_CXX_COMPILER：指定C++编译器
EXECUTABLE_OUTPUT_PATH：可执行文件输出的存放路径 LIBRARY_OUTPUT_PATH：库文件输出的存放路径
6.4	CMake编译工程
CMake目录结构：项目主目录存在一个CMakeLists.txt文件
两种方式设置编译规则：
1.	包含源文件的子文件夹包含CMakeLists.txt文件，主目录的CMakeLists.txt通过add_subdirectory添加子目录即可；
2.	包含源文件的子文件夹未包含CMakeLists.txt文件，子目录编译规则体现在主目录的
CMakeLists.txt中；
6.4.1	编译流程
在 linux 平台下使用 CMake 构建C/C++工程的流程如下:
手动编写 CMakeLists.txt。
执行命令 cmake PATH 生成 Makefile ( PATH 是顶层CMakeLists.txt 所在的目录 )。执行命令make 进行编译。
