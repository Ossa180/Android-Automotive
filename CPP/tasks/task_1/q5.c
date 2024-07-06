#include <stdio.h>
#include <string.h>

struct name
{
    char f_name[20];
    char s_name[20];
    char l_name[20];
};

struct bd
{
    int day;
    int month;
    int year;
};
struct address
{
    char street[100];
    char city [28];
    char country[28];
};

typedef struct employee
{
    struct name e_name;
    struct bd e_bd;
    struct address e_address;
    char job[50];
}employee;


void main()
{
    employee e_1;
    strcpy(e_1.e_name.f_name,"mohamed");
    strcpy(e_1.e_name.s_name,"ahmed");
    strcpy(e_1.e_name.l_name,"hussen");

    e_1.e_bd.day=15;
    e_1.e_bd.month=07;
    e_1.e_bd.year=1999;

    printf("Employee Information:\n");
    printf("Name: %s %s %s\n", e_1.e_name.f_name, e_1.e_name.s_name, e_1.e_name.l_name);
    printf("Date of Birth: %d-%d-%d\n", e_1.e_bd.day, e_1.e_bd.month, e_1.e_bd.year);


}