#include<stdio.h>
int height=20,weight=20;
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
              printf(" ");

        }
        printf("\n");
    }
    
}
int main()
{
    frame();
}