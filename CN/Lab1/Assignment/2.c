#include <stdio.h>
struct dob {
    int date, month, year;
};
typedef struct student_info {
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
}Student;

void print(Student s) {
    printf("Roll no. : %d\n", s.roll_no);
    printf("Name : %s\n", s.name);
    printf("CGPA : %f\n", s.CGPA);
    printf("DOB : %d/%d/%d\n", s.age.date, s.age.month, s.age.year);
}
void input(Student *s) {
    printf("Enter roll no. : ");
    scanf("%d", &s->roll_no);
    printf("Enter name : ");
    scanf("%s", s->name);
    printf("Enter CGPA : ");
    scanf("%f", &s->CGPA);
    printf("Enter DOB : ");
    scanf("%d/%d/%d", &s->age.date, &s->age.month, &s->age.year);
}

int main() {
    Student stud;
    input(&stud);
    printf("\nEntered Details :\n");
    print(stud);
    return 0;
}