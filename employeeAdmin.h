#include<stdio.h>
#include<string.h>
#include "employeeDataType.h"

void addEmployee(Employee *ptr);
void deleteEmployee(Employee ptr[], int ID);
void updateEmployee(Employee ptr[],int ID);
void viewAllEmployee(Employee ptr[]);
void viewByID(Employee ptr[],int ID);
void calSalary(Employee ptr[]);
//void calSal_ID(Employee *ptr,int ID);