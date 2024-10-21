# 1、生成与位置无关的代码（生成于位置无关的.c）
# gcc -fPIC -c *.c 
gcc -fPIC -c func.c -o func.o 

# 2、将.o打包成共享库（动态库）
# gcc -shared -I./include libMyCalc.so *.o
gcc -shared -o libMyCalc.so *.o

gcc -o app main.c -L./ -lMyCalc

# export LD_LIBRARY_PATH=/path/to/library:$LD_LIBRARY_PATH

# export LD_LIBRARY_PATH=$(echo $LD_LIBRARY_PATH | sed 's#/path/to/library:##')

export LD_LIBRARY_PATH=/mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/64_gcc:$LD_LIBRARY_PATH

export LD_LIBRARY_PATH=$(echo $LD_LIBRARY_PATH | sed 's#/mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/64_gcc:##')

# z@OS-20230407SLQA:/mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/64_gcc$ echo $LD_LIBRARY_PATH 
# /mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/64_gcc:/mnt/f/ros/ws/devel/lib:/opt/ros/noetic/lib:/home/z/PX4-Autopilot/build/px4_sitl_default/build_gazebo-classic:/home/z/PX4-Autopilot/build/px4_sitl_default/build_gazebo-classic
# z@OS-20230407SLQA:/mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/64_gcc$ ./app 
# void foo() : hello makefile
# modify



# echo  $LD_LIBRARY_PATH
# echo $LD_LIBRARY_PATH
# /mnt/f/ros/ws/devel/lib:/opt/ros/noetic/lib:/home/z/PX4-Autopilot/build/px4_sitl_default/build_gazebo-classic:/home/z/PX4-Autopilot/build/px4_sitl_default/build_gazebo-classic