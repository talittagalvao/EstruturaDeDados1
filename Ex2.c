#include <stdio.h>
#include "final_ex1.h"
#include  <math.h>
#include <string.h>
#include <stdlib.h>

int main(){

    Team Teams [POPULATION_TEAMS];

    printf ("Bem vindo ao programa que analisa pontos de times.\nPor favor, insira dados dos times:\n\n");

    populate_teams (Teams);
    
    //geraltable_ex2(Teams);

    int winnerteam = tournment (Teams);
    
    printf ("\n\n\t-------> Time vencedor: Time %d! <-------\n\n", (winnerteam+1));

    goodbye_greeting();

    return 0;
}
