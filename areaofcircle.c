#include<stdio.h>
#include<conio.h>
#define pi 3.14159
int main()
{
    double ar=0.0, radius=0.0;
    printf("enter radius: ");
    scanf("%Lf",&radius);
    ar=pi*radius*radius;
    printf("radius of %Lf meters;\narea is %Lf sq.meters",radius,ar);
    getch();
    return 0;
}