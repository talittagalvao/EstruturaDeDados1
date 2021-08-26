#include <stdio.h>
#include "prova_a1.h"
#include  <math.h>
#include <string.h>
#include <stdlib.h>


int main (){

    int exe;
    Student Students [POPULATION_STUDENTS];
    Info InfoStudents [POPULATION_STUDENTS];
    Team Teams [POPULATION_TEAMS];
    int op;
    int N = 10;
    int v[N];
    int max;
    int min;
    int request;
    int vector[VECTOR_SIZE] = {5, 12, 25, 30, 46, 83, 89, 90};
    int answer;
    int x, y;

    printf("Ola!\nEste e um compilado programas para avaliacao A1.\n\n");
    //Talitta Galvão Reis de Oliveira
    // Universidade Veiga de Almeida - Ciências da Computação
    //2021.1 - Estrutura de Dados

    do{
       
        printf("Digite o numero da questao que deseja fazer:\n");
        printf("\t1 - Para um programa que analisa notas de alunos\n");
        printf("\t2 - Para um programa que analisa pontos de times de futebol\n");
        printf("\t3 - Para um programa que analisa valores de um vetor\n");
        printf("\t4 - Para um programa que localiza um elemento em um vetor\n");
        printf("\t5 - Para um programa que realiza multiplicacao entre inteiros\n");
        printf("\t0 - Para SAIR\n");
        printf("Resposta: ");
        scanf ("%d", &exe);

        switch (exe) {
        
        case 1:

            stars();
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
            setbuf(stdin, NULL);
            break;

        case 2:

            stars();
            printf ("Bem vindo ao programa que analisa pontos de times.\nPor favor, insira dados dos times:\n\n");
            populate_teams (Teams);
            int winnerteam = tournment (Teams);
            printf ("\n\n\t-------> Time vencedor: Time %d! <-------\n\n", (winnerteam+1));

            goodbye_greeting();
            setbuf(stdin, NULL);
            break;

        case 3:
            
            stars();
            printf ("Bem vindo ao programa que analisa valores de um vetor.\nPor favor, insira valores inteiros:\n\n");
            max_min (v, N, &max, &min);
            printf_vector (v, N);
            printf("\n\n\t------> O valor maximo: %d\n\t------> O valor minimo: %d\n\n", max, min);

            goodbye_greeting();
            setbuf(stdin, NULL);
            break;

        case 4: 

            stars();
            printf ("Bem vindo ao programa que localiza um elemento em um vetor previamente inserido.\n\n");
            printf("Digite o elemento procurado: ");
            scanf("%d", &request);
            answer = bin_search(vector, 0, VECTOR_SIZE-1, request);

            if (answer == -1){
                printf("Elemento nao esta presente na lista!\n"); 
                printf_vector (vector, VECTOR_SIZE);
            } else{
                printf("Posicao do elemento digitado >>>> %d\n", answer+1);
                printf_vector (vector, VECTOR_SIZE);
            }

            goodbye_greeting();
            setbuf(stdin, NULL);
            break;
        case 5:
            
            stars();
            printf ("Bem vindo ao programa que realiza multiplicacao entre inteiros:.\n\n");

            printf(">Digite o primeiro valor inteiro: ");
            scanf("%d", &x);
            printf(">Digite o segundo valor inteiro: ");
            scanf("%d", &y);
            printf("\n>>>>> Resultado: %d x %d = %ld <<<<<", x, y, multiplication(x, y));
    
            goodbye_greeting();
            setbuf(stdin, NULL);
            break;
        case 0:
            stars();
            printf("Voce escolheu sair!\nObrigada!\n\nFIM DE PROGRAMA\n");
            stars();
            break;
        
        default:
            printf("Opcao invalida!\nTente novamente!\n");
            setbuf(stdin, NULL);
            break;
        }

    } while (exe != 0);

    return 0;
}