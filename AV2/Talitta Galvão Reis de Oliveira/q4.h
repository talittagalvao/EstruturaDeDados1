#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 60
#define SEARCH_ELEMENTS 6

typedef struct list {
  int info;
  struct list *next;
} Tlist;

Tlist *create () {
  return NULL;
}

Tlist *ordered_insert (Tlist *l, int elem) {
  Tlist *p = l; // ponteiro auxiliar para navegar pela lista (NUNCA MANIPULAR O PONTEIRO RECEBIDO COMO PARÂMETRO)
  Tlist *previous = NULL; // aponta para o elemento anterior ao atual
  Tlist *newElem; // novo elemento da lista a ser inserido

  while (p != NULL && p->info <= elem) {
    previous = p;
    p = p->next;
  }

  newElem = (Tlist *) malloc (sizeof (Tlist)); // alocação de memória do novo elemento
  newElem->info = elem;

  if (previous == NULL) { // lista vazia e inserção do primeiro elemento
    newElem->next = l; // o next do novo elemento aponta para a cabeça da lista (NULL)
    l = newElem; // a cabeça da lista aponta para o novo elemento
  }
  else { // lista não vazia
    newElem->next = p; // ponteiro next do novo elemento aponta para o mesmo lugar que p
    previous->next = newElem; // ponteiro next do previous (anterior) aponta para o novo elemento
  }

  return l;
}

void print_list (Tlist *l) {
  Tlist *p = l;

  while (p != NULL) {
    printf ("%d\n", p->info);
    p = p->next;
  }
}

void clear (Tlist *l) {
  Tlist *p = l;

  while (p) {
    Tlist *q = p;
    p = p->next;
    free (q);
  }
}

Tlist *search (Tlist *l, int elem) {
  Tlist *p = l; // ponteiro auxiliar apontando para a cabeça da lista

  while (p) { // enquanto tivermos elementos na lista
    if (p->info != elem) {
      p = p->next; // se o elemento atual for diferente daquele buscado, anda para o próximo
    }
    else {
      return p; // retorna o elemento da lista assim que ele é encontrado
    }
  }

  return p; // só será executado se o elemento não estiver na lista
}

Tlist *remove_elem (Tlist *l, int elem) {
  // Tlist *previous = NULL, *p = l;
  Tlist *previous = l, *p = l->next;

  while ((p != NULL)  && (p->info != elem)) { // andando na lista até ela acabar ou até encontrar o elemento
    previous = p;
    p = p->next;
  }

  if (!p) { // p aponta para NULL, ou seja, o fim da lista foi alcançado
    //printf ("O elemento %d nao esta na lista\n", elem);
    return l; // retorno a própria lista original sem remover nenhum elemento
  }

  if (!previous) { // significa que o elemento a ser removido foi encontrado na primeira posição da lista
    l = l->next; // cabeça da lista apronta para o segund elemento
  }
  else {
    previous->next = p->next; // o anterior aponta para o elemento seguinte ao elemento p
  }

  //printf ("Elemento %d removido da lista\n", p->info);
  free (p);
  return l;
}

Tlist *mega_sena (){
    int r, i;
    time_t t;
    Tlist *list = create ();
    Tlist *sort = create();

    srand((unsigned) time(&t));
  
    for (i = 1; i <= NUM_ELEMENTS; i++) {
        list = ordered_insert (list, i);
    }  
    
    i=1;

    do{
        r = rand () % 60;
        if(search(list,r)){
            sort = ordered_insert (sort, r);
            remove_elem (list, r);
            i++;
        }    
    } while (i <= SEARCH_ELEMENTS);

    //printf("Numeros nao sorteados: \n");    
    //print_list(list);

    printf("\n\n");

    return sort;
    
}