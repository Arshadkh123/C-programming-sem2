#include<stdio.h>
#include<conio.h>
#include<math.h> /* has  sin(), abs(), and fabs() */
int main(void)
{ 
 float r;
 int i;
 char ch;
 printf("\n Angle \t sin \t cos\n");
 for(i=0;i<=100;i=i+30)
 {
    r=i*3.1459/180;
    printf("\n%3d \t %5.2f \t %5.2f\t",i,sin(r),cos(r));
 }
 printf("--------------");
 getch();
return 0;
}