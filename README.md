# Native Scripting API

## Introduction

Native Scripting API is an open source library written in c++. It provides a simple API for creating shared libraries, extracting functions from shared libraries, creating functions pointers and managing life cycle.

Native Scripting API only supports linux and mac at present.

Native Scripting is licensed under the LGPLv3.

|  Platform  |Build Status|
|:----------:|:-----:|
| Linux & Mac| PreRelease |
## Compiling from source

0. Install dependencies.
    * Ensure that you have CMake and git installed and accessible from shell.
    * Optionally install clang-format to get5 a nicely formatted code.
1. Open a shell which provides git and clone this repository
    ```git
    git clone https://github.com/CheralaSaiteja/NativeScripting.git
    ```
2. cd into cloned directory.
3. Create a  build environment with cmake

    **Linux**

    *For compiling with tests*
    ```cmake
    $ cmake -DBUILD_TESTS=ON -S . -B build/
    $ cd build/
    $ make
    ```
    *For compiling without tests set -DBUILD_TESTS=OFF*
    ```cmake
    $ cmake -DBUILD_TESTS=OFF -S . -B build/
    $ cd build/
    $ make
    ```

## Using Native Scripting

See the [documentation](https://github.com/CheralaSaiteja/NativeScripting/blob/master/Documentation.md) for tutorials, guides and the API reference.

## Contributing to Native Scripting

See the [contribution guide]() for more information.

## Reporting bugs
