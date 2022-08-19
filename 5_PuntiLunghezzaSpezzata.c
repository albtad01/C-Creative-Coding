
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 5
typedef struct {
    float x;
    float y;
} Punto;
void stampaPunto(Punto p);
void acquisisciPunto(Punto * p);
float calcolaNorma(Punto p);
float calcolaDistanza(Punto p1, Punto p2);
void acquisisciPunti(Punto * l);
float lunghezza(Punto linea[]);

int main(int argc, const char * argv[]) {
    Punto p,pp,l[N];
    acquisisciPunto(&p);
    // il punto p non è un puntatore, ma passo per indirizzo e all'interno della funzione ho un puntatore all'indirizzo di memoria di p
    stampaPunto(p);
    printf("Norma: %5.2f\n",calcolaNorma(p));
    acquisisciPunto(&pp);
    stampaPunto(pp);
    printf("Distanza p1-p2: %5.2f\n",calcolaDistanza(p, pp));
    acquisisciPunti(l);
    printf("Lunghezza Spezzata: %5.2f\n",lunghezza(l));
    return 0;
}
void stampaPunto(Punto p){
    printf("P(%5.2f;%5.2f)",p.x,p.y);
    printf("\n");
}
void acquisisciPunto(Punto * p){
    printf("Px: ");
    scanf("%f",&(*p).x);
    printf("Py: ");
    scanf("%f",&(p)->y); // equivalenza (*p).x e
}
float calcolaNorma(Punto p){
    return sqrt(pow(p.x-0,2)+pow(p.y-0,2));
}
float calcolaDistanza(Punto p1, Punto p2){
    return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}
void acquisisciPunti(Punto * l){
    int i;
    for(i=0;i<N;i++){
        printf("P%dx: ", i+1);
        scanf("%f",&(*(l+i)).x);
        printf("P%dy: ", i+1);
        scanf("%f",&(*(l+i)).y);
    }
}
float lunghezza(Punto linea[]){
    int i;
    float lun=0;
    for(i=0;i<N-1;i++)
        lun+=sqrt(pow(linea[i].x-linea[i+1].x,2)+pow(linea[i].y-linea[i+1].y,2));
    return lun;
}
