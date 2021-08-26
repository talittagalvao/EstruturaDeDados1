#include <stdio.h>
#include  <math.h>
#include <string.h>
#include <stdlib.h>
#define POPULATION_STUDENTS 5

typedef struct {
    long code;
    char name[100];
    float grade1;
    float grade2;
    float grade3;
    float avg_grade;
} Student;  

void populate_students (Student *students);
void flush_in();
void bestgrade1();
void lowestgradeaverage();
void highestgradeaverage();
void reports (Student *students);
void average();

void populate_students (Student *students){
    for (int i = 0; i < POPULATION_STUDENTS; i++){

        printf("\nInsira o codigo do aluno %d: ", i + 1);
        scanf("%ld", &students[i].code);
        printf("Codigo digitado: %ld \n\n", students[i].code);

        printf("Insira o nome do aluno %d: ", i + 1);
        flush_in();
        scanf("%[A-Z a-z]", students[i].name);
        flush_in();
        printf("Nome digitado: %s \n\n", students[i].name);

        printf("Insira a nota 1 do aluno %d: ", i + 1);
        scanf("%f", &students[i].grade1);
        printf("Nota digitada: %.2f \n\n", students[i].grade1);

        printf("Insira a nota 2 do aluno %d: ", i + 1);
        scanf("%f", &students[i].grade2);
        printf("Nota digitada: %.2f \n\n", students[i].grade2);

        printf("Insira a nota 3 do aluno %d: ", i + 1);
        scanf("%f", &students[i].grade3);
        printf("Nota digitada: %.2f \n\n\n", students[i].grade3);

        students[i].avg_grade = 0;
        students[i].avg_grade = (students[i].grade1 + students[i].grade2 + students[i].grade3)/ 3.00;
        printf("A media das notas do aluno %d: %.2f\n", i+1, students[i].avg_grade);

    }
}

void flush_in() {
    int ch;

    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
    
}

