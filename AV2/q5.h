#include <stdio.h>
#include <stdlib.h>

//lista
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
    printf ("%d \n", p->info);
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

//pilha
typedef struct node {
  int info;
  struct node *next;
} Tnode;

typedef struct stack {
  Tnode *top;
} Tstack;

Tstack *create_pilha () {
  Tstack *s = (Tstack *) malloc (sizeof (Tstack));
  s->top = NULL;
  return s;
}

int empty (Tstack *s) {
  return s->top == NULL; // Se verdadeiro, retorna 1, 0 caso contrário
}

void push (Tstack *s, int elem) {
  Tnode *newNode = (Tnode *) malloc (sizeof (Tnode));
  newNode->info = elem;
  newNode->next = s->top;
  s->top = newNode;
}

int pop (Tstack *s) {
  if (empty (s)) {
    exit (1);
  }
  // novo ponteiro que aponta para o topo da pilha
  Tnode *t = s->top;
  // reapontar o topo da pilha para o elemento imediatamente abaixo
  s->top = s->top->next;
  int result = t->info;
  free (t);
  return result;
}

void clear_pilha (Tstack *s) {
  Tnode *r = s->top, *t;
  while (r) {
    t = r;        // ponteiro auxiliar t aponta para o ponteiro r, que aponta para o topo da pilha
    r = r->next;  // reaponto o topo para o seu elemento imediatamente abaixo
    free (t);     // liberar a memória de ocupada pelo node t
  }
  free (s);       // liberar a memória da estrutura da pilha
}

//função q5
void imprime_invertido (Tlist *l){
    Tlist *p = l;
    Tstack *t = create_pilha();
    
    while (p != NULL) {
        push(t,p->info);
        p = p->next;
    }

    while (t != NULL) {
        printf("%d\n", t->top->info);
        pop(t);
    }
    
    clear(p);
    clear_pilha(t);

}