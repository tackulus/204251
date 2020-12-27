#include<stdio.h>

int main()
{
    int u; 
    float x, y;

    scanf("%d", &u);
    scanf("%f", &x);

    switch (u)
    {
        case 1:
            y = x * 1.8 + 32;
            break;

        case 2:
            y = (x - 32) / 1.8;
            break;
    }
    
    printf("%.2f", y);
    return 0;
}