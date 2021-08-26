#include <stdio.h>
#include  <math.h>
#include <string.h>
#include <stdlib.h>
#define POPULATION_STUDENTS 5
#define POPULATION_TEAMS 2
#define SEPARADOR -10
#define SEPARADOR_NAME -50
#define GRADES 3.0
#define MEDIA 6.0
#define GRADEMAX 10
#define GRADEMIN 0
#define VICTORYPOINT 3
#define DRAWPOINT 1
#define DEFEATPOINT 0
#define P 10

typedef struct {
    long code;
    char name[100];
    float grade1;
    float grade2;
    float grade3;
} Student;  

typedef struct {
    float avg_grade;
    char status;
} Info; 

typedef struct {
    long code; 
    char name[100];
    int victories;
    int draws;
    int defeats;
    int goal_diff;
} Team;


void flush_in();
void espaco();
void printf_vector (int vector[], int size);
void goodbye_greeting();

void populate_students (Student *Students);
void populate_teams (Team *Teams);

void reports(Student *Students, Info *InfoStudents, int op);
int tournment (Team *Teams);

void geraltable_ex1 (Student *Students, Info *InfoStudents);
void geraltable2_ex2 (Team *Teams);

void tableheader_ex1();
//void tableheader_ex2();

void tablebody_ex1(Student *Students, Info *InfoStudents, int i);
//void tablebody_ex2(Team *Teams, int i, int points [POPULATION_TEAMS]);

void infobase_ex1();
void infobase_ex2();

void status_students(Info *InfoStudents);
void bestgrade1(Student *Students, Info *InfoStudents);
void avg_students (Student *Students, Info *InfoStudents);
void lowestgradeaverage(Student *Students, Info *InfoStudents);
void highestgradeaverage(Student *Students, Info *InfoStudents);


void espaco(){
    printf("---------------------------------------------------------\n");
}

void flush_in() {
    int ch;

    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
    
}

void printf_vector (int vector[], int size){
    int i;
    printf("Vetor: { ");
    for (i=0; i<size; i++){
        printf("%d, ", vector[i]);
    }
    printf("}");
}

void goodbye_greeting(){
    printf("\n\nFim do programa\n");
    printf("Obrigada!\nAte a proxima!\n");
}

void tableheader_ex1(){
    printf("[%*s][%*s][%*s][%*s][%*s][%*s][%*s]\n", 
        SEPARADOR, "Codigo", 
        SEPARADOR_NAME, "Nome", 
        SEPARADOR, "Nota 1", 
        SEPARADOR, "Nota 2",
        SEPARADOR, "Nota 3",
        SEPARADOR, "Media",
        SEPARADOR, "Status"   
    );
}

/* void tableheader_ex2(){
    printf("[%*s][%*s][%*s][%*s][%*s][%*s][%*s]\n", 
        SEPARADOR, "Codigo do Time", 
        SEPARADOR_NAME, "Nome do Time", 
        SEPARADOR, "Vitorias", 
        SEPARADOR, "Empates",
        SEPARADOR, "Derrotas",
        SEPARADOR, "Saldo de Gols",
        SEPARADOR, "Pontuacao Final"   
    );
}
*/

void tablebody_ex1(Student *Students, Info *InfoStudents, int i){
    printf("[%*ld][%*s][%*.2f][%*.2f][%*.2f][%*.2f][%*c]\n", 
    SEPARADOR, Students[i].code, 
    SEPARADOR_NAME, Students[i].name, 
    SEPARADOR, Students[i].grade1, 
    SEPARADOR, Students[i].grade2,
    SEPARADOR, Students[i].grade3,
    SEPARADOR, InfoStudents[i].avg_grade,
    SEPARADOR, InfoStudents[i].status    
    );
}

/* void tablebody_ex2(Team *Teams, int i, int points [POPULATION_TEAMS]){
    
    printf("[%*ld][%*s][%*d][%*d][%*d][%*d][%*d]\n", 
    SEPARADOR, Teams[i].code
    SEPARADOR_NAME, Teams[i].name
    SEPARADOR, Teams[i].victories, 
    SEPARADOR, Teams[i].draws,
    SEPARADOR, Teams[i].defeats,
    SEPARADOR, Teams[i].goal_diff,
    SEPARADOR, points[i] = ((Teams[i].victories*VICTORYPOINT) + (Teams[i].draws*DRAWPOINT) + (Teams[i].defeats*DEFEATPOINT))  
    );
}
*/

void infobase_ex1(){
    printf("Media Considerada: >=%.2f\n\nStatus Aluno:\n\tA: Aprovado\n\tR: Reprovado\n", MEDIA);
    printf("\n-->Notas validas: 0.00 a 10.00<--\n\n");
}

void infobase_ex2(){
    printf("Quantidade de partidas consideradas: %d\n\n", P);
    printf("Valores ponto considerados:\n\tVitorias = +%d;\n\tEmpates = +%d;\n\tDerrota = +%d.\n\n", VICTORYPOINT, DRAWPOINT, DEFEATPOINT);
}

void populate_students (Student *Students){

    printf("------------------- Inseririndo Dados -------------------\n");
    
    infobase_ex1();
    
    for (int i = 0; i < POPULATION_STUDENTS; i++){
        printf("Codigo do aluno %d: ", i + 1);
        scanf("%ld", &Students[i].code);

        printf("Insira o nome do aluno %d: ", i + 1);
        flush_in();
        scanf("%[A-Z a-z]", Students[i].name);
        flush_in();

        int valid = 0;
        do {
            printf("Insira a nota 1 do aluno %d: ", i + 1);
            scanf("%f", &Students[i].grade1);
            ((Students[i].grade1 <= GRADEMAX) && (Students[i].grade1 >= GRADEMIN)) ? (valid = 1) : (valid = 0);
            if (!valid){
                printf("Valor invalido! Digite novamente.\n");
            }
        } while(!valid);
        do {
            printf("Insira a nota 2 do aluno %d: ", i + 1);
            scanf("%f", &Students[i].grade2);
            ((Students[i].grade2 <= GRADEMAX) && (Students[i].grade2 >= GRADEMIN)) ? (valid = 1) : (valid = 0);
            if (!valid){
                printf("Valor invalido! Digite novamente.\n");
            }
        } while(!valid);
        do {
            printf("Insira a nota 3 do aluno %d: ", i + 1);
            scanf("%f", &Students[i].grade3);
            ((Students[i].grade3 <= GRADEMAX) && (Students[i].grade3 >= GRADEMIN)) ? (valid = 1) : (valid = 0);
            if (!valid){
                printf("Valor invalido! Digite novamente.\n");
            }
        } while(!valid);
        espaco();
    }
}

void populate_teams (Team *Teams){

    infobase_ex2();

    printf("------------------- Inseririndo Dados -------------------\n");

    for (int i = 0; i < POPULATION_TEAMS; i++){
        printf("Codigo do time %d: ", i + 1);
        scanf("%ld", &Teams[i].code);

        printf("Insira o nome do time %d: ", i + 1);
        flush_in();
        scanf("%[A-Z a-z]", Teams[i].name);
        flush_in();

        int valid = 0;      

        do{

            printf ("->Distribua os resultados das %d partidas de jogo<-\n", P);

            do {
                printf("Insira a quantidade de vitorias time %d: ", i + 1);
                scanf("%d", &Teams[i].victories);
                ((Teams[i].victories >= GRADEMIN)) ? (valid = 1) : (valid = 0);
                if (!valid){
                    printf("Valor invalido! Digite novamente.\n");
                }
            } while(!valid);
            do {
                printf("Insira a quantidade de empates do time %d: ", i + 1);
                scanf("%d", &Teams[i].draws);
                ((Teams[i].draws >= GRADEMIN)) ? (valid = 1) : (valid = 0);
                if (!valid){
                    printf("Valor invalido! Digite novamente.\n");
                }
            } while(!valid);
            do {
                printf("Insira a quantidade de derrotas do time %d: ", i + 1);
                scanf("%d", &Teams[i].defeats);
                ((Teams[i].defeats >= GRADEMIN)) ? (valid = 1) : (valid = 0);
                if (!valid){
                    printf("Valor invalido! Digite novamente.\n");
                }
            } while(!valid);

        }while ((Teams[i].defeats + Teams[i].victories + Teams[i].draws) != P );  

        do {
            printf("Insira o saldo de gols do time %d: ", i + 1);
            scanf("%d", &Teams[i].goal_diff);
            ((Teams[i].goal_diff >= GRADEMIN)) ? (valid = 1) : (valid = 0);
            if (!valid){
                printf("Valor invalido! Digite novamente.\n");
            }
        } while(!valid);
        espaco();
    }
}

void avg_students (Student *Students, Info *InfoStudents){
    for (int i = 0; i < POPULATION_STUDENTS; i++){    
        InfoStudents[i].avg_grade = ((Students[i].grade1 + Students[i].grade2 + Students[i].grade3)/GRADES);
    }

}

void status_students(Info *InfoStudents){
    for (int i = 0; i < POPULATION_STUDENTS; i++){
        if(InfoStudents[i].avg_grade >= MEDIA ){
            InfoStudents[i].status = 'A'; 
        } else{
            InfoStudents[i].status = 'R';
        }
    }
}

void bestgrade1(Student *Students, Info *InfoStudents){
    float bestgrade1 = Students[0].grade1;

    for (int i = 1; i < POPULATION_STUDENTS; i++){
        if (bestgrade1 < Students[i].grade1){
            bestgrade1 = Students[i].grade1;
        } 
    }
    espaco();
    printf("\n---------- Maior nota da primeira prova: %.2f ----------\n", bestgrade1);
    infobase_ex1();
    tableheader_ex1();

    for (int i = 0; i < POPULATION_STUDENTS; i++){
        if (Students[i].grade1 == bestgrade1){
            tablebody_ex1(Students, InfoStudents, i);
        }
    }   
}

void lowestgradeaverage(Student *Students, Info *InfoStudents){
    
    float lowestgradeavg = InfoStudents[0].avg_grade;

    for (int i = 1; i < POPULATION_STUDENTS; i++){
        if (lowestgradeavg > InfoStudents[i].avg_grade){
            lowestgradeavg = InfoStudents[i].avg_grade;
        } 
    }

    printf("\n------------- Menor media das provas: %.2f -------------\n", lowestgradeavg);
    infobase_ex1();
    tableheader_ex1();

    for (int i = 0; i < POPULATION_STUDENTS; i++){
        if (InfoStudents[i].avg_grade == lowestgradeavg){
            tablebody_ex1(Students, InfoStudents, i);
        }
    }
}

void highestgradeaverage(Student *Students, Info *InfoStudents){
    
    float highestgradeavg = InfoStudents[0].avg_grade;

    for (int i = 1; i > POPULATION_STUDENTS; i++){
        if (highestgradeavg > InfoStudents[i].avg_grade){
            highestgradeavg = InfoStudents[i].avg_grade;
        } 
    }

    printf("------------- Maior media das provas: %.2f -------------\n", highestgradeavg);
    infobase_ex1();
    tableheader_ex1();

    for (int i = 0; i < POPULATION_STUDENTS; i++){
        if (InfoStudents[i].avg_grade == highestgradeavg){
           tablebody_ex1(Students, InfoStudents, i); 
        }
    }
}

void geraltable_ex1 (Student *Students, Info *InfoStudents){
        
    printf("\n---------- Tabela de todos os alunos cadastrados ----------\n");
    infobase_ex1();
    tableheader_ex1();

    for (int i = 0; i < POPULATION_STUDENTS; i++){
        tablebody_ex1(Students, InfoStudents,i);
    }
  
}

/*void geraltable_ex2 (Team *Teams){
        
    printf("\n---------- Tabela de todos os times cadastrados ----------\n");
    infobase_ex2();
    tableheader_ex2();
    int points[POPULATION_TEAMS];

    for (int i = 0; i < POPULATION_STUDENTS; i++){
        tablebody_ex2(Teams, i, points);
    }
  
}*/

void reports(Student *Students, Info *InfoStudents, int op){
    switch (op) {
        case 1:
            bestgrade1 (Students, InfoStudents);
            espaco();
            break;
        case 2:
            lowestgradeaverage(Students, InfoStudents);
            espaco();
            break;
        case 3:
            highestgradeaverage(Students, InfoStudents);
            espaco();
            break;
        case 4:
            geraltable_ex1(Students, InfoStudents);
            espaco();
            break;
        case 5:
            printf("\n\nVoce escolheu sair.\n\n");
            espaco();
            printf("Obrigada!\nAte a proxima!");
            break;
        default:
            printf("\nInvalido!\nEscolha Novamente.\n\n");
            espaco();
            break;

    }
}

int tournment (Team *Teams){
//void tournment (Team *Teams){

    // vetor que guarda o calculo de pontos
    int points [POPULATION_TEAMS]; 
    for (int i = 0; i < POPULATION_TEAMS; i++){    
        points[i] = ((Teams[i].victories*VICTORYPOINT) + (Teams[i].draws*DRAWPOINT) + (Teams[i].defeats*DEFEATPOINT));
    }

    // iniciando a maior pontuação com o primeiro cálculo de pontos
    int highestscore = points[0];
    int winnergoals = 0;

    //definindo a maior pontuação
    for (int hs = 1; hs < POPULATION_TEAMS; hs++){
        if (highestscore < points[hs]){
            highestscore = points[hs];
            if(winnergoals < Teams[hs].goal_diff){
                winnergoals = Teams[hs].goal_diff;
            }
        } 
    }
    
    int count = 0;
    int count2 = 0;
    for (int c = 1; c < POPULATION_TEAMS; c++){
        if(points[c] == highestscore){
            count++;
        } if(Teams[c].goal_diff == winnergoals){
            count2++;
        }
    }

    int winner = 0;

    if (count == 1){
        for (int w = 0; w < POPULATION_TEAMS; w++){
            if(points[w] == highestscore){
                winner = w;
            }
        }
    } else if (count2 == 1){
        for (int w = 0; w < POPULATION_TEAMS; w++){
            if((points[w] == highestscore) && (Teams[w].goal_diff == winnergoals)){
                winner = w;
            }
        }
    } else{
        for (int w = 0; w < POPULATION_TEAMS; w++){
            if((points[w] == highestscore) && (Teams[w].goal_diff == winnergoals)){
                winner = w;
                break;
            }
        }
    }

    return winner;

}
