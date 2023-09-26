#include<stdio.h>
#include<Windows.h>
//#include"employeeAdmin.h"
#include"employeeAdmin.c"
//#include"employeeDataType.h"

void admin_menu()
{


    int option2;
    while(1)
 {
    printf("\n\n\n\nPress any key to continue\n");
    getch();
    system("cls");
    printf("ADMIN MENU\n\n\n");
    printf("*********************************\n\n");
    printf("1.View ALL Employees\n");
    printf("2.Add New Employees\n");
    printf("3.Update Employee Information by ID\n");
    printf("4.Calculate Salary\n");
    printf("5.Delete Employee by ID\n");
    printf("6.View Employee Details by ID\n");
    printf("7.RETURN \n\n");

    printf("Please Enter an option\n");

    scanf("%d",&option2);
    system("cls");

    int Id;
    switch(option2)
    {
        case 1: viewAllEmployee(E); 
        continue;
        case 2: addEmployee(&E[count]);
        continue;
        case 3: 
        printf("\nEnter ID to be UPDATED\n");
        scanf("%d",&Id);
        updateEmployee(E,Id);
         continue;
        case 4: calSalary(E);
            continue;
        case 5:printf("\nEnter ID to be DELETED\n");
        scanf("%d",&Id);
        deleteEmployee(E,Id);
        continue;
        case 6: printf("\nEnter ID to view\n");
        scanf("%d",&Id);
        viewByID(E,Id);
        continue;
        case 7: return;

        default: continue;
    }
 }

}

void menu()
{
    while(1)
    {
    int option1;
    printf("EMPLOYEE MANAGEMENT SYSTEM\n\n\n");
    printf("*********************************\n\n");

    printf("1.Employee\n");
    printf("2.Admin\n");
    printf("3.EXIT\n\n");

    printf("Please Enter an option\n");

    scanf("%d",&option1);
    system("cls");

    if(option1==2)
    {
        admin_menu();
        Sleep(7000);
        continue;
    }
    else
    if(option1==1)
    {
        printf("employee_menu()\n");
        Sleep(3000);
        continue;
    }

    else{
    printf("Exiting the program....\n");
    exit(0);
    }
    }
}