#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo {
        int val;
        int profondita;
        struct s_nodo *left;
        struct s_nodo *right;
} nodo;
typedef nodo *albero;
// Modificate la struttura dati dell’albero definito nel file alberi.c in modo da poter salvare in ciascun nodo un intero che rappresenta la profondità del nodo stesso all’interno dell’albero. Ad esempio il nodo radice avrà profondità 0, i suoi figli profondità 1, i figli dei figli profondità 2 e così via. Scrivere una funzione che esplora tutto l’albero, calcola la profondità di ogni nodo e salva tale informazione all’interno del campo appena aggiunto alla struttura dell’albero.


albero creaAlbero(void);
albero createVal(int val);
albero calcolaProfondita(albero t);
albero calcoloProfondita_aux(albero t, int);
void print(albero t);

int f(albero t);

int main(){
  albero alb = creaAlbero();
  calcolaProfondita(alb);
  print(alb);
  printf("\n");
  return 0;
}

int f(albero t) {
     int ris=0;
     //funzione da scrivere

     return ris;
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
       tmp->right->right->right = createVal(6);

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
       printf(" %d , %d ",t->val,t->profondita);
       print(t->right);
       printf(") ");
}

albero calcolaProfondita(albero t){
    return calcoloProfondita_aux(t, 0);;
}


albero calcoloProfondita_aux(albero t, int liv){
    if(t==NULL)
        return NULL;
    t->profondita=liv;
    t->right=calcoloProfondita_aux(t->right, liv+1);
    t->left=calcoloProfondita_aux(t->left, liv+1);
    return t;
}
