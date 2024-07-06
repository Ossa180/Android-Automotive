#include <stdio.h>

void main()
{
    // assume current population is 162,100 and we are at 2002 
    long int current_pop = 162100;
    int year = 2002;
    int growth = 10537; // per year
    while (current_pop < 1000000)
    {
        current_pop+= growth;
        year++;
    }
    printf("population superpassed 1 million at %d with population %d \n",year+1,current_pop+growth);
}