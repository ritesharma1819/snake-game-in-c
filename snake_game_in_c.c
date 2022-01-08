#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int height=20,weight=20,x,y,fruitX,fruitY,flag,game_end,score;
void make_logic()
{
    switch (flag)
    {
    case 1:
    {
        x--;
        break;
    }
    case 2:
    {
        x++;
        break;
    }
    case 3:
    {
        y--;
        break;
    }
    case 4:
    {
        y++;
        break;
    }
    
    }
}
void input()
{
    if (kbhit())
    {
        switch (getch())
        {
            case 'w':
            {
                flag=1;
                break;
            }
            case 's':
            {
                flag=2;
                break;
            }
            case 'a':
            {
                flag=3;
                break;
            }
            case 'd':
            {
                flag=4;
                break;
            }
        
        
        }
  
    }
}
void setup()
{
    x=height/2;
    y=weight/2;

    
    label1:
    fruitX=rand()%20;
    if(fruitX==0)
    goto label1;


    label2:
    fruitY=rand()%20;
    if(fruitY==0)
    goto label2;

    game_end=0;
    score=0;

}
void frame()
{
    system("cls");
    int i,j;
    for ( i = 0; i <=height; i++)
    {
        for ( j = 0; j <=weight; j++)
        {
            if (i==0 || i==height || j==0 || j==weight)
            {
              printf(".");
            }
            else
            {
                if (i==x && j==y)
                printf(">");
                else if (i==fruitX && j==fruitY)
                {
                   printf("@");
                }
            else
            {  
              printf(" ");
            }
            }

        }
        printf("\n");
    }
    
}
int main()
{
    setup();
    while (game_end!=1)
    {
     input();
     frame();
     make_logic();
    }
    
    
}