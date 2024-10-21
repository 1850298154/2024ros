# mkdir lib
gcc func.c -c -o func.o
# ar rcs + 设置静态库名（libMytest.a） + 生成所有的*.o
ar rcs libMyCalc.a *.o

# gcc main.c lib/libMyCalc.a -I./include -o myApp
# gcc main.c -I./include -L ./lib -l MyCalc -o myApp
# gcc main.c ./libMyCalc.a  -o myApp
gcc main.c -L ./  -l MyCalc -o myApp
	# -l 在-L指定的库中，掐头去尾
nm libMyCalc.a      # 查看内容
nm myApp         	# 查看内容


63_gcc$ nm libMyCalc.a      # 查看内容
容

func.o:
                 U _GLOBAL_OFFSET_TABLE_
0000000000000000 T foo
                 U printf
                 U puts
z@OS-20230407SLQA:/mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对
象/cpp面向对象-补充/2024ros/63_gcc$ nm myApp         # 查看内容
0000000000003dc0 d _DYNAMIC
0000000000003fb0 d _GLOBAL_OFFSET_TABLE_
0000000000002000 R _IO_stdin_used
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
000000000000219c r __FRAME_END__
0000000000002028 r __GNU_EH_FRAME_HDR
0000000000004010 D __TMC_END__
0000000000004010 B __bss_start
                 w __cxa_finalize@@GLIBC_2.2.5
0000000000004000 D __data_start
0000000000001120 t __do_global_dtors_aux
0000000000003db8 d __do_global_dtors_aux_fini_array_entry
0000000000004008 D __dso_handle
0000000000003db0 d __frame_dummy_init_array_entry
                 w __gmon_start__
0000000000003db8 d __init_array_end
0000000000003db0 d __init_array_start
0000000000001220 T __libc_csu_fini
00000000000011b0 T __libc_csu_init
                 U __libc_start_main@@GLIBC_2.2.5
0000000000004010 D _edata
0000000000004018 B _end
0000000000001228 T _fini
0000000000001000 t _init
0000000000001080 T _start
0000000000004010 b completed.8061
0000000000004000 W data_start
00000000000010b0 t deregister_tm_clones
0000000000001182 T foo
0000000000001160 t frame_dummy
0000000000001169 T main
                 U printf@@GLIBC_2.2.5
                 U puts@@GLIBC_2.2.5
00000000000010e0 t register_tm_clones