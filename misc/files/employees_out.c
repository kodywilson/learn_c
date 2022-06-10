#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
    char name[50];
    char designation[50];
    int age;
    float salary;
} emp;

int main()
{
    int count = 0;
    FILE *fp;
    fp = fopen("employee.txt", "rb");
    struct employee emps[2];

    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    printf("Testing fread() function: \n\n");

    while( fread(&emp, sizeof(emp), 1, fp) == 1 )
    {
        //count++;
        printf("Name: %s \n", emp.name);
        //strcpy(emps[count].name, emp.name);
        printf("Designation: %s \n", emp.designation);
        strcpy(emps[count].designation, emp.designation);
        printf("Age: %d \n", emp.age);
        printf("Salary: %.2f \n\n", emp.salary);
        count++;
    }

    printf("We found %d employee records.\n", count);
    printf("Name of first employee was %s\n", emps[0].designation);
    printf("Name of second employee was %s\n", emps[1].designation);

    fclose(fp);
    return 0;
}
