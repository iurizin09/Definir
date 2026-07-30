#include <stdio.h>
#include <math.h>

// funçao cria matriz 


int matriz(int n, int m,int matriz[n][m]){
    for (int i = 0; i<n; i++){
        for(int j = 0; j<m;j++){
            matriz[i][j] = 0;
            printf(" %d", matriz[i][j]);
        }a
        printf(" \n");
    }
}


// funçao prenche matriz



int main(void){

    int n,m; 

    

    printf("Entre com a coluna e linha da matriz:");
    scanf("%d %d",&n,&m);
    int matrizz[n][m];

    matriz(n,m,matrizz);



    return 0 ;
}
