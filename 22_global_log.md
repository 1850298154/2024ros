`#include <glog/logging.h>` 是 Google 的日志库（Google Logging Library）的头文件，用于在 C++ 程序中实现高效的日志记录功能。

Google 的日志库提供了丰富的特性，包括但不限于：

1. 灵活的日志级别：支持不同级别的日志记录，如 INFO、WARNING、ERROR、FATAL 等，可以根据需求进行配置。
2. 多线程安全：能够在多线程环境中安全地记录日志。
3. 日志信息格式化：支持日志信息的格式化输出，方便定制和查看日志内容。
4. 日志文件滚动：支持按照文件大小或时间来滚动日志文件，避免单个日志文件过大。
5. 自定义日志处理器：可以自定义日志消息的处理方式，如输出到控制台、写入文件等。
6. 轻量级：对程序运行时的性能影响较小。

以下是一个简单的示例，展示了如何使用 Google 的日志库记录日志：

```cpp
#include <glog/logging.h>

int main(int argc, char* argv[]) {
  // 初始化 Google 日志库
  google::InitGoogleLogging(argv[0]);

  // 设置日志目录
  FLAGS_log_dir = "/path/to/log/directory";

  // 记录日志
  LOG(INFO) << "This is an informational message.";

  return 0;
}
```

在上述示例中，我们首先通过 `google::InitGoogleLogging(argv[0])` 初始化了 Google 日志库，然后设置了日志目录，最后通过 `LOG(INFO)` 记录了一条 INFO 级别的日志。

需要注意的是，在使用 Google 的日志库之前，需要确保已经正确链接了该库，并且在编译时添加了相应的选项。

总之，`#include <glog/logging.h>` 提供了强大而灵活的日志记录功能，可以帮助开发者更好地管理和调试他们的 C++ 程序。


-----------------------------------------------




//log_path  日志存储路径
//process_name  进程名， argv[0]
//最大存储日志大小  单位MB

void errCode::zhuozhi_log_init( const char* log_path, const char* process_name, uint32_t log_size )
{

  google::InitGoogleLogging(process_name);    //初始化log的名字为daqing
  ROS_INFO("path =%s\n",log_path);
  google::SetLogDestination(google::GLOG_INFO, log_path);    //设置输出日志的文件夹，文件夹必须已经存在
  google::SetStderrLogging(google::GLOG_WARNING);
  google::SetLogFilenameExtension("log_");
  FLAGS_colorlogtostderr = true;  // Set log color
  FLAGS_logbufsecs = 0;  // Set log output speed(s)
  FLAGS_max_log_size = log_size;  // Set max log file size
  FLAGS_stop_logging_if_full_disk = true;  // If disk is full

  LOG(INFO) << "hello i am info!";
  LOG(WARNING) << "hello i am warning test";  //输出一个Warning日志
  LOG(ERROR) << "hello i am error test";  //输出一个Error日志
  //google::ShutdownGoogleLogging();
}

void errCode::zhuozhi_log(int logLevel,std::string info)
{
    //错误输出
    LOG(INFO) << info;
}