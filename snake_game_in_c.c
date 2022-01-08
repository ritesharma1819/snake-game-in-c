#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int height=20,weight=20,x,y,fruitX,fruitY,flag,game_end,score;
int tailX[100],tailY[100];
int pre2X,pre2Y;
int countTail=0;


void make_logic()
{
    int preX=tailX[0];
    int preY=tailY[0];
    tailX[0]=x;
    tailY[0]=y;
    for ( int i = 1; i < countTail; i++)
    {
        pre2X=tailX[i];
        pre2Y=tailY[i];
        tailX[i]=preX;
        tailY[i]=preY;
        preX=pre2X;
        preY=pre2Y;

    }
    

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

    for (int i = 0; i < countTail; i++)
    {
       if (x==tailX[i] && y==tailY[i])
       {
          game_end=1;
       }
       
    }
    
    if(x==fruitX && y==fruitY)
    {
    label3:
    fruitX=rand()%20;
    if(fruitX==0)
    goto label3;


    label4:
    fruitY=rand()%20;
    if(fruitY==0)
    goto label4;

    score+=10;
    countTail++;
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
    int i,j,k;
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
                printf("O");
                else if (i==fruitX && j==fruitY)
                {
                   printf("@");
                }
            else
            { 
                 int co=0;
                for ( k = 0; k < countTail; k++)
                {
                   if (i==tailX[k] && j==tailY[k])
                   {
                       printf("o");
                       co=1;
                   }
                }
                if (co==0)
                {
                    printf(" ");
                }
                 
              
            }
            }

        }
        printf("\n");
    }
   printf("Score=%d",score); 
}



int main()
{
    char c;
    label5:
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
    printf("Do you want to play again than press y key:");
    scanf("%c",&c);
    if (c=='y'|| c=='Y')
    {
        goto label5;
    }
    
    
}