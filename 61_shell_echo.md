在 shell 脚本中，可以使用 `echo` 命令来进行回显。`echo` 命令用于在终端输出文本或变量的内容。

以下是几种常见的回显方式：

1. 固定文本回显：
```bash
echo "Hello, World!"  # 输出 Hello, World!
```

2. 变量回显：
```bash
name="Alice"
echo "My name is $name"  # 输出 My name is Alice
```

3. 多行回显：
```bash
echo "Line 1"
echo "Line 2"
echo "Line 3"
# 输出：
# Line 1
# Line 2
# Line 3
```

4. 引用回显（保留原样输出）：
```bash
echo "This is a \$variable"  # 输出 This is a $variable
```

注意，根据不同的 shell 环境，`echo` 命令可能会有些许差异。上述示例适用于常见的 Bash shell。在某些情况下，可能需要使用不同的选项或其他命令来实现特定的回显需求。

另外，为了在脚本中展示回显结果，可以将脚本保存为 `.sh` 后缀的文件，并确保脚本具有可执行权限（可以使用 `chmod +x script.sh` 命令赋予执行权限）。然后在终端中执行该脚本，即可看到回显结果。

# set -x

在 shell 脚本中，可以使用 `set -x` 命令来启用调试模式，这会导致 shell 在执行每个命令之前都会显示该命令。这样可以帮助调试脚本并查看每个命令的执行情况。

示例：
```bash
#!/bin/bash
set -x

echo "Start of the script"

date

ls -l

echo "End of the script"
```

在上面的示例中，`set -x` 命令用于启用调试模式。当执行这个脚本时，除了脚本本身输出的内容外，还会显示每个命令的执行情况，例如 `+ echo "Start of the script"`、`+ date`、`+ ls -l` 等。

请注意，在调试完成后，记得将 `set -x` 命令从脚本中移除，以免在正常运行时产生额外的输出。