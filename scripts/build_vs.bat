call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"

set GTEST_ROOT="C:\\Users\\rasmadeus\\Documents\\dev\\sdk\\googletest\\out\\install\\x64-Debug"
set BOOST_ROOT="C:\\Users\\rasmadeus\\Documents\\dev\\sdk\\boost_1_74_0"

cmake -G "NMake Makefiles" -DCMAKE_PREFIX_PATH=%GTEST_ROOT%;%BOOST_ROOT% -DCMAKE_BUILD_TYPE=Debug %1
cmake --build .
