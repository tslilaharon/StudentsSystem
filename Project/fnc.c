#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"
//קריאה מקובץ
void fileR()
{
    FILE* inf;
    Student inp;
    inf = fopen("main.txt", "rb");
    if (inf != NULL) {
        while (fread(&inp, sizeof(struct Student), 1, inf))
            Add(inp.id, inp.name, inp.lastname, inp.address, inp.phone, inp.avarage, inp.age, inp.day, inp.month, inp.year);
    }
    if (inf != NULL) {
        fclose(inf);
    }
}
void StudentDetails(Student* student)
{
    printf("id: %d\n", student->id);
    printf("Name: %s\n", student->name);
    printf("Last Name: %s\n", student->lastname);
    printf("age: %d\n", student->age);
    printf("address: %s\n", student->address);
    printf("avarage: %0.4f\n", student->avarage);
    printf("Phone: %s\n", student->phone);
    printf("%d/", student->day);
    printf("%d/", student->month);
    printf("%d \n", student->year);
}
//הוספת סטודנט
void AddStudent()
{
    int Studentid, age, day, month, year;
    char name[100], lastname[100], address[100], phone[100];
    float avarage;
    printf("\nPlease enter all Student details\n");
    printf("Id:\n");
    scanf("%d", &Studentid);
    printf("First name:\n");
    scanf("%s", name);
    printf("Last Name:\n");
    scanf("%s", lastname);
    printf("Age:\n");
    scanf("%d", &age);
    printf("Address:\n");
    scanf("%s", address);
    printf("Phone:\n");
    scanf("%s", phone);
    printf("Avarage:\n");
    scanf("%f", &avarage);
    printf("Date of start of studies:\n");
    scanf("%i/%i/%i", &day, &month, &year);


    Add(Studentid, name, lastname, phone, address, avarage, age, day, month, year);
}
//עדכון ממוצע של סטודנט
void AverageUpdate()
{
    int Studentid;
    printf("-----------------------------------------------\n");
    printf("Please enter the student ID to update the average:\n ");
    printf("-----------------------------------------------\n");
    scanf("%d", &Studentid);
    Student* student;
    if ((student = Search(Studentid)) != NULL)
    {
        float average;
        printf("Enter New Avarage: \n");
        scanf("%f", &average);
        UpAvargae(student, average);
    }
    else
    {
        printf("Student ID - %d - was not found so the average cannot be updated\n", Studentid);
    }
}
//הצגת סטודנט
void SearchStudent()
{
    int Studentid;
    printf("Please enter the student ID to view the student details\n");
    scanf("%d", &Studentid);
    Student* student;
    if ((student = Search(Studentid)) != NULL)
    {
        printf("\n-------------------------------\n");
        printf("Student details - %s %s - \n", student->name, student->lastname);
        printf("-------------------------------\n");
        printf("the student details: \n");
        StudentDetails(student);
    }
    else
    {
        printf("Student ID - %d - was not found so the student details are not viewable\n", Studentid);
    }
}
//הצגת כל הסטודנטים
void PrintAllStudents()
{
    Student* student = get_head();
    while (student != NULL)
    {
        printf("\n-------------------------------\n");
        printf("Student details - %s %s - \n", student->name, student->lastname);
        printf("-------------------------------\n");
        StudentDetails(student);
        student = get_next(student);
    }
    printf("\n\No more student details can be viewable\n");
}
//מחיקת סטודנט
void DeleteStudent()
{
    int Studentid;
    printf("-----------------------------------------------\n");
    printf("Please enter the student ID to delete a student\n");
    printf("------------------------------------------------\n");
    scanf("%d", &Studentid);

    if (Delete(Studentid))
    {
        printf("ID - %d - Student deletion completed\n", Studentid);
    }
    else
    {
        printf("Student ID - %d - was not found so the student deletion not completed\n", Studentid);
    }
}
//מחיקת כל הסטודנטים
void DeleteAllStudents()
{
    Deletealist();
    printf("deletion completed\n");
    printf("All the students deleted\n");
}
//הצגת סטטיסטיקה
void ViewStatistics()
{

    int Count = 0;
    float SumGrades = 0, AllAvarage = 0 , max = 0;
    Student* temp = get_head();
     max = temp->avarage;
    while (temp != NULL)
    {
        if (temp->avarage > max)
        {
            max = temp->avarage;
        }
        temp = temp->next;
    }
    temp = get_head();
    while (temp != NULL)
    {
        if (temp->avarage == max)
        {
            printf("Highest grades of students:\n");
            printf("----------------------------\n");
            printf("%f\n", temp->avarage);
        }
        temp = get_next(temp);
    }
    temp = get_head();
    while (temp != NULL)
    {
        SumGrades += temp->avarage;
        Count++;
        temp = get_next(temp);
    }
    AllAvarage = SumGrades / Count;
    printf("Average of all students is: %f\n", AllAvarage);
    printf("-------------------------------\n");
    temp = get_head();
    printf("All students whose average is less than -60- :\n");
    printf("--------------------------------------------\n");
    while (temp != NULL)
    {
        if (temp->avarage < 60)
        {
            StudentDetails(temp);
        }
        temp = get_next(temp);
    }
}
//יציאה 
//כתיבה לקובץ
void Exit()
{
    FILE* fptr;
    Student* temp = get_head();
    fptr = fopen("main.txt", "wb");
    while (temp != NULL)
    {
        fwrite(temp, sizeof(struct Student), 1, fptr);
        temp = get_next(temp);
    }
    printf("GoodBye");
    Deletealist();
    fclose(fptr);
}
