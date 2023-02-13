#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 40

typedef struct {
    int code;
    char name[MAX_NAME_LENGTH];
    float grade1;
    float grade2;
} Student;

int readStudentsFromFile(char *fileName, Student **students) {
    FILE *fp;
    int n = 0;

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fscanf(fp, "%d", &n);
    *students = (Student *) malloc(n * sizeof(Student));

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &(*students)[i].code);
        fscanf(fp, "%s", (*students)[i].name);
        fscanf(fp, "%f", &(*students)[i].grade1);
        fscanf(fp, "%f", &(*students)[i].grade2);
    }

    fclose(fp);
    return n;
}

float average(Student s) {
    return (s.grade1 + s.grade2) / 2;
}

float classAverage(Student *students, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += average(students[i]);
    }
    return sum / n;
}

void listAboveAverage(Student *students, int n, float avg) {
    for (int i = 0; i < n; i++) {
        float studentAvg = average(students[i]);
        if (studentAvg > avg) {
            printf("Código: %d\n", students[i].code);
            printf("Nome: %s\n", students[i].name);
            printf("Média: %.2f\n", studentAvg);
            printf("Média da turma: %.2f\n\n", avg);
        }
    }
}

int main(int argc, char *argv[]) {
    Student *students;
    int n;
    float avg;

    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        exit(1);
    }

    n = readStudentsFromFile(argv[1], &students);
    avg = classAverage(students, n);
    listAboveAverage(students, n, avg);

    free(students);
    return 0;
}
