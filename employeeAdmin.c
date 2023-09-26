#include<stdio.h>
//#include"employeeAdmin.h"
#include<conio.h>
#include"validate.c"

void addEmployee(Employee *ptr)
{
 do{
   printf("Enter ID: ");
   if(scanf("%d",&ptr->ID)==0)
   {
    printf("Enter only integer values\n");
    break;
   }
    }while(!validateID(ptr->ID));

    //printf("/n");
    do{
    printf("Enter Name: ");
    scanf("%s",&ptr->name);
    }while(!validateName(ptr->name));

    //printf("/n");
    do{
    printf("Enter Salary: ");
    scanf("%f",&ptr->basicSalary);
    }while(!validateSalary(ptr->basicSalary));
 
    //printf("/n");
    do{
        printf("Enter Hire Date in the format dd mm yyyy: ");
    scanf("%d %d %d",&ptr->hire.day,&ptr->hire.month,&ptr->hire.year);

    }while(!validateDate(ptr->hire.day,ptr->hire.month,ptr->hire.year));
    
    //printf("/n");

    count++;
    //return;
}

void viewAllEmployee(Employee ptr[])
{
    printf("\nDetails of the Employee\n");
    printf("ID \t Name \t\t Basic Salary \t D.O.J\t \n");
    for(int i=0;i<count;i++)
    {
    printf("%d \t %s \t\t %f \t %d.%d.%d \t \n", ptr[i].ID, ptr[i].name,ptr[i].basicSalary, ptr[i].hire.day, ptr[i].hire.month, ptr[i].hire.year);
    }
    // printf("\n\n\n\nPress any key to continue\n");
    // getch();
    // system("cls");
}

void viewByID(Employee ptr[],int ID)
{
    int i=0;
    for(i=0;i<count;i++)
    {
        if(ptr[i].ID==ID)
        {
        
        printf("ID \t Name \t Basic Salary \t D.O.J \n");
        printf("%d\t %s\t %f\t %d %d %d\t", ptr[i].ID,ptr[i].name,ptr[i].basicSalary,ptr[i].hire.day,ptr[i].hire.month,ptr[i].hire.year);
        printf("\n\n\n\nPress any key to continue\n");
        getch();
        system("cls");
        return;
        }
    }
     printf("\n Employee not found.\n");

    printf("\n\n\n\nPress any key to continue\n");
    getch();
    system("cls");
}
void updateMenu()
{ 

    printf("UPDATE MENU\n\n\n");
    printf("*********************************\n\n");

    printf("1.Update Name\n");
    printf("2.Update Basic Salary\n");
    printf("3.EXIT\n\n");

}

void updateEmployee(Employee ptr[],int upID)

{
    
    for(int i=0;i<count;i++)
    {
        if(ptr[i].ID==upID)
        {
            
           // printf("Employee to be deleted: ");
            //viewEmployee(&ptr[i]); 
        while(1)
        {
            updateMenu();
            printf("\n\nPlease Enter an option\n");
            int option;
            scanf("%d",&option);
            system("cls");

            switch(option)
            {
                case 1: printf("Enter New Name:\n");
                        scanf("%s",&ptr[i].name);
                        continue;

                case 2: printf("Enter new Salary:\n");
                        scanf("%f", &ptr[i].basicSalary);
                        continue;

                case 3:     printf("Returning to the Menu....\n");
                             return;
                default: printf("Invalid input\n");
                continue;
            }
         }
         return;
        }
    
        
     
    }
      printf("Employee ID not found\n");
      return;
}

void calSalary(Employee ptr[])
{
    printf("\nSalary of the Employees\n");
     printf("ID \t Name \t Net Salary\t\n");
    for(int i=0;i<count;i++)
    {
    float temp_Bs=ptr[i].basicSalary;
    float netSalary= temp_Bs + 0.4*temp_Bs + 0.2*temp_Bs + 0.05*temp_Bs;
   
    printf("%d \t %s \t %f \n", ptr[i].ID,ptr[i].name,netSalary);

   // printf("Date of Joining: %d %d %d\n", ptr[i].hire.day,ptr[i].hire.month,ptr[i].hire.year);
    }
}

void shift(Employee ptr[],int index)
{
    for(int i=index;i<count-1;i++)
    {
        ptr[i].ID=ptr[i+1].ID;
        strcpy(ptr[i].name,ptr[i+1].name);
        ptr[i].basicSalary=ptr[i+1].basicSalary;
        ptr[i].hire.day=ptr[i+1].hire.day;
        ptr[i].hire.month=ptr[i+1].hire.month;
        ptr[i].hire.year=ptr[i+1].hire.year;
    }
}
void deleteEmployee(Employee ptr[], int ID)
{
    for(int i=0;i<count;i++)
    {
        if(ptr[i].ID==ID)
        {
            printf("Employee To be deleted:\n");
            viewByID(ptr,ID);

            shift(ptr,i);
            count--;
            printf("Employee deleted.\n");
            return;
        }
    
    }
      printf("Employee ID not found\n");
      return;
}
