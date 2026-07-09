#include <stdio.h>   /* Biblioteca para entrada e saída (printf, scanf) */
 
/* --------------------------------------------------------------------------
 * FUNÇÃO: somaIterativa
 * --------------------------------------------------------------------------
 * Calcula a soma dos primeiros N números naturais usando um laço de repetição.
 * A cada iteração, o valor de 'i' é acumulado na variável 'soma'.
 *
 * Parâmetro: n  - quantidade de números a somar (deve ser >= 1)
 * Retorno  : soma acumulada de 1 até n
 * -------------------------------------------------------------------------- */
long long somaIterativa(int n) {
    long long soma = 0; /* Acumulador da soma; começa em zero */
    int i;              /* Variável de controle do laço */
 
    /* Percorre cada número de 1 até N, acumulando a soma */
    for (i = 1; i <= n; i++) {
        soma += i;      /* Equivalente a: soma = soma + i */
    }
 
    return soma;
}
 
/* --------------------------------------------------------------------------
 * FUNÇÃO PRINCIPAL
 * -------------------------------------------------------------------------- */
int main(void) {
 
    int       n;        /* Valor de N informado pelo usuário (Lucas) */
    long long resultado; /* Armazena o resultado da soma iterativa   */
 
    /* -----------------------------------------------------------------------
     * ENTRADA DE DADOS
     * ----------------------------------------------------------------------- */
    printf("============================================\n");
    printf("  SOMA DOS N PRIMEIROS NUMEROS NATURAIS\n");
    printf("  Auxiliando Lucas na aula de matematica!\n");
    printf("============================================\n\n");
 
    printf("Lucas, informe o valor de N: ");
    scanf("%d", &n);
 
    /* -----------------------------------------------------------------------
     * VALIDAÇÃO: N deve ser um número natural positivo (>= 1)
     * ----------------------------------------------------------------------- */
    if (n < 1) {
        printf("\nERRO: Por favor, informe um numero inteiro positivo (N >= 1).\n");
        return 1; /* Encerra o programa com código de erro */
    }
 
    /* -----------------------------------------------------------------------
     * PROCESSAMENTO: chama a função de soma iterativa
     * ----------------------------------------------------------------------- */
    resultado = somaIterativa(n);
 
    /* -----------------------------------------------------------------------
     * SAÍDA: exibe o passo a passo e o resultado final
     * ----------------------------------------------------------------------- */
    printf("\n--- Passo a passo da soma ---\n");
    printf("Soma = ");
 
    /* Imprime a sequência "1 + 2 + 3 + ... + N" para visualização didática */
    int i;
    for (i = 1; i <= n; i++) {
        if (i < n)
            printf("%d + ", i);
        else
            printf("%d", i); /* Último número: sem o "+" no final */
    }
 
    printf("\n\n--- Resultado ---\n");
    printf("A soma dos %d primeiros numeros naturais e: %lld\n", n, resultado);
 
    printf("\nParabens, Lucas! Problema resolvido com sucesso!\n");
    printf("============================================\n");
 
    return 0; /* Encerra o programa com sucesso */
}
 
/* ==========================================================================
 * EXEMPLOS DE EXECUÇÃO
 * ==========================================================================
 *
 * Exemplo 1 — N = 5:
 *   Soma = 1 + 2 + 3 + 4 + 5
 *   Resultado = 15
 *
 * Exemplo 2 — N = 10:
 *   Soma = 1 + 2 + ... + 10
 *   Resultado = 55
 *
 * Exemplo 3 — N = 100:
 *   Resultado = 5050
 *
 * NOTA TÉCNICA:
 *   - Tipo 'long long' suporta valores até ~9,2 * 10^18, suficiente para
 *     N até aproximadamente 4,2 bilhões antes de causar overflow.
 * ========================================================================== */
