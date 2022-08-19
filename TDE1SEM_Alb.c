// !ESERCIZIO 2

#include<stdio.h>
#define N 4
// h grandezza sottomatrice, k numero 0 nella sottomatrice
int ContaMatriciConZeri(int M[N][N],int h, int k);
void StampaOutput(int quanti,int h,int k);
int main(){
    int M[N][N]={0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1};
    int quanti,h=2,k=1;
    quanti=ContaMatriciConZeri(M,h,k);
    StampaOutput(quanti,h,k);
    printf("\n");
    return 0;
}
int ContaMatriciConZeri(int M[N][N],int h, int k){
    int i,j,ii,jj,NumZeri=0,Success=0;
    for(i=0;(i+h-1)<N;i++){
        for(j=0;(j+h-1)<N;j++){
            for(ii=0;ii<h;ii++){
                for(jj=0;jj<h;jj++){
                    if(M[ii+i][jj+j]==0) NumZeri++;
                }
            }
            if(NumZeri==k) Success++;
            NumZeri=0;
        }
    }
    return Success;
}
void StampaOutput(int quanti,int h,int k){
    printf("Nella matrice M ci sono %d matrici %dx%d aventi %d zeri",quanti,h,h,k);
}

//! ESERCIZIO 3
#include<stdio.h>
#include<stdlib.h>
typedef struct EL {
    int info;
    struct EL * prox;
} ElemLista;
typedef ElemLista * SottoLista;
typedef struct ELL {
    SottoLista lista;
    struct ELL * prox;
} NodoLista;
typedef NodoLista * ListaDiListe;
SottoLista InsInFondoInt(SottoLista lista,int elem );
ListaDiListe InsInFondoLista( ListaDiListe lista,SottoLista lis );
void VisualizzaListaInt(SottoLista lista );
void VisualizzaListaDiListe(ListaDiListe lista );
ListaDiListe costruisci(void);
//
// TODO: PROTOTIPI DELLE FUNZIONI RICHIESTE
//
ListaDiListe Pulisci (ListaDiListe lis);
int Ripetizione(SottoLista ll);
int NumInLista(SottoLista ll, int num);
ListaDiListe CancellaSottoLista(ListaDiListe l);

int main(){
    ListaDiListe lis=NULL;
    lis=costruisci();
    VisualizzaListaDiListe(lis);
    printf("\nPULIZIA:\n");
    lis=Pulisci(lis);
    VisualizzaListaDiListe(lis);
    return 0;
}

ListaDiListe costruisci(){
    int M[8][10]={5,4,1,5,2,7,-1,-1,-1,-1,1,6,9,1,5,7,9,0,-1,-1,1,5,1,1,2,8,9,0,-1,-1,
    1,3,2,4,0,9,8,6,-1,-1,1,2,9,8,4,0,9,0,-1,-1,1,8,7,8,3,-1,-1,-1,-1,-1,
    1,3,4,2,5,7,9,0,-1,-1,7,8,9,-1,-1,-1,-1,-1,-1,-1};
    int i,k;ListaDiListe ris=NULL; SottoLista temp=NULL;
    for(i=0;i<8;i++){
        temp=NULL;
        for(k=0;k<10;k++)
            if(M[i][k]!=-1)temp=InsInFondoInt(temp,M[i][k]);
        ris=InsInFondoLista(ris,temp);
    } return ris;
}
SottoLista InsInFondoInt(SottoLista lista,int elem ) { SottoLista punt;
if(lista==NULL) { punt = malloc( sizeof(ElemLista) );
punt->prox = NULL; punt->info = elem; return punt; }else{lista->prox = InsInFondoInt(lista->prox,elem); return lista;}
}
ListaDiListe InsInFondoLista(ListaDiListe lista,SottoLista lis ) { ListaDiListe punt;
if(lista==NULL) { punt = malloc( sizeof(NodoLista) );
punt->prox=NULL; punt->lista=lis; return punt; }else{lista->prox = InsInFondoLista(lista->prox,lis); return lista;}
}
void VisualizzaListaInt(SottoLista lista) {
    if (lista==NULL) printf(" ---| \n");
    else{
        printf(" %d ---> ", lista->info);
        VisualizzaListaInt( lista->prox );
    }
}
void VisualizzaListaDiListe( ListaDiListe lista ) {
    if(lista==NULL) printf("\n");
    else{
        VisualizzaListaInt(lista->lista);
        VisualizzaListaDiListe(lista->prox);
    }
}

//
// TODO: SVILUPPARE QUI LE FUNZIONI RICHIESTE //
//


// PRENDE LA SOTTOLISTA E VEDE SE CONTIENE RIPETIZIONI (1)
int Ripetizione(SottoLista ll){
    SottoLista head=ll;
    while(ll!=NULL){
        if(NumInLista(head, ll->info)>1) return 1;
        ll=ll->prox;
    }
    return 0;
}
int NumInLista(SottoLista ll, int num){
    int i=0;
    while(ll!=NULL){
        if(ll->info==num) i++;
        ll=ll->prox;
    }
    return i;

}
ListaDiListe CancellaSottoLista(ListaDiListe l){
    ListaDiListe puntTemp=NULL;
    puntTemp=l->prox;
    free(l);
    return puntTemp;
}

ListaDiListe Pulisci (ListaDiListe lis){
    ListaDiListe prec = NULL;
    ListaDiListe head = lis;
    while(head!= NULL){
       if (Ripetizione(head->lista) == 1) {
              if (prec == NULL){
                       lis = head -> prox;
                       free(head);
                       head = lis;
              }
              else {
                    prec -> prox = head -> prox;
                    free(head);
                    head = prec -> prox;
              }
       }
       else {
              prec = head;
              head = head -> prox;
       }
    }
    return lis;
}

// ! ESERCIZIO 4

int Simmetrici(Tree T1, Tree T2){
  if(T1==NULL && T2==NULL) return 1;
  if(T1==NULL || T2==NULL) return 0; // o semplicemente (T1==NULL || T2==NULL)
  return (T1->dato==T2->dato) && Simmetrici(T1->right,T2->left) && Simmetrici(T1->left,T2->right);
}

// !ESERCIZIO 5

1)
SELECT CF, count(*)
FROM Noleggio
GROUP BY CF
2)
SELECT distinct CF
FROM NOLEGGIO
WHERE CF NOT IN (SELECT CF FROM Noleggio WHERE CostoAlGiorno>100)
