## Rewrite Lite [![Build Status](https://api.travis-ci.org/andytimes/rwlite.svg?branch=master)](https://travis-ci.org/andytimes/rwlite)
### 简介
1. Rewrite Lite 是 PC 游戏 Rewrite 的一个跨平台简化版本，目前的版本是一个演示版本。

### 运行方式

下载 [BGM文件夹](https://github.com/andytimes/rwlite/releases/download/v0.0.3/BGM.zip) 并解压到源代码目录，执行：

```sh
git submodule update --init
```

之后参考如下操作（仅介绍 Linux 平台）：

**Linux** :

* 安装 SDL2 和 SDL2-Mixer 开发工具：
    * Fedora: `sudo dnf install SDL2-devel SDL2_mixer-devel`
    * Ubuntu: `sudo apt-get install libsdl2-dev libsdl2-mixer-dev`
* 编译代码 `make`
* 运行程序：`./rewrite`

### 音乐信息
* [**BGM.info**](BGM.info) 提供详细信息

### 其它
* 源代码许可证：[**BSD-2-Clause**](LICENSE)
* 资源文件提取自游戏档案，版权为 [**Visual Art's/Key**](http://key.visualarts.gr.jp/) 所有

![](http://r.loli.io/jyAz6z.jpg)
