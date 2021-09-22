

#include <stdio.h>

char b[7][6];
int index[7],available=1,stop;

void intiBoard(char b[][6])
{
    for(int i=0;i<7;i++)
    {
        for(int s=0;s<6;s++)
        {
            b[i][s]=' ';
        }
    }
}

void printBoard(char b[][6])
{
    for(int i=0;i<7;i++)
    {
        printf(" ");
        for(int s=0;s<15;s++)
        {
            printf("_");
        }
        printf("\n| ");
        for(int s=0;s<6;s++)
        {
            printf("%c ",b[i][s]);
        }
        printf("\n ");
    }
    for(int s=0;s<15;s++)
    {
        printf("_");
    }
    printf("\n");
}

int checkHorizantalWin(char b[][6],int r,char p)
{
    for(int i=0;i<3;i++)
    {
        if(b[r][i]==p&&b[r][i+1]==p&&b[r][i+2]==p&&b[r][i+3]==p)
        {
            return 1;
        }
    }
    return 0;
}

int checkVerticalWin(char b[][6],int c,char p)
{
    for(int i=0;i<4;i++)
    {
        if(b[i][c]==p&&b[i+1][c]==p&&b[i+2][c]==p&&b[i+3][c]==p)
        {
            return 1;
        }
    }
    return 0;
}

int checkDraw(char b[][6])
{
    for(int i=0;i<7;i++)
    {
        if(index[i]<7)
        {
            return 0;
        }
    }
    return 1;
}

void enterTheDisk(int i,char p)
{
    if(index[i]>5)
    {
        available=0;
        return ;
    }
    else
    {
        available=1;
    }
    b[i][index[i]]=p;
    index[i]++;
}

int main()
{
    intiBoard(b);
    printBoard(b);
    char p;
    int i;
    do
    {
        if(checkDraw(b))
        {
            printf("DRAW .\n");
            break;
        }
        do
        {
            printf("Add a red disk at row ( 0 - 6 ) :\n");
            scanf("%d",&i);
            enterTheDisk(i,'R');
            if(!available)
            {
                printf("The slot is not available try another row .\n");
            }
        }
        while(!available);
        printBoard(b);
        if(checkDraw(b))
        {
            printf("DRAW .\n");
            break;
        }
        for(int r=0;r<7;r++)
        {
            if(checkHorizantalWin(b,r,'R'))
            {
                printf("The Red won .\n");
                stop=1;
                break;
            }
        }
        if(stop)
        {
            break;
        }
        for(int c=0;c<6;c++)
        {
            if(checkVerticalWin(b,c,'R'))
            {
                printf("The Red won .\n");
                stop=1;
                break;
            }
        }
        if(stop)
        {
            break;
        }
        do//now the other player
        {
            printf("Add a yellow disk at row ( 0 - 6 ) :\n");
            scanf("%d",&i);
            enterTheDisk(i,'Y');
            if(!available)
            {
                printf("The slot is not available try another row .\n");
            }
        }
        while(!available);
        printBoard(b);
        if(checkDraw(b))
        {
            printf("DRAW .\n");
            break;
        }
        for(int r=0;r<7;r++)
        {
            if(checkHorizantalWin(b,r,'Y'))
            {
                printf("The Yellow won");
                stop=1;
                break;
            }
        }
        if(stop)
        {
            break;
        }
        for(int c=0;c<6;c++)
        {
            if(checkVerticalWin(b,c,'Y'))
            {
                printf("The Yellow won .\n");
                stop=1;
                break;
            }
        }
        if(stop)
        {
            break;
        }
    }
    while(1);

    return 0;
}
