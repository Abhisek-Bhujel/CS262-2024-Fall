#include <stdio.h>
#include <string.h>
int main()
{
    char buffer[20];
    struct employee
    {
        char name[20];
        int hiredate;
        float salary;
    };
    struct employee employee1 = {"Abhisek", 2019, 10000.0};
    printf("name: %s\nhiredate : %d\nsalary : %.2f\n", employee1.name, employee1.hiredate, employee1.salary);

    struct employee employee2;
    printf("Enter the name of employee : ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(employee2.name, buffer);

    printf("Enter the hiredate of employee : ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d",  &employee2.hiredate);

    printf("Enter the salary of employee : ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f",  &employee2.salary);

    printf("name: %s\nhiredate : %d\nsalary : %.2f\n", employee2.name, employee2.hiredate, employee2.salary);


    
    
    return 0;



}