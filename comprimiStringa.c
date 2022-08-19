#include<stdio.h>
#include<string.h>
void comprimiStringa(char txt[100],char res[100]);
void decomprimiStringa(char res[100], char txt[100]);
int main(){
    char txt1[100]="weeeeecoomestaii?";
    char txt2[100]="ciiiaaaaooooo";
    char res1[100],res2[100],prova[100];
    comprimiStringa(txt1, res1);
    printf("Compressione: \n%s -> %s\n",txt1,res1);
    comprimiStringa(txt2, res2);
    printf("Compressione: \n%s -> %s\n",txt2,res2);
    decomprimiStringa(res2, prova);
    printf("Decompressione: \n%s -> %s\n",res2,prova);
    return 0;
}
void comprimiStringa(char txt[100],char res[100]){
    int i=0,j=0,cont=1;
    while(txt[i]!='\0'){
        while(txt[i]==txt[i+1]){
            i++;
            cont++;
        }
        if(cont==1){
            res[j]=txt[i];
            j++;
        }
        else{
            res[j]=cont+'0';
            res[j+1]=txt[i];
            j+=2;
        }

        cont=1;
        i++;
    }
    res[j]='\0';
}
void decomprimiStringa(char res[100],char txt[100]){
    int i=0,j=0,cont=1;
    while(res[i]!='\0'){
        if(res[i]-'0'>=2 && res[i]-'0'<=9){
            while(cont<=res[i]-'0'){
                txt[j]=res[i+1];
                j++;
                cont++;
            }
            cont=1;
            i+=2;
        }
        else{
            txt[j]=res[i];
            j++;
            i++;
        }

    }
}
