
void bubblesort(int a[], int n){
  int i, j;
  // N.B. n-1 è l'ultima componente dell'array.
  for(i = 0; i < n - 1; i++) //scansiona tutto l'array tranne l'ultima componente: n - 1 escluso. Quindi fino al penultimo elemento.
        for (j = 0; i< n - 1- j; j++) //j settato all'ultima componente e decresce ad ogni iterazione. Esce dal ciclo solo se j <= i
                    if (a[j] < a[j-1])  //se la componente corrente è più piccola della precedente, li scambia.
                            scambia(&a[j],&a[j-1]);
}

//la funzione scambia è così composta:
void scambia(int *a, int *b){ //richiede due indirizzi di memoria in entrata che verranno memorizzati in 2 puntatori.
  int temp; //la variabile d'appoggio che memorizza temporaneamente il valore di a.
  temp = *a;
  *a = *b;
  *b = temp;
}
//NB. l'asterisco * dei puntatori fa riferimento sempre al valore a cui punta il puntatore.
