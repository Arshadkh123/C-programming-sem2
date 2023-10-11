/*the distance of a marathon in kilometers
by arshad coder
March 25,2023
*/
#include<stdio.h>
#include<conio.h>
int main()
{
    int miles=26,yards=385;
    double kilometers;
    kilometers=1.609 * (miles + yards/1760.0);
   printf("\n A marathon is %Lf kilometers.\n\n",kilometers);
   getch();
   return 0;
}
