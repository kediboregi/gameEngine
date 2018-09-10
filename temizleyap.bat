cd C:\projeler\gameEngine
cd build\bin\windows\86
del gameEngine.exe
cd ..\..\..\..\
mingw32-make clean
mingw32-make
cd build\bin\windows\86
gameEngine.exe
cd ..\..

pause