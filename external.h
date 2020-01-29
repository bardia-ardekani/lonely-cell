void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int start()
{
    int n;
    SetColorAndBackground(2 , 0);
    gotoxy(35 , 15);
    printf("Hello dear player! please stand by...\n");
    Sleep(5000);
    system("CLS");
    gotoxy(0 , 50);
    printf("loading");
    for(int i = 0 ; i < 4 ; i++)
    {
        printf(".");
        Sleep(500);
    }
    gotoxy(0 , 50);
    printf("            ");
    gotoxy(0 , 50);
    printf("loading");
    for(int i = 0 ; i < 4 ; i++)
    {
        printf(".");
        Sleep(500);
    }
    gotoxy(0 , 50);
    printf("            ");
    gotoxy(0 , 50);
    printf("press any key to continue ");
    getchar();
    system("CLS");
    gotoxy(40 , 15);
    printf("[1]new single player game");
    gotoxy(40 , 16);
    printf("[2]new multiplayer game");
    gotoxy(40 , 17);
    printf("[3]load game");
    gotoxy(40 , 18);
    printf("[4]exit");
    gotoxy(40 , 19);
    printf("[5]map editor");
    gotoxy(40 , 20);
    printf("select a menu : ");
    scanf("%d" , &n);
    Sleep(350);
    system("CLS");
    if(n == 4) { gotoxy(45 , 15); printf("come back soon :)"); Sleep(5000); system("CLS"); exit(-1);}
    gotoxy(0 , 50);
    printf("loading");
    for(int i = 0 ; i < 4 ; i++)
    {
        printf(".");
        Sleep(500);
    }
    gotoxy(0 , 50);
    printf("            ");
    gotoxy(0 , 50);
    printf("loading");
    for(int i = 0 ; i < 4 ; i++)
    {
        printf(".");
        Sleep(500);
    }
    system("CLS");
    return n;
}
