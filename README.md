![](http://r.loli.io/6Fb2eq.jpg)
## Rewrite Lite
###简介
* 移植 Rewrite 中的 Mapping 小游戏，简化情节，剧情改写。

### 运行方式
**获取资源文件夹 [BGM](https://yunpan.cn/cqE8T3xPTULqR )（提取码：6a8f）**

**首先** :
* 进入源代码目录，在 git 终端执行：

```shell
    git submodule update --init
```
* 之后根据具体平台，执行如下操作：

**Linux** :

* 确保已安装 gcc, make, SDL2_mixer-devel, SDL2-devel
* 源代码目录执行 `make`
* 运行：`./rewrite`

**Windows** :

* 获取 [SDL2-devel](http://libsdl.org/download-2.0.php) 和 [SDL2_mixer-devel](https://www.libsdl.org/projects/)，安装 mingw 或 Visual Studio
* 编译（mingw32 示例） : `mingw32-make -f Makefile.mingw`
* 运行：双击 **rewrite.exe**

### 背景音乐
* **BGM.info** 文件提供详细信息

### 其它
* 源代码许可证：[**BSD-2-Clause**](https://opensource.org/licenses/BSD-2-Clause)
* 资源文件仅供试听，版权归 **Visual Art's/Key** 所有
