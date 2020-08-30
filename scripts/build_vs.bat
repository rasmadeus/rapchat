call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"

set OUTPUT_ROOT="C:\\Users\\rasmadeus\\Documents\\dev\\pro\\rapchat\\build\\out"
set RAPCHAT_ROOT="C:\\Users\\rasmadeus\\Documents\\dev\\pro\\rapchat\\rapchat"
set GTEST_ROOT="C:\\Users\\rasmadeus\\Documents\\dev\\sdk\\googletest\\out\\install\\x64-Debug"
set BOOST_ROOT="C:\\Users\\rasmadeus\\Documents\\dev\\sdk\\boost_1_74_0"

cmake -G "NMake Makefiles" -DCMAKE_PREFIX_PATH=%GTEST_ROOT%;%BOOST_ROOT% -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=%OUTPUT_ROOT% -DCMAKE_BUILD_TYPE=Debug %RAPCHAT_ROOT%
cmake --build .
