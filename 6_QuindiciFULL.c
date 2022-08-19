
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 4
int valida (int gioco[N][N], int mossa); // 1 se mossa valida 0 altrimenti
void muovi (int gioco[N][N], int mossa); // aggiorna la scacchiera in base alla mossa
int risolto (int gioco[N][N]); // riceve scacchiera: 1 se risolto 0 altrimenti
void stampa (int gioco[N][N]); // che riceve la scacchiera e la stampa a video
void scambia (int *a, int *b);

int main(int argc, const char * argv[]) {
    int G[N][N]={{8,5,2,4},{11,1,0,7},{12,10,3,15},{9,13,14,6}},choice;
    printf("****QUINDICI: L'ORIGINALE!****\n");
    while(risolto(G)!=1){
        stampa(G);
        printf("Mossa: ");
        scanf("%d",&choice);
        if(valida(G,choice)==1)
            muovi(G,choice);
    }
    stampa(G);
    printf("****RISOLTO!****\n");
    return 15;
}
int valida (int gioco[N][N], int mossa){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(gioco[i][j]==0 && (gioco[i][j-1]==mossa || gioco[i-1][j]==mossa || gioco[i][j+1]==mossa || gioco[i+1][j]==mossa))
                return 1;
        }
    }
    return 0;
}
void muovi (int gioco[N][N], int mossa){
    int i,j,im,jm,flag=0;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(gioco[i][j]==0){
                for(im=0;im<N && flag==0;im++){
                    for(jm=0;jm<N && flag==0;jm++){
                        if(gioco[im][jm]==mossa){
                            scambia(&gioco[i][j],&gioco[im][jm]);
                            flag++;
                        }
                    }
                }
            }
        }
    }
}
void scambia (int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void stampa (int gioco[N][N]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            printf("%d\t",gioco[i][j]);
        printf("\n");
    }
}
int risolto (int gioco[N][N]){
    int i,j,prec=0;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(gioco[i][j]<prec) return 0;
            prec=gioco[i][j];
        }
    }
    return 1;
}
