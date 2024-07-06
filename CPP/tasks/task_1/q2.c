#include <stdio.h>

void main()
{
    long int input;
    int hours,min,sec;

    printf("enter seconds to convert it to HH : MM : SS formt \n");
    scanf("%ld",&input);
    hours=input/3600;
    min=(input%3600)/60;
    sec=(input%3600)%60;
    printf("time in format is >> %d : %d : %d \n",hours,min,sec);

}