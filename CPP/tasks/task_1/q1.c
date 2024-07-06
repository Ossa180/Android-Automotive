#include <stdio.h>

void main()
{
    int input=0;
    int res=0;
    
    printf("please enter input \n");
    scanf("%d",&input);
    while(input !=0)
    {
        res+=input;
        printf("enter new number \n");
        scanf("%d",&input);
        
    }
    printf("result = %d",res);
}