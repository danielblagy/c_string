@echo off
if not exist "obj" mkdir obj
if not exist "bin" mkdir bin
gcc -c src/mystr.c -o obj/mystr.o
gcc -c src/main.c -o obj/main.o
gcc obj/mystr.o obj/main.o -o bin/program