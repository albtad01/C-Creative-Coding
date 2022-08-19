#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo {
        char dato;
        struct s_nodo *left;
        struct s_nodo *right;
} nodo;
typedef nodo *albero;
// Si scriva una funzione che restituisce 1 se concatenando le lettere trovate percorrendo uno dei cammini dalla RADICE alle FOGLIE nell’albero si ottiene la parola contenuta nell’array word, 0 altrimenti. Si scriva anche un’opportuna funzione main per testare contains.

albero creaAlbero(void);
albero createVal(int val);

void print(albero t);

int contains (albero t, char word[]);

int main(){
  int ris=0;
  albero alb = creaAlbero();
  print(alb);

  //chiamata alla funzione da scrivere
    ris=contains(alb,"alby");

  printf("\n\n%d\n\n", ris);
  return 0;
}

int f(albero t) {
     int ris=0;
     //funzione da scrivere

     return ris;
}

albero creaAlbero() {
       albero tmp = createVal('a');
       tmp->left = createVal('i');
       tmp->left->left = createVal('r');
       tmp->left->right = createVal('t');
       tmp->right = createVal('l');
       tmp->right->left = createVal('e');
       tmp->right->right = createVal('b');
       tmp->right->right->left = createVal('y');
       tmp->right->right->right = createVal('e');

       return tmp;
}

albero createVal(int val) {
       albero tmp = malloc(sizeof(nodo));
       tmp->dato = val;
       tmp->left = NULL;
       tmp->right = NULL;
       return tmp;
}

void print(albero t){
       if(t==NULL)
           return;
       printf(" (");
       print(t->left);
       printf(" %c ",t->dato);
       print(t->right);
       printf(") ");
}

int contains (albero t, char word[]){
    if(t==NULL && *word=='\0')
        return 1;
    if(t==NULL || t->dato!=*word)
        return 0;
    if(contains(t->right,word+1) || contains(t->left,word+1))
        return 1;
    return 0;
}
