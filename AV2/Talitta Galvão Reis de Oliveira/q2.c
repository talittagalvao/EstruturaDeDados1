/*Questão 2 (2,0 pontos) Usando somente estas operações, escreva uma função que, dada uma fila f,
retorne uma pilha, contendo todos os elementos de f, e obedecendo a ordem de entrada dos inteiros na
fila f, isto é, o primeiro inteiro que sair da fila f deve ser o primeiro inteiro a sair da pilha. Não é possível
alterar a ordem dos elementos da fila de entrada. A função deve obedecer o seguinte protótipo: 
Tstack *Fila2Pilha (Tqueue *f);*/

#include <stdio.h>
#include "q2.h"

int main () {
    printf("Bem vindo, esse programa transforma uma fila em uma pilha.\n\n");
    Tqueue *queue = createq(); printf(">>Fila criada\n");
    Tstack *stack = create(); printf(">>Pilha criada\n\n");
    int elem;  

    printf("Verificando se a fila esta vazia...\n");
    emptyq(queue) ? printf("Fila vazia\n") : printf("Fila nao vazia\n");
    
    printf("Verificando se a pilha esta vazia...\n");
    empty(stack) ? printf("Pilha vazia\n") : printf("Pilha nao vazia\n");
    
    printf("\n");

    for (int i = 1; i <= 5; i++) {
    printf ("Insira o valor de info para o elemento da fila: ");
    scanf ("%d", &elem);
    insertq (queue, elem);
    }

    printf("\nVerificando se a fila esta vazia...\n");
    emptyq(queue) ? printf("Fila vazia\n") : printf("Fila nao vazia\n");

    printf("Imprimindo fila:\n");
    print_queue(queue);

    stack = Fila2Pilha(queue);

    printf("Transformando fila em pilha:\n");
    printf("Pilha: \n");
    print_stack(stack);
    printf("Fila original: \n");
    print_queue(queue);

    printf("Fim de programa!\n\n");

    clear (stack);
    clearq (queue); 

    return 0;

}
