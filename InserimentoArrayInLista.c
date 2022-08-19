
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
typedef struct EL{
    int info;
    struct EL * prox;
}ElemLista;
typedef ElemLista * ListaDiElem;
void RiempiVettore(int v[N]);
ListaDiElem InsInTesta(ListaDiElem lista, int elem);
void VisualizzaLista(ListaDiElem lista);

int main(int argc, const char * argv[]) {
    int v[N],i;
    ListaDiElem l=NULL;
    RiempiVettore(v);
    for(i=0;i<N;i++)
        l=InsInTesta(l,v[i]);
    VisualizzaLista(l);
    printf("\n");
    return 0;
}
void RiempiVettore(int v[N]){
    int i;
    for(i=0;i<N;i++){
        printf("v[%d]: ",i);
        scanf("%d",&v[i]);
    }
}
ListaDiElem InsInTesta(ListaDiElem lista, int elem){
    ListaDiElem punt;
    punt=(ListaDiElem)malloc(sizeof(ElemLista));
    punt->info=elem;
    punt->prox=lista;
    return punt;
}
void VisualizzaLista(ListaDiElem lista){
    if(lista==NULL)
        printf("---|");
    else{
        printf("%d ---> ",lista->info);
        VisualizzaLista(lista->prox);
    }
}
