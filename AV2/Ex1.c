#include <stdio.h>
#include  <math.h>
#include <string.h>
#include <stdlib.h>

int *new_vector (int size){
    int *vector;
    vector = malloc (size * sizeof (int));
    return vector;
}

void populate_vector (int *v, int size){
    for (int i = 0; i < size; i++){
        printf("Digite um valor para posicao %d do vetor: ", i);
        scanf("%d", &v[i]);
    }
}

void fill_vector (int *v, int size, int new_size){
   
    for (int i = size; i < new_size; i++){
        printf("Digite um valor para posicao %d do vetor: ", i);
        scanf("%d", &v[i]);
    }
}

void print_vector(int *v, int size){
        for (int i = 0; i < size; i++){
        printf("Elemento %d do vetor: %d\n", i, v[i]);
    }
}

void *resize_vector (int *v, int new_size){
    v = realloc (v, new_size * sizeof (int));
    return v;
}


int main (){
    
    /*
    int *v, size;

    //sizeof()
    printf ("Tamanho do INT: %ld byte(s) \n", sizeof(int));

    //malloc()
    printf("Escolha do tamanho de do vetor: ");
    scanf ("%d", &size);
    v = malloc (size * sizeof (int)); //alicação de dinâmica de um vetor de tamanho size. EQv int v[size]

   //printf ("Tamanho do VETOR: %ld byte(s) \n", sizeof(*v));

    //realloc ()
    printf("Escolha o novo tamanho de do vetor: ");
    scanf("%d", &size);
    v = realloc (v, size * sizeof (int)); //nesse caso o vetor passaria a ter 2000 posições

    //liberar vetor
    free(v);

    return 0;
    */

    int *v, size, new_size;

    printf("Escolha o tamanho do vetor: ");
    scanf("%d", &size);

    v = new_vector(size);
    populate_vector(v, size);
    print_vector(v, size);

    printf("Digite um novo valor para o vetor: ");
    scanf("%d", &new_size);

    v = resize_vector(v, new_size);
    fill_vector(v, size, new_size);

    print_vector(v, new_size);

    free(v);

    return 0;

}

