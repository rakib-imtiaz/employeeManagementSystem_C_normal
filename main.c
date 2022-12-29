#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///Employee management system

struct Employee
{
    char name[100];
    int empID;
    double salary;
    double wagesPerHour;
    int workingDayPerWeek;

} empArray[100];

int size=0;

void menu()
{
    printf("\n\n1.Add Employee\n");
    printf("2.Display all Employee information\n");
    printf("3.Delete Employee By Id\n");
    printf("4.Show monthly Salary of All Avaible Employees\n");
   // printf("5.Save Employee Information to File\n");
    //printf("6.Read Employee Information from File\n");
    printf("7.Exit");
}
void addEmployee()
{
    printf("Enter Employee Name : ");
    scanf("%s",empArray[size].name);
    printf("Enter Employee ID : ");
    scanf("%d",&empArray[size].empID);
    printf("Enter Working day per week : ");
    scanf("%d",&empArray[size].workingDayPerWeek);
    printf("Enter Wages per hour : ");
    scanf("%lf",&empArray[size].wagesPerHour);
    empArray[size].salary=empArray[size].workingDayPerWeek*empArray[size].wagesPerHour*4.00;
    //printf("%.2lf",empArray[size].salary);
    printf("\n");
    size++;
    printf("\nEMPLOYEE ADDED !\n");


}
void display()
{
    printf("Employee Information : \n\n");
    printf("Total Employee :  %d\n",size);
    for(int i=0; i<size; i++)
    {
        printf("--------------------------------------------------------\n");

        printf("Employee No             :  %d\n",i+1);
        printf("Employee Name           :  %s\n",empArray[i].name);
        printf("Employee ID             :  %d\n",empArray[i].empID);
        printf("Working day per week    :  %d\n",empArray[i].workingDayPerWeek);
        printf("Wages per hour          :  %.2lf\n",empArray[i].wagesPerHour);
        printf("Salary                  :  %.2lf\n",empArray[i].salary);
        printf("--------------------------------------------------------\n");

    }


}

void showMonthlySalaryofAllEmployee()
{
    printf("\n-----------------------------------------\n");
    printf("MONTHLY SALARY OF ALL EMPLOYEE:  ");
    printf("\n-----------------------------------------\n");
    printf("Total Available Employee:  %d\n\n\n",size);
    for(int i=0; i<size; i++)
    {
        printf("\n--------------------------------------------\n");

        printf("Employee No     : %d\n",i+1);
        printf("Employee Name   : %s\n",empArray[i].name);
        printf("Salary          : %.2lf\n",empArray[i].salary);
        printf("\n--------------------------------------------\n");

    }


}
void readDataFromFile()
{
    FILE *file;
    file=fopen("EMP_INFORMATION.txt","r");
    if(file==NULL)
    {
        printf("You haven't added anything to the file yet... \nAdd some data, save it and read it later. Thanks!\n");
        //fclose(file);
        //return;
        exit(1);
    }
    else
    {

        while(fscanf(file,"%s %d %lf %d %lf",empArray[size].name,&empArray[size].empID,&empArray[size].wagesPerHour,&empArray[size].workingDayPerWeek,&empArray[size
                                                                                                                                                               ].salary)!=EOF)
        {
            //printf("Name:  %s\n",empArray[size].name);
            size++;
        }

        printf("THE FILE HASBEEN READ SUCCESSFULLY! YOU CAN NOW DISPLAY THE INFORMATION\n");

    }

    fclose(file);




}
void saveInformationToFile()
{
    FILE *file;
    file=fopen("EMP_INFORMATION.txt","a");
    for(int i=0; i<size; i++)
    {

        fprintf(file,"%s %d %.2lf %d %.2lf\n",empArray[i].name,empArray[i].empID,empArray[i].wagesPerHour,empArray[i].workingDayPerWeek,empArray[i].salary);

    }
    fclose(file);

    printf("Saved to file successfully!");


}
int searchBYid(int id)
{
    int index=-1;


    for(int i=0; i<size; i++)
    {
        if(empArray[i].empID==id)
        {

            index=i;
            return index;
        }


    }

    return index;


}
void deleteEmployeeByID()
{
    int targetID;
    printf("Enter ID to Delete : ");
    scanf("%d",&targetID);

    int index=searchBYid(targetID);

    if(index!=-1)
    {

        for(int i=index; i<size; i++)
        {
            empArray[i]=empArray[i+1];

        }
        size--;

    }
    else
    {

        printf("ID NOT FOUND");
    }






}
void test()
{

    strcat(empArray[0].name,"rakib");
    empArray[0].empID=101;
    empArray[0].wagesPerHour=100;
    empArray[0].workingDayPerWeek=4;
    empArray[0].salary=400;

    strcat(empArray[1].name,"sakib");
    empArray[1].empID=102;
    empArray[1].wagesPerHour=101;
    empArray[1].workingDayPerWeek=4;
    empArray[1].salary=400;

    strcat(empArray[2].name,"rafasn");
    empArray[2].empID=103;
    empArray[2].wagesPerHour=102;
    empArray[2].workingDayPerWeek=4;
    empArray[2].salary=400;
    size=3;


}

int main()
{

    int option=0;

    printf("|-----------------------------------------|\n");
    printf("|  WELCOME TO EMPLOYEE MANAGEMENT SYSTEM! |\n");
    printf("|-----------------------------------------|\n");

    while(option!=7)
    {
        menu();
        printf("\nEnter your option: \n");
        scanf("%d",&option);


        if(option==1)
        {
            addEmployee();
        }
        else if(option==2)
        {
            display();
        }
        else if(option==3)
        {
            deleteEmployeeByID();
        }
        else if(option==4)
        {
            showMonthlySalaryofAllEmployee();
        }
        else if(option==5)
        {
            saveInformationToFile();
        }
        else if(option==6)
        {
            readDataFromFile();
        }
        else if(option==7)
        {
            printf("|-------------------------------------|\n");
            printf("|  THANKS FOR USING THE APPLICATION!  |\n");
            printf("|-------------------------------------|\n");
            exit(1);
        }
        else
        {
            printf("INVALID OPTION\n");
        }


    }





    return 0;
}
