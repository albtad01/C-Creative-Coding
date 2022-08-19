
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 3

typedef struct Complex{
    double Re;
    double Im;
} Complex;
void GetComplesso(Complex * n);
Complex MaxComplessoModulo(Complex * array);

int main(int argc, const char * argv[]) {
    int i;
    Complex Complessi[N],MaxComplesso;
    for(i=0;i<N;i++)
        GetComplesso(Complessi+i);
    MaxComplesso=MaxComplessoModulo(Complessi);
    printf("Complesso con Norma più alta: %5.2f+%5.2fi\n",MaxComplesso.Re,MaxComplesso.Im);
    return 0;
}
void GetComplesso(Complex * n){
    printf("Parte Reale: ");
    scanf("%lf",&(n)->Re);
    printf("Parte Immaginaria: ");
    scanf("%lf",&(*n).Im);
}
Complex MaxComplessoModulo(Complex * array){
    Complex maxmodc=array[0];
    int i;
    double maxmodn=0;
    for(i=0;i<N;i++){
        if(sqrt(pow(array[i].Re,2)+pow(array[i].Im,2))>maxmodn){
            maxmodn=sqrt(pow(array[i].Re,2)+pow(array[i].Im,2));
            maxmodc=array[i];
        }
    }
    return maxmodc;
}
