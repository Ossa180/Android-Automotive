#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int string_num;
    std::cout<<"enter number of string you want to enter \n";
    std::cin>>string_num;

    char** array=(char**)malloc(string_num * sizeof(char*));
    for (int i=0 ; i <string_num;i++)
    {
        char str[20];
        std::cout<<"enter string "<<i+1<<"\n";
        scanf("%s",str);
        array[i] = (char *)malloc((strlen(str)+1) * sizeof(char));
        strcpy(array[i],str);

    }
    printf("strings >>> ");
    for (int i = 0; i < string_num; i++) {
        printf("%s ", array[i]);
    }
    for (int i = 0; i < string_num; i++) {
        free (array[i]);
    }

    free (array);

}
