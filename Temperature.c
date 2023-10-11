#include<stdio.h>
int main()
{
    int farehn,celsius;
    printf("enter the temperature in farehnheit:");
    scanf("%d",&farehn);
    celsius=(farehn - 32)/0.9; // note conversion
    printf("\n %d farenheit is %d celsius.\n",farehn,celsius);
    return 0;
}