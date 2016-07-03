## Rewrite Lite
**构建状态：** [![Build Status](https://img.shields.io/travis/andytimes/rwlite/master.svg)](https://travis-ci.org/andytimes/rwlite)
###简介
* 对 PC 游戏 Rewrite（Visual Art's/Key）进行轻量化、跨平台移植。

### 运行方式
**获取资源文件夹** [**BGM**](https://yunpan.cn/cqE8T3xPTULqR )（提取码：**6a8f**）

将获取的 BGM 文件夹移入源代码目录，执行：

```shell
git submodule update --init
```
获取子模块，之后根据具体平台，参考如下操作：

**Linux** :

* 安装 **SDL2-devel**, **SDL2_mixer-devel** (Ubuntu 中为 **libsdl2-dev** 和 **libsdl2-mixer-dev**)
* 源代码目录执行 `make`
* 运行：`./rewrite`

**Windows** :

* 获取 [SDL2-devel](http://libsdl.org/download-2.0.php) 和 [SDL2_mixer-devel](https://www.libsdl.org/projects/)，安装 mingw
* 编译（以 32 位平台为例） : `mingw32-make -f Makefile.mingw`
* 运行：双击 **rewrite.exe**

**其他平台** :
* 待续 ...

### 音乐信息
* [**BGM.info**](BGM.info) 提供详细信息

### 其它
* 源代码许可证：[**BSD-2-Clause**](LICENSE)
* 资源文件版权归 [**Visual Art's/Key**](http://key.visualarts.gr.jp/) 所有

![](http://r.loli.io/jyAz6z.jpg)
