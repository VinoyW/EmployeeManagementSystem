int count=0;
#define MAX 100

struct Date
{
    int day;
    int month;
    int year;
};
typedef struct Employees
{
    char name[35];
    int ID;
    float basicSalary;
    struct Date hire;
} Employee;

Employee E[MAX];
