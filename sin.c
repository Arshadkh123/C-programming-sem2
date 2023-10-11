#include <stdio.h>
#include<conio.h>
#include <math.h>
int main(void)
{
  double si, num;
  printf(" Enter a Value between 0 and 1 :  ");
  scanf("%lf", &num);
  
  si = sin(num);
  
  printf("\n The sine value of %lf = %lf ", num, si);
  getch();
  return 0;
  
}