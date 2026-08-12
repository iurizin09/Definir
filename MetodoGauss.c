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
}

int VericaPivo(double matriz[linhas][colunas],int linha,int coluna)// retorna linha que esta o piov
{
// retornar linha e coluna do pivo;
    double pivo = 0;
    int linhaA = 0;
    for(linha;linha < linhas;linha++){
       if(fabs(matriz[linha][coluna]) > pivo){
        pivo = fabs(matriz[linha][coluna]);
        linhaA = linha;
       }
}
return linhaA;
}

// troca linhas 

void trocaLinhas(double matriz[linhas][colunas],int linha1,int linha2){
   double aux;
   for(int j = 0; j < colunas; j++){
       aux = matriz[linha1][j];
       matriz[linha1][j] = matriz[linha2][j];
       matriz[linha2][j] = aux;
   }
}

void trocaLinhas2(double matriz[linhas][colunas],int linha1,int linha2,int coluna){
   double aux;
   if(matriz[linha1][coluna] == matriz[linha2][coluna]){
    return;
   }
   for(int j = 0; j < colunas; j++){
       aux = matriz[linha1][j];
       matriz[linha1][j] = matriz[linha2][j];
       matriz[linha2][j] = aux;
   }
}



void eliminaColuna(double matriz[linhas][colunas],int linha,int coluna)// linha e coluna do pivo para trocarmoso no segundo termo OU SEJA e o pivo pode ser OUTRO DEPOIS poe exemplo o 
{
   for(int i = 0 ; i < linhas  ; i++){ //  aqui so vai de  
        double termo = matriz[i+1][coluna] / matriz[linha][coluna]  ;// matriz[0][0] = 4 / -2 matriz [1][0] 
        for (int j = 0; j < colunas ; j++)
      {             matriz[i+1][j] = (-termo)*matriz[linha][coluna] + matriz[i+1][j]; // deve pegar o termo
          imprimir(matriz);
        printf("\n");
        }       
  }
    return;}

int main(void){

// metodo de gausss definir matriz
double matriz[linhas][colunas] = {
                    {1,-3,2,11},
                    {-2,8,-1,-15},
                    {4,-6,5,29}};

imprimir(matriz);

//vericar pivo coluna 1

int linha_pivo = VericaPivo(matriz,0,0); // verifica linha do pivo
double pivo = matriz[linha_pivo][0];
printf("O pivo da coluna 1 é: %.1lf \n",pivo);

trocaLinhas(matriz,linha_pivo,0); // linha que ta 


//printf("\n");
eliminaColuna(matriz,0,0); // essa linha e coluna do pivo pode mudar

///////////////////

int linha_pivo2 = VericaPivo(matriz,1,1); // estou utilzaindo esse varia para verificar o da coluna e linha
double pivo2 = matriz[linha_pivo2][1];
printf("O pivo da coluna 2 é: %.1lf \n",pivo2);

trocaLinhas2(matriz,linha_pivo2,2,1);

//imprimir(matriz);
//void trocaLinhas2(double matriz[linhas][colunas],int linha1,int linha2,int coluna){
//   double aux;
//   if(matriz[linha1][coluna] == matriz[linha2][coluna]){
//    return;
//   }
//   for(int j = 0; j < colunas; j++){
//       aux = matriz[linha1][j];
//       matriz[linha1][j] = matriz[linha2][j];
//      matriz[linha2][j] = aux;
//   }
//}


//printf("\n");
//eliminaColuna(matriz,1,1); // essa linha e coluna do pivo pode mudar
//imprimir(matriz);





return 0 ;
}

