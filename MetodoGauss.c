#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define colunas 4
#define linhas 3

void imprimir(double matriz[linhas][colunas]){
    for (int i = 0; i<linhas; i++){
        for(int j = 0; j<colunas;j++){
            printf(" %.1lf ", matriz[i][j]);
        }
        printf(" \n");
    }
    printf("\n");
}

int VericaPivo(double matriz[linhas][colunas],int linha,int coluna)// retorna linha que esta o piov
{
// retornar linha e coluna do pivo;
    int pivo = 0;
    int linhaA = 0;

    for(;linha < linhas;linha++){
       if(fabs(matriz[linha][coluna]) > pivo){
        pivo = fabs(matriz[linha][coluna]);
        linhaA = linha;
       }
}

return linhaA;
}

// troca linhas 

void trocaLinha(double matriz[linhas][colunas],int linha1,int linha2,int coluna)
// como sempre vai ocorrer troca ou nao de linhas, entao nao e preciso passar a coluna, pois a troca e de toda a linha
{
     double aux;
    for(int j = 0; j < colunas; j++){
       aux = matriz[linha1][j];
       matriz[linha1][j] = matriz[linha2][j];
       matriz[linha2][j] = aux;
   }
}




void eliminaColuna(double matriz[linhas][colunas],int linha,int coluna)// linha e coluna do pivo para trocarmoso no segundo termo OU SEJA e o pivo pode ser OUTRO DEPOIS poe exemplo o 
{
   for(int i = coluna + 1 ; i < linhas; i++){ //  aqui so vai de
        double termo = matriz[i][coluna] / matriz[linha][coluna]  ;// matriz[2][1] = -4 / 10 matriz [1][0]
        for (int j = coluna; j < colunas ; j++) {
            matriz[i][j] = (-termo)*matriz[linha][j] + matriz[i][j]; // deve pegar o termo e
        } 
    
    }
}


void eliminaColuna2(double matriz[linhas][colunas],int linha,int coluna)//  2  2linha e coluna do pivo para trocarmoso no segundo termo OU SEJA e o pivo pode ser OUTRO DEPOIS poe exemplo o 
{
   for(int i = linha - 1; i >=0  ; i--){ //  2

        double termo = matriz[i][coluna] / matriz[linha][coluna]  ;// matriz[2][1] = -4 / 10 matriz [1][0]

        for (int j = coluna; j < colunas ; j++) { //2 2
            
            matriz[i][j] = (-termo)*matriz[linha][j] + matriz[i][j]; //
             
            
        } 
    }
}




// verificar

int main(void){

// metodo de gausss definir matriz
double matriz[linhas][colunas] = {
                    {1,-3,2,11},
                    {-2,8,-1,-15},
                    {4,-6,5,29}};
int linha_pivo = 0;
int i ;

for(i= 0; i < colunas-2;i++){
linha_pivo = VericaPivo(matriz,i,i); // verifica linha do pivo

if(matriz[linha_pivo][i] != matriz[i][i]){
    
      trocaLinha(matriz,linha_pivo,i,i);// // se por exemplo a linha 1 e 2 forem iguais, nao precisa trocar
    }

 eliminaColuna(matriz,i,i); // essa linha e coluna do pivo pode mudar
 imprimir(matriz);
  

}


for(i = linhas - 1 ; i >= 0 ;i--){
    eliminaColuna2(matriz,i,i); // essa linha e coluna do pivo pode mudar
    matriz[i][colunas-1] = matriz[i][colunas-1]/matriz[i][i];

}

imprimir(matriz);


return 0 ;
}
