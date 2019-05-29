#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Enter height of pyramid: ");
    }
    while (height<0 || height>9);
    
    for (int i=0;i<height;i++)
    {
        for (int j=0;j<height-i-1;j++)
        {
            printf(".");
        }
        for (int k=0;k<=i;k++)
        {
            printf("#");
        }
        printf(" ");
        
        for (int l=0;l<=i;l++)
        {
            printf("#");
        }
        
        for (int m=0;m<height-i-1;m++)
        {
            printf(".");
        }
        printf("\n");
    }
}
