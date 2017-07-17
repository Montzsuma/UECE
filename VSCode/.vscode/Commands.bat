@echo off

REM %1 = ${fileExtname}
REM %2 = TaskName
REM %3 = ${fileDirname}
REM %4 = ${fileBasename}
REM %5 = ${fileBasenameNoExtenion}
REM %6 = OpenGL or ""

cd %3

if %1==.c (
    if %2==Build (
        gcc -o %5 %4
    )
    if %2==Run (
        %5
    )
    if %2==BuildRun (
        gcc -o %5 %4
        %5
    )
)

if {%1}=={.cpp} (
    if {%6}=={} (
        if {%2}=={Build} (
            g++ -o %5 %4
        )
        if {%2}=={Run} (
            {%5}
        )
        if {%2}=={BuildRun} (
            g++ -o %5 %4
            %5
        )
    )
    if {%6}=={OpenGL} (
        if {%2}=={Build} (
            g++ -o %5 %4 -lopengl32 -lglut32 -lglu32 -lwinmm -lgdi32
        )
        if {%2}=={Run} (
            %5
        )
        if {%2}=={BuildRun} (
            g++ -o %5 %4 -lopengl32 -lglut32 -lglu32 -lwinmm -lgdi32
            %5
        )
    )
)

if %1==.cs (
    if %2==Build (
        csc %4
    )
    if %2==Run (
        %5
    )
    if %2==BuildRun (
        csc %4
        %5
    )
)

if %1==.rb (
    if %2==BuildRun (
        ruby %4
    )
)

if %1==.py (
    if %2==BuildRun (
        python %4
    )
)

if %1==.java (
    if %2==Build (
        javac %4
    )
    if %2==Run (
        java %5
    )
    if %2==BuildRun (
        javac %4
        java %5
    )
)
