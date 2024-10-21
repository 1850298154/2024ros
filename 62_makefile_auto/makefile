######################################################

# hello:  test
# 	echo "hello, \nmakefile!!"
# test:  three
# 	echo "test, \nmakefile!!"
# three: four ; echo "three" 
# four: ; echo "four"

######################################################

# #makefile
# all : func.o main.o  
# 	gcc -o hello.exe func.o main.o
# func.o : func.c  
# 	gcc -o func.o -c func.c
# main.o : main.c  
# 	gcc -o main.o -c main.c

# 59_makefile$ make
# gcc -o func.o -c func.c
# gcc -o main.o -c main.c
# gcc -o hello.exe func.o main.o
# ## 修改 func.c 再编译
# 59_makefile$ make
# gcc -o func.o -c func.c
# gcc -o hello.exe func.o main.o
# ## 什么都不修改
# 59_makefile$ make
# gcc -o hello.exe func.o main.o


# 59_makefile$ make
# gcc -o hello.exe func.o main.o
# z@OS-20230407SLQA:/mnt/h/vs_Community/项目管
# 理/练习/cpp速成/速成c++面向对象/cpp面向对象-补
# 充/2024ros/59_makefile$ ll
# total 28
# drwxrwxrwx 1 z z  4096 Feb 13 16:19 ./
# drwxrwxrwx 1 z z  4096 Feb 13 14:40 ../
# -rwxrwxrwx 1 z z   108 Feb 13 16:17 func.c*
# -rwxrwxrwx 1 z z  1792 Feb 13 16:17 func.o*
# -rwxrwxrwx 1 z z 16800 Feb 13 16:19 hello.exe*    !!!
# -rwxrwxrwx 1 z z    70 Feb 13 16:09 main.c*
# -rwxrwxrwx 1 z z  1544 Feb 13 16:13 main.o*
# -rwxrwxrwx 1 z z   585 Feb 13 16:18 makefile*

# z@OS-20230407SLQA:/mnt/h/vs_Community/项目管
# 理/练习/cpp速成/速成c++面向对象/cpp面向对象-补
# 充/2024ros/59_makefile$ make
# gcc -o hello.exe func.o main.o
# z@OS-20230407SLQA:/mnt/h/vs_Community/项目管
# 理/练习/cpp速成/速成c++面向对象/cpp面向对象-补
# 充/2024ros/59_makefile$ ll
# total 28
# drwxrwxrwx 1 z z  4096 Feb 13 16:21 ./
# drwxrwxrwx 1 z z  4096 Feb 13 14:40 ../
# -rwxrwxrwx 1 z z   108 Feb 13 16:17 func.c*
# -rwxrwxrwx 1 z z  1792 Feb 13 16:17 func.o*
# -rwxrwxrwx 1 z z 16800 Feb 13 16:21 hello.exe*    !!!
# -rwxrwxrwx 1 z z    70 Feb 13 16:09 main.c*
# -rwxrwxrwx 1 z z  1544 Feb 13 16:13 main.o*
# -rwxrwxrwx 1 z z   585 Feb 13 16:18 makefile*

######################################################

# #makefile
# hello.exe all : func.o main.o  
# 	gcc -o hello.exe func.o main.o
# func.o : func.c  
# 	gcc -o func.o -c func.c
# main.o : main.c  
# 	gcc -o main.o -c main.c

# # z@OS-20230407SLQA:/mnt/h/vs_Community/项目管理/练习/cpp速成
# # /速成c++面向对象/cpp面向对象-补充/2024ros/59_makefile$ make
# # make: 'hello.exe' is up to date.

######################################################


target=app
# 获取./目录中所有的.c
src = $(wildcard ./*.c)
# 替换 src中 所有的.c为.o 
obj = $(patsubst ./%.c, ./%.o, $(src) )
cc = gcc
$(target):$(obj)
	# $(cc) $(obj) -o $(target)   # 两者等价
	$(cc) $^ -o $@   			# 两者等价 
%.o:%.c
	$(cc) -c $< -o $@   
# 规则：make clean 执行 删除
# 规则：生成伪目标，不会跟本地文件比较 -f强制删除
.PHONY:clean hello
clean:
	-rm  # 加'-' 执行失败，则忽略这条命令(rm 没有参数，导致执行失败)
	rm $(obj) $(target) -f
# clean: FORCE
# 	-rm  # 加'-' 执行失败，则忽略这条命令(rm 没有参数，导致执行失败)
# 	rm $(obj) $(target) -f
# FORCE:
hello:
	echo "hello, makefile"

