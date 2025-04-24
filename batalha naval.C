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


             // Posiçoes iniciais em que os navios diagonais irão ocupar
    
    int linhaDiagonal1 = 6;  // 7ª linha
    int colunaDiagonal1 = 3;  // 4ª coluna

    int linhaDiagonal2 = 0; // 1ª linha
    int colunaDiagonal2 = 9; // 10ª linha


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
     

                // Navio Diagonal 1

    int navioDiagonal1[tamanhoNavio] = {3, 3, 3};   // Array representando o navio diagonal 1, [tamanho do navio] {numero represntando o navio}
    
    if (linhaDiagonal1 + tamanhoNavio <= linhas && colunaDiagonal1 + tamanhoNavio <= colunas) {      //  detecção se esta dentro do tabuleiro
        int sobreposicao = 0;
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] != 0) {    // verificção se ja tem um navio na posição
                sobreposicao = 1;       // detecção de algo diferente de agua
                break;      // em caso de colisão, algo diferente de 0, o loop é parado
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < tamanhoNavio; i++) {      // estrutura de repetição para sobrepor na diagonal a partir da posição inicial
                tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] = navioDiagonal1[i];
            }
        }
    }   

                    // Navio Diagonal 2     

    int navioDiagonal2[tamanhoNavio] = {3, 3, 3};     // Array representando o navio diagonal 2, [tamanho do navio] {numero represntando o navio}
    
    if (linhaDiagonal2 + tamanhoNavio <= linhas && colunaDiagonal2 - tamanhoNavio >= 0) {   //  detecção se esta dentro do tabuleiro
        int sobreposicao = 0;
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] != 0) {       // verificção se ja tem um navio na posição
                sobreposicao = 1;     // detecção de algo diferente de agua
                break;        // em caso de colisão, algo diferente de 0, o loop é parado
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < tamanhoNavio; i++) {          // estrutura de repetição para sobrepor na diagonal a partir da posição inicial
                tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] = navioDiagonal2[i];
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
