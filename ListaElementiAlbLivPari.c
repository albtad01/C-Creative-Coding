#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo {
        int val;
        struct s_nodo *left;
        struct s_nodo *right;
} nodo;
typedef nodo * albero;
typedef struct el{
    int info;
    struct el * prox;
}ElemLista;
typedef ElemLista * ListaDiElem;
// Scrivere una funzione (e opportuna funzione main per testarla) che dato un albero in input, inserisca in una lista i soli nodi di livello pari.


albero creaAlbero(void);
albero createVal(int val);
void print(albero t);

ListaDiElem InsInFondo( ListaDiElem lista, int elem );
ListaDiElem InsInTesta( ListaDiElem lista, int elem );
void VisualizzaLista( ListaDiElem lista );
ListaDiElem RestituisciNodiPari(albero t);
ListaDiElem RestituisciNodiPari_aux(albero t,ListaDiElem, int);

int main(){
  albero alb = creaAlbero();
  ListaDiElem l=NULL;
  print(alb);

  //chiamata alla funzione da scrivere
  l=RestituisciNodiPari(alb);
    printf("\n");
  VisualizzaLista(l);
  return 0;
}

ListaDiElem RestituisciNodiPari(albero t){
    return RestituisciNodiPari_aux(t,NULL,0);
}
ListaDiElem RestituisciNodiPari_aux(albero t, ListaDiElem l, int liv){
    if(t==NULL)
        return l; // se è nodo nullo, ritorno la lista stessa senza inserirci nulla
    if(liv%2==0)
        l=InsInFondo(l,t->val);
    l=RestituisciNodiPari_aux(t->right, l, liv+1); // prima andiamo a destra per aggiornare la lista con eventuli livelli pari
    l=RestituisciNodiPari_aux(t->left, l, liv+1); // NB: noi passiamo la lista stessa a cui inseriamo eventualmente dei nodi
    return l; // alla fine ritorniamo la lista a cui abbiamo aggiunto i nodi necessari
}

albero creaAlbero() {
       albero tmp = createVal(7);
       tmp->left = createVal(3);
       tmp->left->left = createVal(9);
       tmp->left->right = createVal(10);
       tmp->right = createVal(8);
       tmp->right->left = createVal(5);
       tmp->right->right = createVal(12);
       tmp->right->right->left = createVal(11);
       tmp->right->right->right = createVal(17);

       return tmp;
}

albero createVal(int val) {
       albero tmp = malloc(sizeof(nodo));
       tmp->val = val;
       tmp->left = NULL;
       tmp->right = NULL;
       return tmp;
}

void print(albero t){
       if(t==NULL)
           return;
       printf(" (");
       print(t->left);
       printf(" %d ",t->val);
       print(t->right);
       printf(") ");
}
void VisualizzaLista( ListaDiElem lista ) {
    if ( lista==NULL )
        printf(" ---| \n");
    else {
        printf(" %d ---> ",lista->info);
        VisualizzaLista(lista->prox);
    }
}
ListaDiElem InsInTesta( ListaDiElem lista, int elem ) {
    ListaDiElem punt;
    punt = (ListaDiElem) malloc(sizeof(ElemLista));
    punt->info = elem;
    punt->prox = lista;
    return  punt;
}
ListaDiElem InsInFondo( ListaDiElem lista, int elem ){
    ListaDiElem punt;
    if(lista==NULL){
        punt=malloc(sizeof(ElemLista));
        punt->prox=NULL;
        punt->info=elem;
        return punt;
    }
    else{
        lista->prox=InsInFondo(lista->prox,elem);
        return lista;
    }
}
