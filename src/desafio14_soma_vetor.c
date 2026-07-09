#include <stdio.h>   /* Entrada e saída padrão (printf, scanf) */
#include <stdlib.h>  /* Alocação dinâmica de memória (malloc, free) */
 
/* ----------------------------------------------------------------
 * Função: calcularSoma
 * ----------------------------------------------------------------
 * Percorre o vetor e acumula a soma de todos os seus elementos.
 *
 * Parâmetros:
 *   vetor[] - array de inteiros a ser somado
 *   tamanho - número de elementos válidos no vetor
 *
 * Retorno:
 *   long long - soma total (tipo maior para evitar overflow
 *               em vetores com muitos elementos grandes)
 * ---------------------------------------------------------------- */
long long calcularSoma(int vetor[], int tamanho) {
    long long soma = 0;  /* Acumulador iniciado em zero */
 
    /* Itera por cada posição do vetor, somando o valor atual */
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];  /* Acumula o elemento na posição i */
    }
 
    return soma;
}
 
/* ----------------------------------------------------------------
 * Função: preencherVetor
 * ----------------------------------------------------------------
 * Solicita ao usuário que insira cada elemento do vetor.
 *
 * Parâmetros:
 *   vetor[]  - array onde os valores serão armazenados
 *   tamanho  - quantidade de elementos a preencher
 * ---------------------------------------------------------------- */
void preencherVetor(int vetor[], int tamanho) {
    printf("\n  Insira os %d elemento(s) do vetor:\n", tamanho);
 
    for (int i = 0; i < tamanho; i++) {
        printf("  vetor[%d] = ", i);
        scanf("%d", &vetor[i]);  /* Lê o valor e armazena na posição i */
    }
}
 
/* ----------------------------------------------------------------
 * Função: exibirVetor
 * ----------------------------------------------------------------
 * Imprime todos os elementos do vetor de forma organizada.
 *
 * Parâmetros:
 *   vetor[]  - array a ser exibido
 *   tamanho  - número de elementos no vetor
 * ---------------------------------------------------------------- */
void exibirVetor(int vetor[], int tamanho) {
    printf("\n  Vetor: [ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
 
        /* Adiciona vírgula entre os elementos, exceto no último */
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}
 
/* ============================================================
 *  Função Principal
 * ============================================================ */
int main(void) {
 
    int tamanho;  /* Armazena o número de elementos do vetor */
 
    /* --------------------------------------------------------
     * Etapa 1: Definir o tamanho do vetor
     * -------------------------------------------------------- */
    printf("============================================\n");
    printf("   Desafio 14 - Soma dos Elementos do Vetor\n");
    printf("============================================\n\n");
 
    printf("  Quantos elementos o vetor tera? ");
    scanf("%d", &tamanho);
 
    /* Validação: o vetor deve ter pelo menos 1 elemento */
    if (tamanho <= 0) {
        printf("\n  [ERRO] O tamanho deve ser maior que zero.\n");
        return 1;  /* Encerra o programa com código de erro */
    }
 
    /* --------------------------------------------------------
     * Etapa 2: Alocar memória dinamicamente para o vetor
     * --------------------------------------------------------
     * Usamos malloc para suportar qualquer tamanho informado
     * pelo usuário, sem desperdiçar memória fixa.
     * -------------------------------------------------------- */
    int *vetor = (int *) malloc(tamanho * sizeof(int));
 
    /* Verifica se a alocação foi bem-sucedida */
    if (vetor == NULL) {
        printf("\n  [ERRO] Falha ao alocar memoria.\n");
        return 1;
    }
 
    /* --------------------------------------------------------
     * Etapa 3: Preencher o vetor com os dados do usuário
     * -------------------------------------------------------- */
    preencherVetor(vetor, tamanho);
 
    /* --------------------------------------------------------
     * Etapa 4: Exibir o vetor preenchido
     * -------------------------------------------------------- */
    exibirVetor(vetor, tamanho);
 
    /* --------------------------------------------------------
     * Etapa 5: Calcular e exibir a soma
     * -------------------------------------------------------- */
    long long soma = calcularSoma(vetor, tamanho);
 
    printf("\n  Soma de todos os elementos: %lld\n", soma);
    printf("\n============================================\n");
 
    /* --------------------------------------------------------
     * Etapa 6: Liberar a memória alocada dinamicamente
     * --------------------------------------------------------
     * Boa prática: sempre liberar o que foi alocado com malloc
     * para evitar vazamentos de memória (memory leaks).
     * -------------------------------------------------------- */
    free(vetor);
    vetor = NULL;  /* Anula o ponteiro após liberar (segurança) */
 
    return 0;  /* Encerramento bem-sucedido do programa */
}
