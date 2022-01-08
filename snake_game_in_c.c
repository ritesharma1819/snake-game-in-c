#include<stdio.h>
int height=20,weight=20,x,y,fruitX,fruitY;
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

}
void frame()
{
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
    frame();
}