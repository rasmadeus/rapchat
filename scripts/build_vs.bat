call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"

set GTEST_HOME="C:/Users/rasmadeus/Documents/dev/sdk/googletest/out/install/x64-Release"

cmake -G "NMake Makefiles" -DCMAKE_PREFIX_PATH=%GTEST_HOME% -DCMAKE_BUILD_TYPE=Debug %1
cmake --build .
