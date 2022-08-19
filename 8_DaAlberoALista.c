#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodo_t {
    int e;
    struct nodo_t *next;
    struct nodo_t *down;
} nodo;
typedef nodo * ptrNodo;
typedef struct nodo_f_t{
    int e;
    struct nodo_f_t *next;
}nodo_f;
typedef nodo_f * ptrNodoF;
ptrNodoF flatten(ptrNodo ll);
ptrNodoF flatten_aux(ptrNodo ll, ptrNodoF l);
void VisualizzaLista( ptrNodoF lista );

int main(int argc, const char * argv[]) {
    ptrNodoF ptrF=NULL;
    ptrNodo ptr0,ptr1,ptr2,ptr3;
    ptr0=(ptrNodo)malloc(sizeof(nodo));
    ptr0->e=1;
    ptr0->down=NULL;
    ptr0->next=NULL;
    ptr1=(ptrNodo)malloc(sizeof(nodo));
    ptr1->e=2;
    ptr1->down=NULL;
    ptr1->next=NULL;
    ptr2=(ptrNodo)malloc(sizeof(nodo));
    ptr2->e=3;
    ptr2->down=NULL;
    ptr2->next=NULL;
    ptr3=(ptrNodo)malloc(sizeof(nodo));
    ptr3->e=4;
    ptr3->down=NULL;
    ptr3->next=NULL;
    ptr0->down=ptr1;
    ptr0->next=ptr3;
    ptr1->down=ptr2;
    ptrF=flatten(ptr0);
    VisualizzaLista(ptrF);
    return 0;
}
ptrNodoF InsInTesta( ptrNodoF lista, int elem ) {
    ptrNodoF punt;
    punt = (ptrNodoF) malloc(sizeof(nodo_f));
    punt->e = elem;
    punt->next = lista;
    return  punt;
}
ptrNodoF InsInFondo( ptrNodoF lista, int elem ){
    ptrNodoF punt;
    if(lista==NULL){
        punt=malloc(sizeof(nodo_f));
        punt->next=NULL;
        punt->e=elem;
        return punt;
    }
    else{
        lista->next=InsInFondo(lista->next,elem);
        return lista;
    }
}
ptrNodoF flatten(ptrNodo ll){
    return flatten_aux(ll,NULL);
}
ptrNodoF flatten_aux(ptrNodo ll, ptrNodoF l){
    if(ll==NULL)
        return NULL;
    l=InsInFondo(l, ll->e);
    if(ll->down!=NULL)
        l=flatten_aux(ll->down,l);
    if(ll->next!=NULL)
        l=flatten_aux(ll->next,l);
    return l;
}
void VisualizzaLista( ptrNodoF lista ) {
    if ( lista==NULL )
        printf(" ---| \n");
    else {
        printf(" %d ---> ",lista->e);
        VisualizzaLista(lista->next);
    }
}
