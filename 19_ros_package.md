`#include <ros/package.h>` 是 ROS（Robot Operating System）中的一个头文件，用于获取 ROS 包的路径信息。

ROS 是一个开源机器人操作系统，常用于机器人软件开发。ROS 中的软件以“包”（package）的形式组织，每个包包含了相应的节点、消息、服务等内容。使用 `ros::package` 头文件中提供的函数可以获取 ROS 包的相关信息，例如包名、包的路径等。

常用的 `ros::package` 函数如下：

- `ros::package::getPath()`：获取指定 ROS 包的路径。
- `ros::package::getPackagePath()`：获取所有已加载的 ROS 包的路径。

例如，以下代码展示了如何使用 `ros::package::getPath()` 函数获取当前 ROS 包的路径：

```cpp
#include <ros/package.h>
#include <iostream>
int main(int argc, char** argv) {
    ros::init(argc, argv, "my_package");
    std::string package_path = ros::package::getPath("my_package");
    std::cout << "my_package path: " << package_path << std::endl;
    return 0;
}
```

上述代码中，我们通过调用 `ros::package::getPath()` 函数并传入当前 ROS 包的名称 `"my_package"`，获取了当前 ROS 包的完整路径，并将其打印在终端上。