/*Questão 1 (2,0 pontos) Implemente uma função que receba uma pilha p, e some todos os valores
pares guardados em p. Ao final da execução desta função, p permanecerá com todos os seus
elementos e retorna-se a soma. O protótipo desta função é o seguinte: 
int soma_par (Tstack *p);*/

#include <stdio.h>
#include "q1.h"

int main () {
    printf("Bem vindo, esse programa soma os valores pares de uma pilha.\n\n");

    Tstack *stack = create(); printf(">>Pilha criada\n");
    int elem;
    int sum;

    printf("\nVerificando se a pilha esta vazia...\n");
    empty(stack) ? printf("Pilha vazia\n\n") : printf("Pilha nao vazia\n\n");


    for (int i = 1; i <= 5; i++) {
    printf ("Insira o valor de info para o elemento da pilha: ");
    scanf ("%d", &elem);
    push (stack, elem);
    }
    
    printf("\nVerificando se a pilha esta vazia...\n");
    empty(stack) ? printf("Pilha vazia\n\n") : printf("Pilha nao vazia\n\n");

    printf("Imprimindo a pilha: \n");
    print_stack(stack);

    printf("\n");

    sum = soma_par (stack);
    printf(">> A soma dos elementos pares da pilha: %d <<\n\n", sum);
    
    printf("Imprimindo a pilha:\n");
    print_stack(stack);


    printf("\nFim de programa!\n\n");
    
    clear (stack);
    return 0;
}