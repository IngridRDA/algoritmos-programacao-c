#include <stdio.h> /* Biblioteca para entrada e saída (printf, scanf) */
 
int main(void) {
 
    /* -------------------------------------------------------
     * Declaração de variáveis
     *   numero    → número escolhido pelo Pedro para a tabuada
     *   resultado → produto da multiplicação em cada linha
     *   i         → contador do laço (de 1 até 10)
     * ------------------------------------------------------- */
    int numero, resultado, i;
 
    /* -------------------------------------------------------
     * Entrada de dados
     *   Solicita ao usuário o número desejado para a tabuada.
     *   %d lê um inteiro e armazena em &numero.
     * ------------------------------------------------------- */
    printf("========================================\n");
    printf("       TABUADA DO PEDRO                 \n");
    printf("========================================\n");
    printf("Digite o numero para gerar a tabuada: ");
    scanf("%d", &numero);
 
    /* -------------------------------------------------------
     * Validação simples
     *   Verifica se o número digitado é positivo (>= 1).
     *   Caso negativo ou zero, exibe aviso e encerra.
     *   Nota: esta validação é básica; pode ser expandida
     *   para tratar entradas inválidas (letras, etc.) com
     *   técnicas mais avançadas (ex.: fgets + strtol).
     * ------------------------------------------------------- */
    if (numero <= 0) {
        printf("\nPor favor, informe um numero inteiro positivo!\n");
        return 1; /* encerra o programa com código de erro */
    }
 
    /* -------------------------------------------------------
     * Processamento e saída — laço for
     *
     *   Estrutura: for (inicialização; condição; incremento)
     *
     *   - i começa em 1 (primeira linha da tabuada)
     *   - continua enquanto i <= 10
     *   - i++ incrementa o multiplicador a cada iteração
     *
     *   Em cada iteração:
     *     1. Calcula o produto: resultado = numero * i
     *     2. Imprime a linha no formato "N x I = R"
     * ------------------------------------------------------- */
    printf("\n--- Tabuada do %d ---\n\n", numero);
 
    for (i = 1; i <= 10; i++) {
 
        resultado = numero * i;   /* calcula o produto */
 
        /* Formata a saída alinhando os campos com %2d
         * para que números de 1 dígito (1-9) fiquem
         * alinhados com os de 2 dígitos (10).           */
        printf("%2d x %2d = %3d\n", numero, i, resultado);
    }
 
    printf("\n========================================\n");
    printf("  Bons estudos, Pedro!                  \n");
    printf("========================================\n");
 
    return 0; /* encerra o programa com sucesso */
}
