#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//ASSINATURAS
void swap(int *xp, int *yp);
void quickSort(int A[],int inicio, int fim);
int partition(int A[],int inicio,int fim);

void swap(int *xp, int *yp){ //FUNCIONALIDADE PARA TROCAR OS VALORES ENTRE DOIS ESPAÇOS DE MEMÓRIA
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void quickSort(int A[],int inicio, int fim){        //QUICKSORT RECURSIVO
    if (inicio < fim){
    int pivot = partition(A,inicio,fim);
    quickSort(A,inicio,pivot-1);
    quickSort(A,pivot+1,fim);
    }
}

int partition(int A[],int inicio,int fim){
    int pivot = A[fim];
    int i = inicio-1;
    for (int j=inicio;j < fim;j++){
        if (A[j] <=pivot){
            i = i+1;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[fim]);
    return i+1;
}


int main(){
    int i;
    int A[30];
    srand(time(NULL));


    for (i=0;i<30;i++){                 //Preenchimento do vetor
        A[i] = rand()%50;
        printf("A[%d] = %d\n",i,A[i]);
    }

    quickSort(A,0,29);

    printf("________________________________________________________________________________________________\n");

    for (i=0;i<30;i++){             //Visualização do vetor ordenado
        printf("A[%d] = %d\n",i,A[i]);
    }
    return 0;
}