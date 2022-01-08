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
    default:
      break;
    
    }
    if (x<0 || x>height || y<0 || y>weight)
    {
        game_end=1;
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
            case 'x':
            {
                game_end=1;
                break;
            }
        
        
        }
  
    }
}
void setup()
{
    game_end=0;

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
     frame();
     input();
     make_logic();

     for (int  m = 0; m < 1000; m++)
     {
        for (int n = 0; n < 100000; n++)
        {
        }
        
     }
     
    }
    
    
}