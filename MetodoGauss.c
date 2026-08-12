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

double VericaPivo(double matriz[linhas][colunas],int linha,int coluna)// retorna linha que esta o piov
{
// retornar linha e coluna do pivo;
    double pivo = 0;
    double linhaA = 0;
    for(linha;linha < linhas;linha++){
       if(fabs(matriz[linha][coluna]) > pivo){
        pivo = fabs(matriz[linha][coluna]);
        linhaA = linha;
       }
}
return linhaA;
}

// troca linhas 

void trocaLinhas(double matriz[linhas][colunas],int linha1,int linha2,int coluna)
// como sempre vai ocorrer troca ou nao de linhas, entao nao e preciso passar a coluna, pois a troca e de toda a linha
{
    if(matriz[linha1][coluna] == matriz[linha2][coluna]){
        return ; // se por exemplo a linha 1 e 2 forem iguais, nao precisa trocar
    }
     double aux;
    for(int j = 0; j < colunas; j++){
       aux = matriz[linha1][j];
       matriz[linha1][j] = matriz[linha2][j];
       matriz[linha2][j] = aux;
   }
}




void eliminaColuna(double matriz[linhas][colunas],int linha,int coluna,int k,int linha_atual )// linha e coluna do pivo para trocarmoso no segundo termo OU SEJA e o pivo pode ser OUTRO DEPOIS poe exemplo o 
{
   for(int i = 0 ; i < linhas -  k  ; i++){ //  aqui so vai de
        double termo = matriz[linha_atual+1][coluna] / matriz[linha][coluna]  ;// matriz[2][1] = -4 / 10 matriz [1][0]
        for (int j = 0; j < colunas ; j++) {
        double aux = matriz[linha_atual+1][j];  // matriz 
        if(aux != 0){
        matriz[linha_atual+1][j] = (-termo)*matriz[linha][coluna] + aux; // deve pegar o termo
        } 
        } 
         linha_atual++;
    }
}

int main(void){

// metodo de gausss definir matriz
double matriz[linhas][colunas] = {
                    {1,-3,2,11},
                    {-2,8,-1,-15},
                    {4,-6,5,29}};
int linha_pivo = 0;
for(int i = 0 ; i < colunas-2;i++){
linha_pivo = VericaPivo(matriz,i,i); // verifica linha do pivo
trocaLinhas(matriz,linha_pivo,i,i);
eliminaColuna(matriz,i,i,i+1,i); // essa linha e coluna do pivo pode mudar
imprimir(matriz);
printf("\n");
}

return 0 ;
}
