#include<stdio.h>
#include<stdbool.h>
#include"employeeDataType.h"
#include"validate.h"
#include<ctype.h>
#include<string.h>
//function to validate salary
bool validateSalary(int salary)
{
    if(salary<0)
    {
        printf("Salary cannot be negative\n");
        return false;
    }
    return true;
}
//function to validate ID
bool validateID(int ID)
{
    int temp=ID;
    int size=0;

    //check if the ID is unique
    for(int i=0;i<count;i++)
    {
        if(ID==E[i].ID)
        {
            printf("ID already EXIST, Enter a new one\n");
            return false;
        }
    }
    //check if the ID is of size 4
    while(temp)
    {
        size++;
        temp=temp/10;
    }
    if(size!=4)
    {
        printf("Enter a numeric ID of size 4\n");
        return false;
    }
    //check if the ID is not negative
    if(ID<0)
    {
        printf("ID cannot be negative\n");
        return false;
    }
    return true;
}

//function to validate Name
bool validateName(char name[])
{
    printf("strlen(name)\n");
    for(size_t i=0;i<strlen(name);i++)
    {
        if((isdigit(name[i]) && name[i]!=' '))
        {
            printf("Name cannot contain anything other than alphabets.\n");
            return false;
        }
        return true;
    }
}
//function validate the date
bool validateDate(int day, int month, int year)
{
    if(day>31 || day<1)
    {
        printf("INVALID DAY\n");
        return false;
    }
    if(month<1 || month>12)
    {
        printf("INVALID DAY\n");
        return false;
    }
    if(year<1890 || year>2200)
    {
        printf("INVALID Year\n");
        return false;
    }
    //validating for feb
    if(month==02)
    {
        if(day>28)
        return false;
    }

//validating days in a month
    switch(day)
    {
        case 31: if(month==4 || month==6 || month==9 || month==11 || month==2)
        printf("This month cannot have 31 days. Enter Valid date.\n");
        return false;
        case 30: if(month==1 || month==2 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
         printf("This month cannot have 30 days. Enter Valid date.\n");
        return false;
        default:
        break;
    }
    return true;

}