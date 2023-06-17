@echo off

set QTDIR=C:\Qt\qtcreator-4.11.2\bin
set PATH=%QTDIR%\bin;%PATH%

qmake -project
qmake
make