#include <stdio.h>
#include <stdlib.h>

#include <math.h>

// funçao cria matriz 


void imprimir(int n, double **matriz){
    for (int i = 0; i<n; i++){
        for(int j = 0; j<n;j++){
            printf("%.2lf ", matriz[i][j]);
        }
        printf(" \n");
    }
    return ;
}

double** criar(int n){
    double **matriz;
    matriz=(double**)malloc(n*sizeof(double*));
    for (int i = 0; i<n; i++){
        matriz[i]=(double*)malloc(sizeof(double)*n);
    }
    return matriz;
}
void zeros(int n, double **matriz){
    for (int i = 0; i<n; i++){
        for(int j = 0; j<n;j++){
            matriz[i][j] = 0;
        }
    }
    return ;
}

void preencher(int n, double** matriz,double h){
    matriz[0][0]=1;
    for (int i = 1; i<n-1; i++){
        matriz[i][i-1]=-1/h;
        matriz[i][i]=2/h;
        matriz[i][i+1]=-1/h;
    }
    matriz[n-1][n-1]=1;
    return ;
}

int main(void){

    int n=10; 
    int a=0;
    int b=1;
    double h=(double)(b-a)/(double)n;
    

    double **matrizz,mat[n+1][n+1];
    matrizz=criar(n+1);

    imprimir(n+1,matrizz);        

    zeros(n+1,matrizz);
            printf("dkkdk\n");

    imprimir(n+1,matrizz);        
    printf(" \n");

    preencher(n+1,matrizz,h);
    imprimir(n+1,matrizz);        
    printf(" \n");


    matrixx(n, mat);
    imprimir2(n+1,mat);        


    return 0 ;
}
