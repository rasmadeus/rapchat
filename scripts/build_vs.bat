call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"

set BOOST_HOME=C:\Users\rasmadeus\Documents\dev\sdk\boost_1_71_0
set QT_HOME=C:\Users\rasmadeus\Documents\dev\sdk\5.13.0\msvc2017_64
set GTEST_HOME=C:\Users\rasmadeus\Documents\dev\sdk\googletest\out\install\x64-Debug

cmake -G "NMake Makefiles" -DCMAKE_PREFIX_PATH=%QT_HOME%;%BOOST_HOME%;%GTEST_HOME% -DCMAKE_BUILD_TYPE=Debug %1
cmake --build .
