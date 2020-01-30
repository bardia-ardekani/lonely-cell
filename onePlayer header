struct player1{
    int x;
    int y;
    int energy;
    char cellName[20];
    struct player1 * next;
};

void boostEnergy(int size , int energyArr[size][size] ,char map[size][size] , struct player1 * head , char name[20] , int x , int y);
struct player1 * split(int size , int flag[size][size] ,char map[size][size] , struct player1 * head , char name[20] , int x , int y);
char *randstring(size_t length);
void createCellPlayer1(struct player1 ** head, int size ,int flag[size][size] , char map[size][size]);
void insertCellPlayer1(struct player1 * head , int size , char map[size][size]);
struct player1 * createNode(char name[] , int x , int y , int energy);
void insert(struct player1 **head ,struct player1 * createNode);
struct player1 * deleteNode(struct player1 ** head , int x , int y);
void printList(struct player1 ** head , int size);
void SetColorAndBackground(int ForgC, int BackC);
void gotoxy(int x, int y);
int oddEven(int number);
void printMap(int size , char arr[size][size] , int energy[size][size]);
void mapEditorNormal(int size , char map[size][size]);
void mapBuilder(int size , char map[size][size]);
void moveNorth(int size , char map[size][size] , int flag[size][size] , char name[] , int x , int y , struct player1 * head);
void moveSouth(int size , char map[size][size] , int flag[size][size] , char name[] , int x , int y , struct player1 * head);
void moveNortheast(int size , char map[size][size] , int flag[size][size] , char name[] , int x , int y , struct player1 * head);
void moveNorthwest(int size , char map[size][size] , int flag[size][size] , char name[] , int x , int y , struct player1 * head);
void moveSoutheast(int size , char map[size][size] , int flag[size][size] , char name[] , int x , int y , struct player1 * head);
void moveSouthwest(int size , char map[size][size] , int flag[size][size] , char name[] , int x , int y , struct player1 * head);
void arrayMode(int *x , int *y , int size);
void save( struct player1 * head , int p , int size , int energyArr[size][size] ,char map[size][size]);
struct player1 * load(struct player1 *head , int size , int flag[size][size] , char map[size][size] ,int energyArr[size][size]);

void boostEnergy(int size , int energyArr[size][size] ,char map[size][size] , struct player1 * head , char name[20] , int x , int y)
{
    if(map[x][y] != '1'){printf("its not a energy cell!\n");return;}
    struct player1 * current = head;
        while(current != NULL)
        {
            if(strcmp(current->cellName , name) == 0 && current->x == x && current->y == y) break; ///cell has been found
            else if(current->next == NULL && (strcmp(current->cellName , name) != 0 || current->x != x || current->y != y) )
            {
                printf("'%s' not found\n" , name);
                return;
            }
            current = current->next;
        }
    if(current->energy == 100) return;
    int hold;

    if(energyArr[x][y] >= 15)
    {
        current->energy += 15;
        energyArr[x][y] -= 15;
    } else {
        current->energy += energyArr[x][y];
        energyArr[x][y] = 0;
    }

    if(current->energy > 100)
    {
        hold = current->energy - 100;
        current->energy -= hold;
        energyArr[x][y] += hold;
    }

    return;
}

struct player1 * split(int size , int flag[size][size] ,char map[size][size] , struct player1 * head , char name[20] , int x , int y)
{
    int nx , ny;
    if(map[x][y] != '2') {printf("you cant split a cell here!\n"); return head;}
    int emptyCell = 0;
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size ; j++)
        {
            if(fabs(i - x) <= 1 && fabs(j - y) <= 1 && flag[i][j] == 0 && map[i][j] != '3')
            {
                if( y % 2 == 1 )
                    if( !(i == x - 1 && j == y - 1) && !(i == x - 1 && j == y + 1) )
                    {
                        emptyCell = 1;
                        nx = i;
                        ny = j;
                    }
                if( y % 2 == 0 )
                    if( !(i == x + 1 && j == y - 1) && !(i == x + 1 && j == y + 1) )
                    {
                        emptyCell = 1;
                        nx = i;
                        ny = j;
                    }
            }
        }
    }
    if(emptyCell == 0) {printf("there is no empty cells\n");Sleep(5000); return;} ///there is no empty cells

    struct player1 * current = head;
        while(current != NULL)
        {
            if(strcmp(current->cellName , name) == 0 && current->x == x && current->y == y) break; ///cell has been found
            else if(current->next == NULL && (strcmp(current->cellName , name) != 0 || current->x != x || current->y != y) )
            {
                printf("'%s' not found\n" , name);
                return;
            }
            current = current->next;
        }
    if(current->energy < 80){printf("you dont have enough energy!\n");Sleep(5000);return head;}
    char name1[20] , name2[20] , *rands1 , *rands2;
    int n , stringLen1 , stringLen2;
    printf("[1]randomize a name for mother cell\n[2]choose a name for mother cell\nchoose one option : ");
    scanf("%d" , &n);
    switch (n)
    {
    case 1:
        printf("enter the size of your random name : ");
        scanf("%d" , &stringLen1);
        rands1 = randstring(stringLen1);
        printf("%s\n" , rands1);
        insert(&head , createNode(rands1 , current->x , current->y , 40));
        break;
    case 2:
        printf("name your mother cell : ");
        scanf("%s" , name1);
        printf("%s\n" , name1);
        insert(&head , createNode(name1 , current->x , current->y , 40));
        break;
    }
    printf("[1]randomize a name for baby cell\n[2]choose a name for baby cell\nchoose one option : ");
    scanf("%d" , &n);
    switch (n)
    {
    case 1:
        printf("enter the size of your random name : ");
        scanf("%d" , &stringLen2);
        rands1 = randstring(stringLen2);
        printf("%s\n" , rands2);
        insert(&head , createNode(rands2 , nx , ny , 40));
        flag[nx][ny] = 1;
        deleteNode(&head , current->x , current->y);
        break;
    case 2:
        printf("name your baby cell : ");
        scanf("%s" , name2);
        printf("%s\n" , name2);
        insert(&head , createNode(name2 , nx , ny , 40));
        flag[nx][ny] = 1;
        deleteNode(&head , current->x , current->y);
        break;
    }
    return head;
}

char *randstring(size_t length) {

    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
    char *randomString = NULL;

    if (length) {
        randomString = malloc(sizeof(char) * (length +1));

        if (randomString) {
            for (int n = 0;n < length;n++) {
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }

            randomString[length] = '\0';
        }
    }

    return randomString;
}

void createCellPlayer1(struct player1 ** head, int size ,int flag[size][size] , char map[size][size])
{
    int cellCount;
    printf("please Enter the number of cells : ");
    scanf("%d" , &cellCount);
    for(int i = 0 ; i < cellCount ; i++)
    {
        int n , x , y;
        printf("[1]randomize a name for %dth cell\n[2]choose a name for %dth cell\nenter any key : " , i+1 , i+1);
        scanf("%d" , &n);
        do{
        x = rand() % size;
        y = rand() % size;
        }while( flag[x][y] == 1 || map[x][y] == '3' ); ///to avoid recurrent coordinate and forbidden cells
        flag[x][y] = 1;
        char nameStr[20];
        char *rands;
        int stringLen;
        switch (n)
        {
        case 1:
            printf("enter the size of your random name : ");
            scanf("%d" , &stringLen);
            rands = randstring(stringLen);
            printf("%s\n" , rands);
            insert(&(*head) , createNode(rands , x , y , 0));
            break;
        case 2:
            printf("name your cell : ");
            scanf("%s" , nameStr);
            printf("%s\n" , nameStr);
            insert(&(*head) , createNode(nameStr , x , y , 0));
            break;
        }
    }
}

void insertCellPlayer1(struct player1 * head , int size , char map[size][size])
{
    struct player1 * current = head;
    if(current == NULL)
    {
        printf("no cells for an old man\n");
        return;
    }

    while(current != NULL)
    {
        int step = oddEven(current->y);
        int xCoor = current->x * 5 + 2 + step;
        int yCoor = current->y * 13 + 6;
        int color = map[current->x][current->y];
        switch (color)
            {
            case 49:
                SetColorAndBackground(0,6);
                break;
            case 50:
                SetColorAndBackground(0,5);
                break;
            case 51:
                SetColorAndBackground(0,7);
                break;
            case 52:
                SetColorAndBackground(0,3);
                break;
            }
    gotoxy(yCoor,xCoor); /// y = satr x = soton
    printf("X");
    current = current->next;
    }
    SetColorAndBackground(2,0);
    gotoxy(0,size*5 + 3);///go back to normal position and color
}

struct player1 * createNode(char name[] , int x , int y , int energy)
{
    struct player1 * nn;
    nn = (struct player1 *)malloc(sizeof(struct player1));
    nn->x = x;
    nn->y = y;
    nn->energy = energy;
    strcpy( nn->cellName , name );
    nn->next = NULL;
    return nn;
}

void insert(struct player1 **head ,struct player1 * createNode)
{
    if(*head == NULL)
    {
        *head = createNode;
        return;
    }

    struct player1 * current = *head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = createNode;
}

struct player1 * deleteNode(struct player1 ** head , int x , int y)
{
    if(*head == NULL)
    {
        printf("the list is empty\n");
        return NULL;
    }

    struct player1 * current = *head;
    struct player1 * toDelete;
    if( current->x == x && current->y == y )
    {
        toDelete = current;
        *head = current->next;
        free(toDelete);
        return *head;
    }
    struct player1 * save;

    while( current->next->x != x || current->next->y != y )
    {
        current = current->next;
        if(current->next->next == NULL) break;
    }
    if( current->next->next == NULL && (current->next->x != x || current->next->y != y) )
    {
        printf("this data does not exist\n");
        return;
    }
    save = current;
    toDelete = current->next;
    save->next = current->next->next;
    free(toDelete);
    return *head;
}

void printList(struct player1 ** head , int size)
{
    struct player1 * curr = *head;
    int i = 1;
    if(curr == NULL)
    {
        printf("list is empty\n");
        return;
    }
    while(curr != NULL)
    {
        printf("\n[%d] %s (%d , %d) energy = %d", i , curr->cellName , curr->y , size - curr->x - 1 , curr->energy);
        curr = curr->next;
        i++;

    }
    printf("\n");
}

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

int oddEven(int number)
{
    if(number % 2 == 0) return 0;
    else return 2;
}

void printMap(int size , char arr[size][size] , int energy[size][size])
{
     /// 1) Energy = yellow
     /// 2) Mitosis = purple
     /// 3) forbidden = red
     /// 4) normal = blue
     ///xcoor == 12*j and reset after every first loop
     ///ycoot == 3*i + step ///step is for up and down in the map
     int xCoor , yCoor , step;
     for(int i = 0 ; i < size ; i++)
     {
        for(int j = 0 ; j < size ; j++)
        {
            step = oddEven(j);
            xCoor = 13*j;
            yCoor = 5*i + step;
            yCoor = 5*i + step;
            switch (arr[i][j])
            {
            case 49:
                SetColorAndBackground(0,6);
                break;
            case 50:
                SetColorAndBackground(0,5);
                break;
            case 51:
                SetColorAndBackground(0,7);
                break;
            case 52:
                SetColorAndBackground(0,3);
                break;
            }
            gotoxy(xCoor , yCoor);
            printf("    (%d,%d)    " , j , size - i - 1);
            gotoxy(xCoor , yCoor+1);
            printf("             ");
            gotoxy(xCoor , yCoor+2);
            printf("             ");
            gotoxy(xCoor , yCoor+3);
            printf("             ");
            gotoxy(xCoor , yCoor+4);
            printf("             ");
            if(arr[i][j] == '1') {gotoxy(xCoor , yCoor+4); printf("     %.3d     " , energy[i][j]);}
            gotoxy(13*size + 5 , size/2 * 5);
            SetColorAndBackground(6,0);
            printf("/Energy/");
            gotoxy(13*size + 5 , size/2 * 5 + 1);
            SetColorAndBackground(5,0);
            printf("/Mitosis/");
            gotoxy(13*size + 5 , size/2 * 5 + 2);
            SetColorAndBackground(7,0);
            printf("/Forbidden/");
            gotoxy(13*size + 5 , size/2 * 5 + 3);
            SetColorAndBackground(3,0);
            printf("/Normal/");
            SetColorAndBackground(2,0); ///change back color to normal
        }
        printf("\n");

     }
}

void mapEditorNormal(int size , char map[size][size])
{
    int randome;
    srand(time(0));
    for(int i = 0 ; i < size ; i++)
     {
        for(int j = 0 ; j < size ; j++)
        {
            randome = rand() % 4 + 1;
            switch (randome)
            {
            case 1:
                map[i][j] = '1';
                break;
            case 2:
                map[i][j] = '2';
                break;
            case 3:
                map[i][j] = '3';
                break;
            case 4:
                map[i][j] = '4';
                break;
            }
        }
     }
}

void mapBuilder(int size , char map[size][size])
{
    int number;
    printf("1) Energy = yellow\n2) Mitosis = purple\n3) forbidden = white\n4) normal = blue\n");
    printf("init the map : \n");
    for(int i = 0 ; i < size ; i++)
     {
        for(int j = 0 ; j < size ; j++)
        {
            printf("location x:%d , y:%d is : " , i , j);
            scanf("%d" , &number);
            switch (number)
            {
            case 1:
                map[i][j] = '1';
                break;
            case 2:
                map[i][j] = '2';
                break;
            case 3:
                map[i][j] = '3';
                break;
            case 4:
                map[i][j] = '4';
                break;
            }
        }
     }
}
void moveNorth(int size , char map[size][size] , int flag[size][size] , char name[] , int x , int y , struct player1 * head)
{
        struct player1 * current = head;
        while(current != NULL)
        {
            if(strcmp(current->cellName , name) == 0 && current->x == x && current->y == y) break; ///cell has been found
            else if(current->next == NULL && (strcmp(current->cellName , name) != 0 || current->x != x || current->y != y) )
            {
                printf("'%s' not found\n" , name);
                return;
            }
            current = current->next;
        }
        if(flag[current->x - 1][current->y] != 0 || map[current->x - 1][current->y] == '3'){printf("you cant go there!\n"); return;}
        flag[current->x][current->y] = 0;
        flag[current->x - 1][current->y] = 1;
        current->x = current->x - 1;
        return;
}

void moveSouth(int size , char map[size][size] , int flag[size][size] , char name[] , int x , int y , struct player1 * head)
{
        struct player1 * current = head;
        while(current != NULL)
        {
            if(strcmp(current->cellName , name) == 0 && current->x == x && current->y == y) break; ///cell has been found
            else if(current->next == NULL && (strcmp(current->cellName , name) != 0 || current->x != x || current->y != y) )
            {
                printf("'%s' not found\n" , name);
                return;
            }
            current = current->next;
        }
        if(flag[current->x + 1][current->y] != 0 || map[current->x + 1][current->y] == '3'){printf("you cant go there!\n"); return;}
        flag[current->x][current->y] = 0;
        flag[current->x + 1][current->y] = 1;
        current->x = current->x + 1;
        return;
}

void moveNortheast(int size , char map[size][size] , int flag[size][size] , char name[] , int x , int y , struct player1 * head)
{
        struct player1 * current = head;
        while(current != NULL)
        {
            if(strcmp(current->cellName , name) == 0 && current->x == x && current->y == y) break; ///cell has been found
            else if(current->next == NULL && (strcmp(current->cellName , name) != 0 || current->x != x || current->y != y) )
            {
                printf("'%s' not found\n" , name);
                return;
            }
            current = current->next;
        }

        if(current->y % 2 == 0) ///x-- , y++
        {
            if(flag[current->x - 1][current->y + 1] != 0 || map[current->x - 1][current->y + 1] == '3'){printf("you cant go there!\n"); return;}
            flag[current->x][current->y] = 0;
            flag[current->x - 1][current->y + 1] = 1;
            current->x = current->x - 1;
            current->y =current->y + 1;
        } else { /// y++
            if(flag[current->x][current->y + 1] != 0 || map[current->x][current->y + 1] == '3'){printf("you cant go there!\n"); return;}
            flag[current->x][current->y] = 0;
            flag[current->x][current->y + 1] = 1;
            current->y =current->y + 1;
        }
        return;
}

void moveNorthwest(int size , char map[size][size] , int flag[size][size] , char name[] , int x , int y , struct player1 * head)
{
        struct player1 * current = head;
        while(current != NULL)
        {
            if(strcmp(current->cellName , name) == 0 && current->x == x && current->y == y) break; ///cell has been found
            else if(current->next == NULL && (strcmp(current->cellName , name) != 0 || current->x != x || current->y != y) )
            {
                printf("'%s' not found\n" , name);
                return;
            }
            current = current->next;
        }

        if(current->y % 2 == 0) ///x-- , y--
        {
            if(flag[current->x - 1][current->y - 1] != 0 || map[current->x - 1][current->y - 1] == '3'){printf("you cant go there!\n"); return;}
            flag[current->x][current->y] = 0;
            flag[current->x - 1][current->y - 1] = 1;
            current->x = current->x - 1;
            current->y =current->y - 1;
        } else { /// y--
            if(flag[current->x][current->y - 1] != 0 || map[current->x][current->y - 1] == '3'){printf("you cant go there!\n"); return;}
            flag[current->x][current->y] = 0;
            flag[current->x][current->y - 1] = 1;
            current->y =current->y - 1;
        }
        return;
}

void moveSoutheast(int size , char map[size][size] , int flag[size][size] , char name[] , int x , int y , struct player1 * head)
{
        struct player1 * current = head;
        while(current != NULL)
        {
            if(strcmp(current->cellName , name) == 0 && current->x == x && current->y == y) break; ///cell has been found
            else if(current->next == NULL && (strcmp(current->cellName , name) != 0 || current->x != x || current->y != y) )
            {
                printf("'%s' not found\n" , name);
                return;
            }
            current = current->next;
        }

        if(current->y % 2 == 0) /// y++
        {
            if(flag[current->x][current->y + 1] != 0 || map[current->x][current->y + 1] == '3'){printf("you cant go there!\n"); return;}
            flag[current->x][current->y] = 0;
            flag[current->x][current->y + 1] = 1;
            current->y =current->y + 1;
        } else { /// x++ , y++
            if(flag[current->x + 1][current->y + 1] != 0 || map[current->x + 1][current->y + 1] == '3'){printf("you cant go there!\n"); return;}
            flag[current->x][current->y] = 0;
            flag[current->x + 1][current->y + 1] = 1;
            current->x =current->x + 1;
            current->y =current->y + 1;
        }
        return;
}

void moveSouthwest(int size , char map[size][size] , int flag[size][size] , char name[] , int x , int y , struct player1 * head)
{
        struct player1 * current = head;
        while(current != NULL)
        {
            if(strcmp(current->cellName , name) == 0 && current->x == x && current->y == y) break; ///cell has been found
            else if(current->next == NULL && (strcmp(current->cellName , name) != 0 || current->x != x || current->y != y) )
            {
                printf("'%s' not found\n" , name);
                return;
            }
            current = current->next;
        }

        if(current->y % 2 == 0) /// y--
        {
            if(flag[current->x][current->y - 1] != 0 || map[current->x][current->y - 1] == '3'){printf("you cant go there!\n"); return;}
            flag[current->x][current->y] = 0;
            flag[current->x][current->y - 1] = 1;
            current->y =current->y - 1;
        } else { /// x++ , y--
            if(flag[current->x + 1][current->y - 1] != 0 || map[current->x + 1][current->y - 1] == '3'){printf("you cant go there!\n"); return;}
            flag[current->x][current->y] = 0;
            flag[current->x + 1][current->y - 1] = 1;
            current->x =current->x + 1;
            current->y =current->y - 1;
        }
        return;
}
void arrayMode(int *x , int *y , int size)
{
    int xr , yr;
    xr = size - *y - 1;
    yr = *x;
    *x = xr;
    *y = yr; ///turn x & y back to array mode

    return;
}

void save( struct player1 * head , int p , int size , int energyArr[size][size] ,char map[size][size])
{
    FILE * mood = fopen("mood.txt" , "w");
    int c;
    if(p == 1) c = 49;
    if(p == 2) c = 50;
    fputc(c , mood);
    fclose(mood);
    FILE * save = fopen("save.txt" , "w");
    FILE * res = fopen("resourse.txt" , "w");
    FILE * maps = fopen("savedMap" , "wb");
    if(save == NULL) {printf("ERROR!"); return;}
    if(res == NULL) {printf("ERROR!"); return;}
    fwrite(&size , sizeof(int) , 1 , maps);
    struct player1 * curr = head;
    while(curr!=NULL)
    {
        fprintf(save ,"%s %d %d %d\n" , curr->cellName , curr->x , curr->y , curr->energy);
        curr = curr->next;
    }
    for(int i = 0 ; i < size ; i++)
     {
        for(int j = 0 ; j < size ; j++)
        {
            char c = map[i][j];
            fprintf( res , "%d " , energyArr[i][j]);
            fwrite(&c , sizeof(char) , 1 , maps);
        }
     }
    fclose(maps);
    fclose(res);
    fclose(save);
}

struct player1 * load(struct player1 *head , int size , int flag[size][size] , char map[size][size] ,int energyArr[size][size])
{
    char name[20];
    int x , y , energy , n;
    FILE *load = fopen("load.txt" , "r");
    fscanf(load , "%d" , &n);
    if(n == 0)
    {
        createCellPlayer1(&head , size , flag , map);
        return head;
    }
    FILE *save = fopen("save.txt" , "r");
    FILE *res = fopen("resourse.txt" , "r");
    while(1)
    {
        if(feof(save)) break;
        fscanf(save , "%s %d %d %d\n" , name , &x , &y , &energy);
        insert(&head , createNode(name , x , y , energy));
        printList(&head , n);
    }
    printf("hey");
    for(int i = 0 ; i < size ; i++)
     {
        for(int j = 0 ; j < size ; j++)
        {
            fscanf(res , "%d" , &energyArr[i][j]);
        }
     }
    fclose(save);
    fclose(res);
    return head;
}
