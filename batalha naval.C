#include<stdio.h>

   #define linhas 10
   #define colunas 10
   #define tamanhoNavio 3
  
int main(){

             //Tabuleiro

    int tabuleiro[linhas][colunas]; // Matriz 10x10 representando o tabuleiro

             // Inicializando o tabuleiro com 0 (água)

    for (int i = 0; i < linhas; i++) {             
        for (int j = 0; j < colunas; j++) {   
            tabuleiro[i][j] = 0;              // representação do tabuleiro, 0 = água
        }
    }
          
             // Posiçoes iniciais em que o navio horizontal irá ocupar
             
    int linhaHorizontal = 2;  // 3ª linha
    int colunaHorizontal = 1;  // 2ª coluna

              
              // Posiçoes iniciais em que o navio vertical irá ocupar

    int linhaVertical = 4;   // 5ª linha
    int colunaVertical = 5;  // 6ª coluna


             //  Navio horizontal

    int navioHorizontal[tamanhoNavio] = {3, 3, 3};  // Array representando o navio horizontal, [tamanho do navio] {numero represntando o navio}


    if (colunaHorizontal + tamanhoNavio <= colunas) {        
        int sobreposicao = 0;
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] != 0) {   // verificção se ja tem um navio na posição
                sobreposicao = 1;    // detecção de algo diferente de agua
                break;   // em caso de colisão, algo diferente de 0, o loop é parado
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < tamanhoNavio; i++) {   // estrutura de repetição para repetir 3 colunas na mesma linha a paritr da posição inicial
                tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];   
            } 
        }
    }


              //  Navio Vertical
 
    int navioVertical[tamanhoNavio] = {3, 3, 3};  // Array representando o navio vertical, [tamanho do navio] {numero represntando o navio}


    if (linhaVertical + tamanhoNavio <= linhas) {
        int sobreposicao = 0;
        for (int j = 0; j < tamanhoNavio; j++) {
            if (tabuleiro[linhaVertical + j][colunaVertical] != 0) {     // verificção se ja tem um navio na posição
                sobreposicao = 1;    // detecção de algo diferente de agua
                break;  // em caso de colisão, algo diferente de 0, o loop é parado
            }
        }

        if (!sobreposicao) { 
            for (int j = 0; j < tamanhoNavio; j++) {   // estrutura de repetição para repetir 3 linhas na mesma coluna a paritr da posição inicial
                tabuleiro[linhaVertical + j][colunaVertical] = navioVertical[j];       
            }
        }
    }


               // Tabuleiro final com os Naios

    printf("\nTabuleiro Batalha Naval:\n\n");   
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
