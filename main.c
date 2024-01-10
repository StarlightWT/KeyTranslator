#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <dirent.h>

void dictionaryPrint(int ascii, char fileName[]);
int main()
{
    DIR *dir;
    char key, path[500] = {}, curPath[500] = {};
    struct dirent *dent;

    char dictionaries[50][500];
    int dictionariesLength = 0;
    while (path[0] == '\0')
    {
        printf("Input path to dictionaries:\n");
        scanf("%s", path);
    }

    dir = opendir(path);
    if (dir != NULL)
    {
        size_t length;
        printf("Found dictionaries:\n");
        while ((dent = readdir(dir)) != NULL)
        {
            length = strlen(dent->d_name);
            if (!(strcmp(dent->d_name, ".") == 0 || strcmp(dent->d_name, "..") == 0 || (*dent->d_name) == '.') && (strcmp(dent->d_name + length - 4, ".txt") == 0))
            {
                printf(dent->d_name);
                printf("\n");
                strcpy(dictionaries[dictionariesLength], dent->d_name);
                dictionariesLength++;
            }
        }
    }
    closedir(dir);

    while (1)
    {
        key = getch(); // Get the keypress
        if (key == 27)
            break;                                 // If keypress == 27 (esc key) close
        printf("Char: %c\nASCII: %d\n", key, key); // Output the keypress in ascii
        for (int i = 0; i < dictionariesLength; i++)
        {
            strcpy(curPath, path);
            strcat(curPath, "/");
            dictionaryPrint(key, strcat(curPath, dictionaries[i]));
        }
        printf("- - - - - -\n");
    }
    return 0;
}

void dictionaryPrint(int ascii, char filePath[])
{
    FILE *f;
    f = fopen(filePath, "r");
    char read[255], *readASCII, nazev[100];
    strcpy(nazev, fgets(read, 255, f));
    nazev[strlen(nazev) - 1] = '\0';
    while (fgets(read, 255, f) != NULL)
    {
        readASCII = strtok(read, "§");
        if (atoi(readASCII) == ascii)
        {
            readASCII = strtok(NULL, "§");
            readASCII = strtok(NULL, "§");
            printf("%s: %s", nazev, readASCII);
        };
    }
    fclose(f);
}