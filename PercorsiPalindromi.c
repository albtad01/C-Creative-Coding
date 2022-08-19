typedef struct s_nodo {
        int val;
        struct s_nodo *left;
        struct s_nodo *right;
} nodo;
typedef nodo *albero;
typedef struct EL{
    int val;
    struct EL * next;
} nodo_l;
typedef nodo_l * Lista;
albero creaAlbero(void);
albero createVal(int val);
void print(albero t);
int numPercorsiPalindromi(albero t, Lista l);
int lunghezzaLista(Lista l);
int listaPalindroma(Lista l);
Lista cancellaUltimoNodo(Lista l);
Lista InsInFondo( Lista lista, int elem );
void VisualizzaLista( Lista lista );
int main(){
  int ris=0;
  albero alb = creaAlbero();
  print(alb);
    printf("\n\nPercorsi possibili:\n");
  ris=numPercorsiPalindromi(alb,NULL);

  printf("\n\n%d\n\n", ris);
  return 0;
}


albero creaAlbero() {
       albero tmp = createVal(10);
       tmp->left = createVal(3);
       tmp->left->left = createVal(5);
       tmp->left->right = createVal(10);
       tmp->right = createVal(3);
       tmp->right->left = createVal(5);
       tmp->right->right = createVal(3);
       tmp->right->right->left = createVal(11);
       tmp->right->right->right = createVal(10);

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
Lista InsInFondo( Lista lista, int elem ){
    Lista punt;
    if(lista==NULL){
        punt=malloc(sizeof(nodo_l));
        punt->next=NULL;
        punt->val=elem;
        return punt;
    }
    else{
        lista->next=InsInFondo(lista->next,elem);
        return lista;
    }
}
void VisualizzaLista( Lista lista ) {
    if ( lista==NULL )
        printf(" ---| \n");
    else {
        printf(" %d ---> ",lista->val);
        VisualizzaLista(lista->next);
    }
}
int numPercorsiPalindromi(albero t, Lista l){
    int sx,dx;
    if(t==NULL)
        return 0;
    if(t->right==NULL && t->left==NULL){
        l=InsInFondo(l, t->val);
        VisualizzaLista(l);
        return listaPalindroma(l);
    }
    l=InsInFondo(l, t->val);
    sx=numPercorsiPalindromi(t->left, l);
    cancellaUltimoNodo(l);
    dx=numPercorsiPalindromi(t->right, l);
    cancellaUltimoNodo(l);
    return sx+dx;
}
int listaPalindroma(Lista l){
    int i=0,lenght=0,flag=1,j=0;
    Lista head=l,scroll1=l,scroll2=NULL;
    lenght=lunghezzaLista(l);
    while(scroll1!=NULL){
        scroll2=head;
        while(scroll2!=NULL){
            if(i==(lenght-j-1) && scroll1->val!=scroll2->val)
                flag=0;
            j++;
            scroll2=scroll2->next;
        }
        j=0;
        i++;
        scroll1=scroll1->next;
    }
    return flag;
}
int lunghezzaLista(Lista l){
    int cont=0;
    Lista scroll=l;
    while(scroll!=NULL){
        cont++;
        scroll=scroll->next;
    }
    return cont;
}
Lista cancellaUltimoNodo(Lista l){
    Lista head=l,prec=NULL;
    while(l!=NULL){
        if(l->next==NULL){
            prec->next=NULL;
            free(l);
            l=NULL;
        }
        else{
            prec=l;
            l=l->next;
        }
    }
    return head;
}
