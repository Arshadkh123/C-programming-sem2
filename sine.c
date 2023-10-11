/*
Arshad khan
15-06-23
Coursera Assignment week 2
sine of number between 0 and 1
*/

#include<stdio.h>
#include<conio.h>
#include <math.h> // to use the function sin()
int main(void)
{ 
 double x_radians;  // since the number is between 0 and 1, it cannot be in degrees
 double sin_x;      // to store sine of x_radians\
 
 printf("Enter any number between 0 and 1 (not inclusive) :\n");   // taking input from user
 scanf("%lf", &x_radians); //storing input in x_radians
 
 if(x_radians>0 && x_radians < 1) //checking if input is in the given range
 {
   sin_x= sin(x_radians); // using sin() from math.h 
 
   printf("the number: %lf \nthe sine of number: %lf \n", x_radians, sin_x); //printing output
 }
 else
 printf("Input error; number is not in the range of 0 to 1."); //printing error message
 getch();
return 0;
}
