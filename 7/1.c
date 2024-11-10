#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int id;
    char name[50];
    int age;
} Student;

int findStudentByID(Student *students, int n, int id) {
    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}
int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    Student *students = (Student *)malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }
    printf("Enter student details (ID Name Age):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &students[i].id, students[i].name, &students[i].age);
    }
    int id;
    printf("Enter student ID to search: ");
    scanf("%d", &id);
    int index = findStudentByID(students, n, id);
    if (index != -1) {
        printf("Student found: ID=%d, Name=%s, Age=%d\n", students[index].id, students[index].name, students[index].age);
    } else {
        printf("Student not found.\n");
    }
    free(students);
    return 0;
}
