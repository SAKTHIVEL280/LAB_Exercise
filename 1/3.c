#include <stdio.h>
#define MAX_GRADES 100
typedef struct {
    int grades[MAX_GRADES];
    int size;
} GradeList;
void addGrade(GradeList *list, int grade) {
    if (list->size < MAX_GRADES) {
        list->grades[list->size] = grade;
        list->size++;
    } else {
        printf("Grade list is full.\n");
    }
}
double calculateAverage(GradeList *list) {
    int sum = 0;
    for (int i = 0; i < list->size; i++) {
        sum += list->grades[i];
    }
    return (double)sum / list->size;
}
void displayGrades(GradeList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("Grade: %d\n", list->grades[i]);
    }
}
int main() {
    GradeList myGrades;
    myGrades.size = 0;
    addGrade(&myGrades, 85);
    addGrade(&myGrades, 90);
    addGrade(&myGrades, 78);
    printf("Grades:\n");
    displayGrades(&myGrades);
    printf("Average Grade: %.2f\n", calculateAverage(&myGrades));
    return 0;
}
