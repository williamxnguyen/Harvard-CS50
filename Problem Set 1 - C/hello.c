#include <stdio.h>

int main(void)
{
    printf('hello, world!\n')
}

//Before executing, I am compiling the program (clang) to translate it from source code into machine code. 
//To output a specific file name after compiling , use -- clang -o output_file_name original_file e.g. clang -o hello hello.c
