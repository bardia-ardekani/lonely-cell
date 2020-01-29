#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include"external.h"

int start();

int main()
{
    system("CLS");
    int n , m;
    FILE * new = fopen("load.txt" , "w");
    FILE * mood = fopen("mood.txt" , "r");
    n = start();
    switch (n)
    {
    case 1:
        fprintf(new , "0");
        fclose(new);
        fclose(mood);
        system("onePlayerGame.exe");
        break;
    case 2:
        fprintf(new , "0");
        fclose(new);
        fclose(mood);
        system("twoPlayerGame.exe");
        break;
    case 3:
        fprintf(new , "1\n");
        fscanf(mood , "%d" , &m);
        printf("%d" , m);
        fclose(new);
        fclose(mood);
        switch (m)
        {
        case 1:
            system("onePlayerGame.exe");
            break;

        case 2:
            system("twoPlayerGame.exe");
            break;
        }
        break;
    case 5:
        system("mapEditor.exe");
        break;
    }
    return 0;
}
