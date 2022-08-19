#include <stdio.h>
#include <stdlib.h>
typedef struct n {
    int val;
    struct n * left;
    struct n * right;
} nodo;
typedef nodo * albero;
albero createVal(int val);
albero creaAlbero1(void);
albero creaAlbero2(void);
albero creaAlbero3(void);
void print(albero t);
void stampa(albero T);
int f(albero t1,albero t2);
int SimmetriaSpeculare(albero t);
int SimmetriaSpeculare_aux(albero t1, albero t2);
int main(){
    albero T1,T2,T3;
    T1 = creaAlbero1();
    T2 = creaAlbero2();
    T3 = creaAlbero3();
    printf("\nT1: ");
    stampa(T1);
    printf("\nT2: ");
    stampa(T2);
    printf("\nT3: ");
    stampa(T3);
    printf("\n");
    //LA FUNZIONE DA SVILUPPARE VIENE USATA QUI
    if(f(T1,T2)==1)
        printf("T1 e T2 sono simmetrici\n");
    else printf("T1 e T2 non sono simmetrici\n");
    if(f(T1,T3)==1)
        printf("T1 e T3 sono simmetrici\n");
    else printf("T1 e T3 non sono simmetrici\n");
    printf("\n");
    if(SimmetriaSpeculare(T1)==1) printf("T1 è simmetricamente speculare\n");
    if(SimmetriaSpeculare(T2)==1) printf("T2 è simmetricamente speculare\n");
    if(SimmetriaSpeculare(T3)==1) printf("T3 è simmetricamente speculare\n");

    return 0;
}

//
// TODO: SVILUPPARE QUI DENTRO QUANTO RICHIESTO
//
int f(albero t1,albero t2){
    if(t1==NULL && t2==NULL)
        return 1;
    if(t1==NULL || t2==NULL)
        return 0;
    return t1->val==t2->val && f(t1->left,t2->right) && f(t1->right,t2->left);
}
int SimmetriaSpeculare(albero t){
    if(t==NULL)
        return 1;
    return SimmetriaSpeculare_aux(t->left, t->right);
}
int SimmetriaSpeculare_aux(albero t1, albero t2){
    if((t1==NULL && t2==NULL))
        return 1;
    if(t1==NULL || t2==NULL)
        return 0;
    return SimmetriaSpeculare_aux(t1->left, t2->right) && SimmetriaSpeculare_aux(t1->right, t2->left);
}
// uguale ma senza uguaglianza valori (uguale struttura, ma valori possono essere diversi)
albero creaAlbero1() {
    albero tmp = createVal(0);
    tmp->left = createVal(1);
    tmp->left->left = createVal(4);
    tmp->right = createVal(2);
    tmp->right->left = createVal(3);
    tmp->right->right = createVal(7);
    return tmp;
}
albero creaAlbero2() {
    albero tmp = createVal(0);
    tmp->left = createVal(2);
    tmp->left->left = createVal(7);
    tmp->left->right = createVal(3);
    tmp->right = createVal(1);
    tmp->right->right = createVal(4);
    return tmp;
}
albero creaAlbero3() {
    albero tmp = createVal(7);
    tmp->right = createVal(3);
    tmp->left = createVal(4);
    tmp->left->right=createVal(66);
    return tmp;
}
void print(albero t){
    if(t==NULL)return;
    else{printf(" (");print(t->left);printf(" %d ",t->val);print(t->right);printf(") ");}
}
void stampa(albero T){print(T);printf("\n");}
albero createVal(int val) {
    albero tmp = malloc(sizeof(nodo));
    tmp->val = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
