#include <stdio.h>
#include "final_ex1.h"
#include  <math.h>
#include <string.h>
#include <stdlib.h>

int main(){

    Student Students [POPULATION_STUDENTS];
    Info InfoStudents [POPULATION_STUDENTS];
    int op;

    printf ("Bem vindo ao programa que analisa notas.\nPor favor, insira dados de alunos:\n\n");
    
    populate_students (Students);
    avg_students (Students, InfoStudents);
    status_students(InfoStudents);  
   
    do{
        printf ("Escolha um item de analise:\n\t1 - Melhor nota na primeira prova;\n\t2 - Media Geral mais baixa;\n\t3 - Media Geral mais alta;\n\t4 - Avaliacao geral;\n\t5 - Sair.\nResposta: ");

        scanf("%d", &op);
        reports (Students, InfoStudents, op);

    } while (op!=5);  

    goodbye_greeting();

    return 0;
    
}   


