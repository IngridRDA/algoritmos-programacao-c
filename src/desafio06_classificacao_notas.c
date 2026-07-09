/* Biblioteca padrão de entrada e saída */
#include <stdio.h>
 
int main() {
 
    /* --------------------------------------------------------
     * Declaração de variáveis
     * --------------------------------------------------------
     * 'nota'    -> armazena o valor real digitado pelo usuário
     * 'conceito'-> armazena o caractere do conceito calculado
     * -------------------------------------------------------- */
    float nota;
    char  conceito;
 
    /* --------------------------------------------------------
     * Leitura da nota
     * --------------------------------------------------------
     * "%f" lê um número de ponto flutuante (float).
     * O operador & indica o endereço de memória da variável.
     * -------------------------------------------------------- */
    printf("=== Classificacao de Notas - Aluna Maria ===\n\n");
    printf("Digite a nota de Maria (0.0 a 10.0): ");
    scanf("%f", &nota);
 
    /* --------------------------------------------------------
     * Validação da entrada
     * --------------------------------------------------------
     * Notas válidas estão no intervalo fechado [0, 10].
     * Caso o valor informado esteja fora desse intervalo,
     * o programa exibe um aviso e encerra sem classificar.
     * -------------------------------------------------------- */
    if (nota < 0.0 || nota > 10.0) {
        printf("\nNota invalida! Por favor, informe um valor entre 0.0 e 10.0.\n");
        return 1; /* Retorno diferente de 0 indica erro ao sistema operacional */
    }
 
    /* --------------------------------------------------------
     * Classificação por conceito
     * --------------------------------------------------------
     * Os blocos if/else if são verificados na ordem:
     *   1º) A  -> nota >= 9.0
     *   2º) B  -> nota >= 7.0  (já se sabe que nota < 9.0)
     *   3º) C  -> nota >= 5.0  (já se sabe que nota < 7.0)
     *   4º) D  -> nota >= 3.0  (já se sabe que nota < 5.0)
     *   5º) F  -> demais casos (nota < 3.0)
     *
     * IMPORTANTE: Graças ao encadeamento else if, cada condição
     * subsequente não precisa repetir o limite superior —
     * ele já foi descartado pelo bloco anterior.
     * -------------------------------------------------------- */
    if (nota >= 9.0) {
        conceito = 'A';                 /* Excelente */
    } else if (nota >= 7.0) {
        conceito = 'B';                 /* Bom */
    } else if (nota >= 5.0) {
        conceito = 'C';                 /* Regular */
    } else if (nota >= 3.0) {
        conceito = 'D';                 /* Insuficiente */
    } else {
        conceito = 'F';                 /* Muito insuficiente */
    }
 
    /* --------------------------------------------------------
     * Exibição do resultado
     * --------------------------------------------------------
     * "%.1f" formata o float com exatamente 1 casa decimal,
     * garantindo uma apresentação padronizada (ex.: 8.5, 10.0).
     * "%c"   exibe o caractere do conceito.
     * -------------------------------------------------------- */
    printf("\n--------------------------------------------\n");
    printf("  Nota informada : %.1f\n", nota);
    printf("  Conceito obtido: %c\n",   conceito);
    printf("--------------------------------------------\n");
 
    return 0; /* Programa encerrado com sucesso */
}
