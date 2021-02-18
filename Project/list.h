#ifndef LIST_H_
#define LIST_H_

typedef struct Student
{
    int id, age, day, month, year;
    char name[100], lastname[100], address[100], phone[100];
    float avarage;
    struct Student* next;
} Student;
Student* get_head();
Student* get_next(Student* current);
void Add(int id, char* name, char* lastname, char* phone, char* address, float avarage, int age, int day, int month, int year);
void UpAvargae(Student* student, float avarge);
Student* Search(int id);
int Delete(int id);
void Deletealist();


#endif
