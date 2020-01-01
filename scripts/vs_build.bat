CALL "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
SET QT_HOME=C:\Users\rasmadeus\Documents\dev\sdk\5.13.0\msvc2017_64
SET BOOST_HOME=C:\Users\rasmadeus\Documents\dev\sdk\boost_1_71_0
SET OUT=C:\Users\rasmadeus\Documents\dev\pro\rapchat\build\out
cmake -G "NMake Makefiles" -DCMAKE_INSTALL_PREFIX=%OUT% -DCMAKE_PREFIX_PATH=%OUT%/find;%QT_HOME%;%BOOST_HOME% %1
cmake --build .
cmake --install .
