#include <stdio.h>
#include "Ex1.h"
#include  <math.h>
#include <string.h>
#include <stdlib.h>


/*Crie uma função chama reports que receba um vetor de estruturas de alunos de um
determinado curso. A estrutura deve conter o código do aluno, o seu nome, a nota da primeira prova, a nota da
segunda prova e nota da terceira prova. A função deverá:
(a) Permitir ao usuario entrar com os dados de 5 alunos.
(b) Encontrar e imprimir os dados do aluno com maior nota da primeira prova.
(c) Encontrar e imprimir os dados do aluno com maior media geral.
(d) Encontrar e imprimir os dados do aluno com menor media geral.
(e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para aprovação. Apresente esta
informação na forma de uma tabela.
Sugere-se que seja criada uma função para popular os dados dos alunos. A estrutura e as assinaturas das
funções devem ser as seguintes:

typedef struct {
    long code;
    char name[100];
    float grade1;
    float grade2;
    float grade3;
} Student;    

//void populate_students (Student *students);
//void reports (Student *students);


Dica: Para ler strings contendo espaços, utilize a instruçao: scanf("%[A-Z a-z]",str);
*/

int main(){

    Student students [POPULATION_STUDENTS];
   // float avg_grade = 0, index_max_grade = 0, idex_min_grade = 0;

    populate_students (students);

//    bestgrade1();

//    lowestgradeaverage();

//    highestgradeaverage();

//    reports (Student *students);




    
}

