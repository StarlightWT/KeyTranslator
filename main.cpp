#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define ARMDic "armdictionary.txt"

void dictionaryPrint(int ascii, FILE *file);
int main() {
    char key;
    FILE *f;
    while(1)
    {
        key=getch(); //Get the keypress
        if(key==27) break; //If keypress == 27 (esc key) close
        printf("Char: %c\nASCII: %d\n", key, key); //Output the keypress in ascii
        f = fopen(ARMDic, "r");
        dictionaryPrint(key, f);
        fclose(f);
        printf("- - - - - -\n");
    }
    return 0;
    }

void dictionaryPrint(int ascii, FILE *file){
    char read[255], *readASCII;
    while(fgets(read, 255, file) != NULL){
        readASCII = strtok(read, "§");
        if(atoi(readASCII) == ascii) {
            readASCII = strtok(NULL, "§");
            readASCII = strtok(NULL, "§");
            printf("%s: %s", "ARM", readASCII);
        };
    }
}