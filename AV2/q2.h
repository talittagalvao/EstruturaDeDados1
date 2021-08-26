#include <stdlib.h>

typedef struct node {
  int info;
  struct node *next;
} Tnode;

typedef struct queue {
  Tnode *start, *end;
} Tqueue;

typedef struct stack {
  Tnode *top;
} Tstack;


//fila
Tqueue *createq () {
  Tqueue *q = (Tqueue *) malloc (sizeof(Tqueue));
  q->start = q->end = NULL;
  return q;
}

int emptyq (Tqueue *q) {
  return !q->end;
}

void insertq (Tqueue *q, int elem) {
  Tnode *node = (Tnode *) malloc (sizeof(Tnode));
  node->info = elem;
  node->next = NULL;

  // apontar o ponteiro do antigo último elemento para o novo último elemento
  if (q->end) {
    q->end->next = node;
  }

  // andar com o ponteiro de fim da fila
  q->end = node;

  // apontar o ponteiro de início caso a fila esteja vazia
  if (!q->start) {
    q->start = node;
  }
}

int remove_nodeq (Tqueue *q) {
  if (emptyq (q)) {
    exit (1);
  }

  // ponteiro q->start aponta para o primeiro elemento da fila
  int value = q->start->info;

  // criar um novo ponteiro nó que aponta para o primeiro elemento da fila, que será removido
  Tnode *p = q->start;

  // andar com o ponteiro de início da fila para o próximo elemento
  q->start = q->start->next;

  // apontar o ponteiro de fim da fila para NULL, caso o elemento a ser removido sea o último restante
  if (!q->start) {
    q->end = NULL;
  }

  // liberar a memória do elemento removido da fila
  free (p);

  return value;
}

void clearq (Tqueue *q) {
  Tnode *p = q->start, *aux;

  // enquanto existirem elementos na fila
  while (p) {
    aux = p;        // utilizar o auxiliar para não perder o apontamento
    p = aux->next;  // caminhar com o ponteiro p
    free (aux);     // liberar a memória o elemento em questão da fila
  }
  free (q);         // liberar a memória da fila
}

void print_queue (Tqueue *q) {
  Tqueue *p;
  p = createq();
  int value;

  while (!emptyq(q)) {
    value = remove_nodeq (q);
    printf ("%d  ", value);
    insertq (p, value);
  }

  while (!emptyq(p)) {
    value = remove_nodeq (p);
    insertq (q, value);
  }
  printf ("\n\n");

  clearq (p);
}

//pilha

Tstack *create () {
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

void clear (Tstack *s) {
  Tnode *r = s->top, *t;
  while (r) {
    t = r;        // ponteiro auxiliar t aponta para o ponteiro r, que aponta para o topo da pilha
    r = r->next;  // reaponto o topo para o seu elemento imediatamente abaixo
    free (t);     // liberar a memória de ocupada pelo node t
  }
  free (s);       // liberar a memória da estrutura da pilha
}

void print_stack (Tstack *s) {
  Tstack *t = create();
  int elem, counter = 1;

  while (!empty (s)) {
    push (t, pop (s));
  }
  // Ao fim do while, temos uma cópia invertida da pilha s na pilha t

  while (!empty (t)) {
    elem = pop (t);
    printf ("Elemento %d da pilha = %d\n", counter, elem);
    push (s, elem);
    counter ++;
  }
  // Ao final do while, temos a pilha s repopulada na ordem correta com os seus elementos impressos e a pilha t vazia
  clear (t);
}

Tstack *Fila2Pilha (Tqueue *f){
  Tqueue *p = createq();
  Tstack *t = create();
  Tstack *j = create();
  
  int value;
 
  while (!emptyq(f)) {
    value = remove_nodeq (f);
    insertq (p, value);
    push (t, value);
  }

  while (!emptyq(p)) {
    value = remove_nodeq (p);
    insertq (f, value);
  }

  while (!empty (t)) {
  value = pop (t);
  push (j, value);
  }
  
  clear (t);
  clearq (p);

  return j;
  
}


