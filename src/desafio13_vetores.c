#include <stdio.h>/* Biblioteca para entrada e saída (printf, scanf) */
 
int main() {
 
    /* ---------------------------------------------------
     * Declaração do vetor
     * ---------------------------------------------------
     * Um vetor em C é uma coleção de elementos do mesmo
     * tipo armazenados em posições contíguas de memória.
     * Aqui declaramos um vetor de 10 inteiros.
     * O índice vai de 0 (primeiro) até 9 (último).
     * --------------------------------------------------- */
    int numeros[10];
 
    int i; /* variável de controle do laço de repetição */
 
    /* ---------------------------------------------------
     * Fase 1: Preenchimento do vetor
     * ---------------------------------------------------
     * Percorremos cada posição do vetor (de 0 a 9) e
     * solicitamos ao André que digite o número sugerido
     * pelo colega correspondente.
     * --------------------------------------------------- */
    printf("========================================\n");
    printf("   Auxiliando o André - Turma de Prog.  \n");
    printf("========================================\n\n");
 
    printf("Digite os 10 números sugeridos pelos colegas:\n\n");
 
    for (i = 0; i < 10; i++) {
 
        /* Exibe qual colega está sendo registrado (1 a 10, mais intuitivo) */
        printf("  Colega %2d -> Digite um número: ", i + 1);
 
        /* Lê o valor digitado e armazena na posição i do vetor */
        scanf("%d", &numeros[i]);
        /*
         * NOTA: o operador & (endereço) é necessário para que o scanf
         * saiba onde na memória guardar o valor lido.
         */
    }
 
    /* ---------------------------------------------------
     * Fase 2: Impressão do vetor
     * ---------------------------------------------------
     * Percorremos novamente o vetor do início ao fim e
     * exibimos cada elemento com seu respectivo índice,
     * para que André veja o resultado completo.
     * --------------------------------------------------- */
    printf("\n========================================\n");
    printf("       Resultado do Vetor do André       \n");
    printf("========================================\n\n");
 
    printf("  Índice  |  Valor\n");
    printf("  --------+---------\n");
 
    for (i = 0; i < 10; i++) {
 
        /* Imprime o índice (entre colchetes) e o valor armazenado */
        printf("  [  %2d  ] |  %d\n", i, numeros[i]);
    }
 
    printf("\n========================================\n");
    printf("  Vetor preenchido com sucesso, André!  \n");
    printf("========================================\n\n");
 
    return 0; /* Indica que o programa terminou sem erros */
}
