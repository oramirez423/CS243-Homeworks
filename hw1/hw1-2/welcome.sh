#!/bin/bash
#Omar Ramirez-Chio

echo My home path is: $HOME
echo Files in my HOME:
ls -ltr $HOME

cd
mkdir tmp$$
cd tmp$$
mkdir Courses
cd Courses
mkdir cs243
cd
echo My tmp folder: $(ls -R tmp$$)
echo 

echo Translation steps: Preprocessing, compilation, assembly, and linking 
echo Warning flags required for gcc in this course: -Wall -Wextra -pedantic
echo C dialect flags required for gcc in this course: -std=c99
echo Debug flags required for gcc in this course: -ggdb
echo LoginId: 'whoami'
