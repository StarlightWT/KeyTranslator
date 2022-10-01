#include <stdio.h>
#include <conio.h>

int main() {
    char key;
    while(1)
    {
        key=getch(); //Get the keypress
        printf("%d\n", key); //Output the keypress in ascii
        if(key==27) break; //If keypress == 27 (esc key) close
    }
    return 0;
    }