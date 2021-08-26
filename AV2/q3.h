#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int info;
  struct list *next;
} Tlist;

typedef struct circular {
  int info;
  struct circular *next;
}Tcl;


//>>LISTA
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


//CIRCULAR
Tcl *create_circular () {
  return NULL;
}

Tcl *insert_circular (Tcl *l, int elem) {
  Tcl *new_elem = (Tcl *) malloc (sizeof (Tcl));
  new_elem->info = elem;

  if (!l) { // Se a lista estiver vazia e este for o primeiro elemento,
    new_elem->next = new_elem; // o next do primeiro elemento aponta para ele mesmo
    return new_elem;
  }

  new_elem->next = l->next;
  l->next = new_elem;
  return l;
}

void clear_circular (Tcl *l) {
  if (l) {
    Tcl *p = l->next;
    while (p != l) {
      Tcl *q = p;
      p = p->next;
      free (q);
    }
    free (p);
  }
}

void print_circular (Tcl *l) {
  if (l) {
    printf ("%d\n", l->info);
    Tcl *p = l->next;
    while (p != l) {
      printf ("%d\n", p->info);
      p = p->next;
    }
  }
}

Tcl *search_circular (Tcl *l, int elem) {
  if (!l) {
    return NULL;
  }
  if (l->info == elem) {
    return l;
  }

  Tcl *p = l->next;
  while (p != l && p->info != elem) {
    p = p->next;
  }

  if (p == l) {
    return NULL;
  }

  return p;
}

Tcl *gera_circular (Tlist *l){
    Tlist *p = l;
    Tcl *c = create();

    while (p != NULL) {
        c = insert_circular (c, p->info);
        p = p->next;
    }

    clear (p);
    
    return c;

}