#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo {
        int val;
        struct s_nodo *left;
        struct s_nodo *right;
} nodo;
typedef nodo *albero;


albero creaAlbero(void);
albero createVal(int val);

void print(albero t);

int MassimoPari(albero t);

int main(){
  int ris=0;
  albero alb = creaAlbero();
  print(alb);

  //chiamata alla funzione da scrivere
  ris=MassimoPari(alb);

  printf("\n\n%d\n\n", ris);
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
int MassimoPari(albero t){
    //assunzione: numeri > 0
    if(t==NULL)
        return 0;
    if(t->val%2==0 && t->val>MassimoPari(t->left) && t->val>MassimoPari(t->right))
        return t->val;
    if(MassimoPari(t->left)%2==0 && MassimoPari(t->left)>t->val && MassimoPari(t->left)>MassimoPari(t->right))
        return MassimoPari(t->left);
    if(MassimoPari(t->right)%2==0)
        return MassimoPari(t->right);
    return 0;
}
// VERSIONE PROF
int f3_max(albero t) {
    //caso base: nessun nodo il massimo è 0
    if(t==NULL)
        return 0;
    // trovo i massimi di destra e sinistra... (che si interromperanno quando arrivano a NULL)
    int maxSX = f3_max(t->left);
    int maxDX = f3_max(t->right);
    int val = t->val;
    //...e confronto i due massimi con il valore corrente dell'albero!
    if (val>maxSX && val>maxDX)
        return val;

    if (maxSX>val && maxSX>maxDX)
        return maxSX;

    return maxDX;
}
