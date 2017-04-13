# CoolProp_openmp_test
Test CoolProp High Level API with OpenMP!
A test code of CoolProp's OpenMP support!

Prereqs:
* Python
* git
* A compiler/build system (visula studio, OSX, g++, etc.)

Start a command prompt!!

1. Do a recursive checkout of this example:

git clone --recursive https://github.com/CoolProp/simple_cmake_example

2. Move into the directory

cd test_coolprop_omp

3. Make directories

mkdir build && cd build

4. Run cmake to generate build system

cmake .. -G GENERATOR

where GENERATOR would be "Visual Studio 14 2015 Win64" for Visual Studio 2015, or nothing for the default, or Xcode for Xcode on OSX. see cmakw --help for a list of supported generators on your computer 

5. build!

cmake --build .

6. on my own computer using "Visual Studio 10 2010 Win64" as GENERATOR, the run result is as below:
D:\test_coolprop_omp\build\Debug>main.exe
Unable to load fluid [Acetone] due to error: Cannot load fluid [Acetone:67-64-1] because it is already in library; consi
der enabling the config boolean variable OVERWRITE_FLUIDS
Unable to load fluid [Ammonia] due to error: Cannot load fluid [Ammonia:7664-41-7] because it is already in library; con
sider enabling the config boolean variable OVERWRITE_FLUIDS
Unable to load fluid [Argon] due to error: Cannot load fluid [Argon:7440-37-1] because it is already in library; conside
r enabling the config boolean variable OVERWRITE_FLUIDS
i = 3 H = 692381.288848
i = 8 H = 692381.288848
i = 4 H = 692381.288848
i = 9 H = 692381.288848
i = 5 H = 692381.288848
i = 6 H = 1.#INF00
i = 7 H = 692381.288848
i = 0 H = 692381.288848
i = 1 H = 692381.288848
i = 2 H = 692381.288848

D:\test_coolprop_omp\build\Debug>main.exe
Unable to load fluid [1-Butene] due to error: Cannot load fluid [1-Butene:106-98-9] because it is already in library; co
nsider enabling the config boolean variable OVERWRITE_FLUIDSUnable to load fluid [1-Butene] due to error: Cannot load fl
uid [1-Butene:106-98-9] because it is already in library; consider enabling the config boolean variable OVERWRITE_FLUIDS


i = 0 H = 1.#INF00
i = 3 H = 1.#INF00
i = 1 H = 1.#INF00
i = 4 H = 1.#INF00
i = 2 H = 1.#INF00
i = 5 H = 1.#INF00
i = 8 H = 692381.288848

