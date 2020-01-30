#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include"twoPlayer.h"
/*
#include"map2.h"
#include"linkedlist2.h"
#include"insertPlayer2.h"
#include"movement2.h"
#include"sideFunc2.h"
#include"energy&split2.h"
*/

int main()
{
    int n , s;
    struct player1 * p1 = NULL;
    struct player1 * p2 = NULL;
    srand(time(NULL));

    FILE *ptr;

    FILE *loads = fopen("load.txt" , "r");
    if(loads == NULL){ printf("ERROR!"); exit(-1); }
    fscanf(loads , "%d" , &s);
    fclose(loads);

    if( s == 0)
    {
       ptr = fopen("map" , "rb");
       if(ptr == NULL){ printf("ERROR!"); exit(-1); }
    } else {
       ptr = fopen("savedMap" , "rb");
       if(ptr == NULL){ printf("ERROR!"); exit(-1); }
    }

    fread(&n , sizeof(int) , 1 , ptr);
    char map[n][n];
    int flag[n][n] , arrEnergy[n][n];

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
        {
            fread(&map[i][j] , sizeof(char) , 1 , ptr); flag[i][j] = 0;
            if(map[i][j] == '1') {arrEnergy[i][j] = 100;}
            else {arrEnergy[i][j] = -1;}
        }

    p1 = load1(p1 , n , flag , map , arrEnergy , 2 , 1);
    p2 = load2(p2 , n , flag , map , arrEnergy , 2 , 2);
    system("CLS");
    printMap(n , map , arrEnergy);
    insertCellPlayer1(p1 , n , map);
    insertCellPlayer1(p2 , n , map);

    for(int i = 1 ; i > 0 ; i++)
    {
        if( i % 2 == 1)
        {
            printf("player 1 it is your turn : \n");
            int game , move , x , y , xr , yr;
            char name[20];
            printf("[1]Move\n[2]Split a cell\n[3]Boost energy\n[4]Save\n[5]Exit\n[6]show cells\n");
            printList(&p1 , n);
            printf("\nSelect a menu : ");
            scanf("%d" , &game);

            switch (game)
            {
            case 1:
                printf("choose a cell?\n");
                printf("name : "); scanf("%s" , name);
                printf("X : "); scanf("%d" , &x);
                printf("Y : "); scanf("%d" , &y);
                arrayMode(&x , &y , n);

                printf("[1]North\n[2]South\n[3]Northeast\n[4]Northwest\n[5]Southeast\n[6]Southwest\nChoose an option : ");
                scanf("%d" , &move);
                switch (move)
                {
                case 1:
                    moveNorth(n , map , flag , name , x , y , p1);
                    break;
                case 2:
                    moveSouth(n , map , flag , name , x , y , p1);
                    break;
                case 3:
                    moveNortheast(n , map , flag , name , x , y , p1);
                    break;
                case 4:
                    moveNorthwest(n , map , flag , name , x , y , p1);
                    break;
                case 5:
                    moveSoutheast(n , map , flag , name , x , y , p1);
                    break;
                case 6:
                    moveSouthwest(n , map , flag , name , x , y , p1);
                    break;
                } ///movement case ended here...
                break;

            case 2: ///split a cell
                printf("choose a cell?\n");
                printf("name : "); scanf("%s" , name);
                printf("X : "); scanf("%d" , &x);
                printf("Y : "); scanf("%d" , &y);
                arrayMode(&x , &y , n);
                p1 = split(n , flag , map , p1 , name , x , y , 1);
                break;
            case 3: ///boost energy
                printf("choose a cell?\n");
                printf("name : "); scanf("%s" , name);
                printf("X : "); scanf("%d" , &x);
                printf("Y : "); scanf("%d" , &y);
                arrayMode(&x , &y , n);
                boostEnergy(n , arrEnergy , map , p1 , name , x , y);
                break;
            case 4:
                save(p1 , p2 , 2 , n , arrEnergy , map);
                break;
            case 5:
                return -1;
                break;
            case 6:
                printList(&p1 , n);
                i--;
                Sleep(5000);
                break;
            }
            Sleep(500);
            system("CLS");
            printMap(n , map , arrEnergy);
            insertCellPlayer1(p1 , n , map);
            insertCellPlayer1(p2 , n , map);
        }///end of player 1
        else{
            printf("player 2 it is your turn : \n");
            int game , move , x , y , xr , yr;
            char name[20];
            printf("[1]Move\n[2]Split a cell\n[3]Boost energy\n[4]Save\n[5]Exit\n[6]show cells\n");
            printList(&p2 , n);
            printf("\nSelect a menu : ");
            scanf("%d" , &game);

            switch (game)
            {
            case 1:
                printf("choose a cell?\n");
                printf("name : "); scanf("%s" , name);
                printf("X : "); scanf("%d" , &x);
                printf("Y : "); scanf("%d" , &y);
                arrayMode(&x , &y , n);

                printf("[1]North\n[2]South\n[3]Northeast\n[4]Northwest\n[5]Southeast\n[6]Southwest\nChoose an option : ");
                scanf("%d" , &move);
                switch (move)
                {
                case 1:
                    moveNorth(n , map , flag , name , x , y , p2);
                    break;
                case 2:
                    moveSouth(n , map , flag , name , x , y , p2);
                    break;
                case 3:
                    moveNortheast(n , map , flag , name , x , y , p2);
                    break;
                case 4:
                    moveNorthwest(n , map , flag , name , x , y , p2);
                    break;
                case 5:
                    moveSoutheast(n , map , flag , name , x , y , p2);
                    break;
                case 6:
                    moveSouthwest(n , map , flag , name , x , y , p2);
                    break;
                } ///movement case ended here...
                break;

            case 2: ///split a cell
                printf("choose a cell?\n");
                printf("name : "); scanf("%s" , name);
                printf("X : "); scanf("%d" , &x);
                printf("Y : "); scanf("%d" , &y);
                arrayMode(&x , &y , n);
                p2 = split(n , flag , map , p2 , name , x , y , 2);
                break;
            case 3: ///boost energy
                printf("choose a cell?\n");
                printf("name : "); scanf("%s" , name);
                printf("X : "); scanf("%d" , &x);
                printf("Y : "); scanf("%d" , &y);
                arrayMode(&x , &y , n);
                boostEnergy(n , arrEnergy , map , p2 , name , x , y);
                break;
            case 4:
                save(p1 , p2 , 2 , n , arrEnergy , map);
                break;
            case 5:
                return -1;
                break;
            case 6:
                printList(&p2 , n);
                i--;
                Sleep(5000);
                break;
            }
            Sleep(500);
            system("CLS");
            printMap(n , map , arrEnergy);
            insertCellPlayer1(p1 , n , map);
            insertCellPlayer1(p2 , n , map);
        }
    }
    fclose(ptr);
    return 0;
}
