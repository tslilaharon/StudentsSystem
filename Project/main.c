#include <stdio.h>
#include "fnc.h"

void PrintMenu()
{
    printf("\n1.Adding a student\n");
    printf("2.Average student update\n");
    printf("3.Search student\n");
    printf("4.Print all students\n");
    printf("5.Deleting a student\n");
    printf("6.Delete all students\n");
    printf("7.View statistics\n");
    printf("8.Exit\n");
}
int main()
{
    fflush(stdin);
    fileR();
    int choice = 0;
    printf("-------------------------------\n");
    printf("*Welcome to the student system*\n");
    printf("-------------------------------\n");
    do
    {
        fflush(stdin);
        PrintMenu();
        printf("\nPlease Enter your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1://����� �����
            AddStudent();
            break;
        case 2://����� �����
            AverageUpdate();
            break;
        case 3://���� ������
            SearchStudent();
            break;
        case 4://���� �� ���������
            PrintAllStudents();
            break;
        case 5://����� ������
            DeleteStudent();
            break;
        case 6://����� �� ���������
            DeleteAllStudents();
            break;
        case 7://���� ���������
            ViewStatistics();
            break;
        case 8://�����
            Exit();
            break;
        default:
            printf("*Error*\n");
            printf("Wrong Input, please try again ");
            break;
        }

    } while (choice != 8);

}
