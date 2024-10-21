---
created: 2024-02-14T16:42:55 (UTC +08:00)
tags: [htop怎么看]
source: https://blog.csdn.net/u010815991/article/details/116082683
author: 
---

# Linux系统状态命令htop详细解释说明_htop怎么看-CSDN博客

> ## Excerpt
> 文章浏览阅读3.2k次，点赞3次，收藏11次。top命令升级版本htophtop的介绍htop是Linux系统中的一个互动的进程查看器,与Linux传统的top比较的话,htop更人性化并且还支持鼠标操作!htop的优势(1) 在htop中，可以垂直和水平滚动列表，查看所有进程和完整的命令行。(2) 在top中，您按下的每个未分配的键都有延迟(尤其是当多键转义序列意外触发时)。(3) htop启动得更快(top似乎在显示任何东西之前会收集一段时间的数据)。(4) 在htop中，您不需要输入进程号来终止进程，而在top中，您需要这样做。_htop怎么看

---
### top命令升级版本htop

-   htop的介绍  
    `htop`是Linux系统中的一个互动的进程查看器,与Linux传统的top比较的话,`htop`更`人性化`并且还`支持鼠标`操作!
-   htop的优势

> (1) 在htop中，可以垂直和水平滚动列表，查看所有进程和完整的命令行。  
> (2) 在top中，您按下的每个未分配的键都有延迟(尤其是当多键转义序列意外触发时)。  
> (3) htop启动得更快(top似乎在显示任何东西之前会收集一段时间的数据)。  
> (4) 在htop中，您不需要输入进程号来终止进程，而在top中，您需要这样做。  
> (5) 在htop中，您不需要输入进程编号或优先级值来重新分配进程，而在top中，您需要这样做。  
> (6) 在htop中，您可以同时杀死多个进程。  
> (7) top更老，因此更容易测试。

这里使用CentOS7.X系统版本为例,使用`yum`下载安装:

```csharp
#安装epel源

yum install epel-release

#安装htop

yum install -y htop

#安装完毕后命令行输入

htop
```

![](https://img-blog.csdnimg.cn/20190501103811440.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM0NjcyMDMz,size_16,color_FFFFFF,t_70)

> 从上面的截图中可以看到,`htop`命令输出总共分成了五个展示区:  
> (1)CPU状态区域  
> (2)整体状态区域  
> (3)内存状态区域  
> (4)进程状态区域  
> (5)管理控制区域

### htop的众多输出信息的详解

htop通过进度条展示每个CPU逻辑核心的使用百分比,并使用不同的颜色进行区分:

-   CPU usage bar

![](https://img-blog.csdnimg.cn/20190501103818280.png)

> 该行主要显示CPU使用情况,htop还为将不同颜色来区分是使用情况:  
> (1)蓝色的表示low-prority(低优先级)使用  
> (2)绿色的表示normal(标准)使用情况  
> (3)红色的表示kernel(内核)使用情况  
> (4)青色的表示virtuality(虚拟性)使用情况

-   **Memory bar**  
    ![Alt text](https://img-blog.csdnimg.cn/20190501103825503.png)

> 该行主要表示内存使用情况，同样的htop使用了不同颜色来区分是使用情况:  
> (1)绿色的表示已经使用内存情况  
> (2)蓝色的表示用于缓冲的内存使用情况  
> (3)黄色的表示用于缓存的内存使用情况

> 该行主要显示交换分区使用情况，当你发现你的`交换分区(swap)已经派上用场`的时候，说明你的物理**内存已经不足**，需要考虑增加内存了。

整体状态区域  
![Alt text](https://img-blog.csdnimg.cn/20190501103830388.png)

> (1)Tasks显示进程总数,当前运行的进程数  
> (2)Load average显示的是系统的1分钟,5分钟,10分钟的平均负载情况  
> (3)Uptime显示系统运行了多长时间

> 进程状态区域  
> PID：表示进程号,是非零正整数  
> USER：发起该进程的用户名  
> PRI：进程优先级  
> NI：(nice)进程的优先级别数值  
> VIRT：进程占用的虚拟内存  
> RES：进程占用的物理内存  
> SHR：进程使用的共享内存  
> S：进程的运行状况
> 
> (1) R 表示正在运行  
> (2) S 表示休眠  
> (3) Z 表示僵死状态  
> (4) N 表示该进程优先值是负数
> 
> CPU%：进程占用的CPU使用率  
> MEM%：此进程占用的物理内存和总内存的百分比  
> TIME%：启动进程后占用CPU的累计时长  
> Command：进程启动的启动命令名称即路径

> 管理控制台  
> F1;查看htop说明  
> F2;htop设定  
> F3;搜索进程  
> F4;进程过滤器  
> F5;显示属性结构  
> F6;折叠或展开(新版本里的),或选择排序方式(旧版本里的)  
> F7; 减少nice值,提高进程优先级  
> F8; 增加nice值,降低进程优先级  
> F9; 可对进程传递信号  
> F10; 退出

F2进入设置界面

-   ![Alt text](https://img-blog.csdnimg.cn/20190501103837181.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM0NjcyMDMz,size_16,color_FFFFFF,t_70)  
    针对每项进行设置可以切换输出的形式

1.  切换主题颜色  
    ![Alt text](https://img-blog.csdnimg.cn/20190501103841885.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM0NjcyMDMz,size_16,color_FFFFFF,t_70)
    
2.  显示选项  
    ![Alt text](https://img-blog.csdnimg.cn/20190501103846499.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM0NjcyMDMz,size_16,color_FFFFFF,t_70)
    
3.  为了更能清楚确认进程和线程的关系  
    按F2进入打开colimns设定  
    ![Alt text](https://img-blog.csdnimg.cn/20190501103851333.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM0NjcyMDMz,size_16,color_FFFFFF,t_70)
    

找到`TGID`后,  
按`F5`安装  
卸载是`F9`  
保存`F10`

-   F3是搜索进程

> 不区分大小写,可输入进程名搜索,

-   F4 是类似于过滤的功能

> 输入的筛选条件会一直保存,可以按`ESC`键清除!


# 2
---
created: 2024-02-14T21:19:17 (UTC +08:00)
tags: [linux htop]
source: https://blog.csdn.net/null_one/article/details/129636102
author: 
---

# Linux工具 - htop详解_linux htop-CSDN博客

> ## Excerpt
> 文章浏览阅读3.5k次，点赞5次，收藏7次。Linux工具 - htop详解_linux htop

---
## htop 是什么

![在这里插入图片描述](https://img-blog.csdnimg.cn/7a6cdc8628e740e184726849e8939f54.png)

**htop是top的升级版,允许用户监视系统上运行的进程及其完整的命令行**。

1.  系统不会自带，若是Ubuntu，sudo apt, 若是Centos， yum 可以安装。根据不过系统来进行安装
2.  支持用户交互，可以通过鼠标来kill进程而不用通过输入其PID，支持用鼠标上下拖动，且不同的颜色代表不同的意思。
3.  允许用户根据CPU，内存和时间间隔对进程进行排序

## htop 的安装

### ubuntu

```bash
sudo apt install htop
```

## htop 使用

![在这里插入图片描述](https://img-blog.csdnimg.cn/cc08e3f9724d42d38fc7dfbdfb695356.png)

### 数字1，2，3 4

数字1，2，3，4分别代表CPU处理器/核，上图是一个四核的处理器

### 数字后中括号中的内容

每一个CPU的总用量情况，注意这条上面会有不同的颜色：  
1\. 蓝色：显示低优先级(low priority)进程使用的CPU百分比。  
2\. 绿色：显示用于普通用户(user)拥有的进程的CPU百分比。  
3\. 红色：显示系统进程(kernel threads)使用的CPU百分比。  
4\. 橙色：显示[IRQ](https://so.csdn.net/so/search?q=IRQ&spm=1001.2101.3001.7020)时间使用的CPU百分比。  
5\. 洋红色(Magenta)：显示Soft IRQ时间消耗的CPU百分比。  
6\. 灰色：显示IO等待时间消耗的CPU百分比。  
7\. 青色：显示窃取时间(Steal time)消耗的CPU百分比

### Mem 和 Swp 中的数字

提供了内存（Memory）和交换（Swap）使用情况。 类似于CPU中的进度条，内存监视也包含具有多种颜色的进度条：  
1\. 绿色：显示内存页面占用的RAM百分比  
2\. 蓝色：显示缓冲区页面占用的RAM百分比  
3\. 橙色：显示缓存页面占用的RAM百分比

### Task thr 等区域

![在这里插入图片描述](https://img-blog.csdnimg.cn/5afcc65a19944cb384368c71dae22036.png)

-   **_第一行 (Tasks, thr, running)_**
    
-   参考上面的屏幕截图，我们在计算机上运行的153个任务(tasks)被分解为449个线程(thread)，其中只有1个进程处于运行(running)状态。
    
-   任务(tasks)是打开的进程总数的代表，但并不是每个打开的进程都在不断消耗CPU。 每个进程都处于几种状态
    
-   R: Running：表示进程(process)正在使用CPU
    
-   S: Sleeping: 通常进程在大多数时间都处于睡眠状态，并以固定的时间间隔执行小检查，或者等待用户输入后再返回运行状态。
    
-   T/S: Traced/Stoped: 表示进程正在处于暂停的状态
    
-   Z:Zombie or defunct:已完成执行但在进程表中仍具有条目的进程。
    
-   **_第二行 Load Average_**
    
-   三个值是指系统在最后1分钟，最近5分钟和最后15分钟的平均负载 （0.56, 0.74, 0.74）
    
-   **_第三行 Uptime_**
    
-   表示这个系统一共运行了多长的时间，图中是运行了两个小时五十一分钟
    

### 下半部分

![在这里插入图片描述](https://img-blog.csdnimg.cn/bc7a546ecc53496e829d3ff11fda4bd9.png)

-   PID – 描述进程的ID号
-   USER – 描述进程的所有者（谁跑的）
-   PRI – 描述Linux内核查看的进程优先级
-   NI – 描述由用户或root重置的进程优先级
-   VIRT – 它描述进程正在使用的虚拟内存 （virtual memory）
-   RES – 描述进程正在消耗的物理内存（physical memory）
-   SHR – 描述进程正在使用的共享内存（shared memory）
-   S – 描述流程的当前状态 (state)
-   CPU％ – 描述每个进程消耗的CPU百分比
-   MEM％ – 描述每个进程消耗的内存百分比
-   TIME+ – 进程占用的CPU时长
-   Command –它与每个进程并行显示完整的命令执行 (比如/usr/lib/R)

### 一些快捷键

u – 用于显示特定用户拥有的所有进程。

P –用于基于高CPU消耗对进程进行排序。

M –用于基于高内存消耗对进程进行排序。

T –用于根据时间段对过程进行排序。

h –用于打开帮助窗口并查看此处未提及的更多快捷方式。
