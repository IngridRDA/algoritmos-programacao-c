/* Biblioteca padrão para entrada e saída (printf, scanf) */
#include <stdio.h>   
 
int main(void) {
 
    /* --------------------------------------------------------
     * DECLARAÇÃO DE VARIÁVEIS
     * Usamos float para permitir notas com casas decimais,
     * como 7.5 ou 8.3, que são muito comuns em boletins.
     * -------------------------------------------------------- */
    float nota_matematica;   /* Nota da prova de Matemática  */
    float nota_portugues;    /* Nota da prova de Português   */
    float nota_ciencias;     /* Nota da prova de Ciências    */
    float media;             /* Média final calculada        */
 
    /* --------------------------------------------------------
     * CABEÇALHO DO PROGRAMA
     * -------------------------------------------------------- */
    printf("============================================\n");
    printf("   CALCULADORA DE MEDIA DE NOTAS - PEDRO   \n");
    printf("============================================\n\n");
 
    /* --------------------------------------------------------
     * ENTRADA DE DADOS
     * O comando scanf lê o valor digitado pelo usuário e o
     * armazena no endereço de memória da variável indicada
     * pelo operador &.
     * O formato "%.1f" limita a exibição a 1 casa decimal.
     * -------------------------------------------------------- */
    printf("Digite as notas de Pedro (de 0.0 a 10.0):\n\n");
 
    printf("  Nota de Matematica: ");
    scanf("%f", &nota_matematica);
 
    printf("  Nota de Portugues : ");
    scanf("%f", &nota_portugues);
 
    printf("  Nota de Ciencias  : ");
    scanf("%f", &nota_ciencias);
 
    /* --------------------------------------------------------
     * CÁLCULO DA MÉDIA ARITMÉTICA SIMPLES
     * Todas as disciplinas têm o mesmo peso, portanto
     * somamos as três notas e dividimos por 3.
     *
     * ATENÇÃO: dividimos por 3.0 (float) e não por 3 (int)
     * para garantir que a divisão seja feita em ponto
     * flutuante, evitando perda de precisão.
     * -------------------------------------------------------- */
    media = (nota_matematica + nota_portugues + nota_ciencias) / 3.0;
 
    /* --------------------------------------------------------
     * EXIBIÇÃO DO RESULTADO
     * -------------------------------------------------------- */
    printf("\n--------------------------------------------\n");
    printf("  BOLETIM DO PEDRO\n");
    printf("--------------------------------------------\n");
    printf("  Matematica : %.1f\n", nota_matematica);
    printf("  Portugues  : %.1f\n", nota_portugues);
    printf("  Ciencias   : %.1f\n", nota_ciencias);
    printf("  ---------------------\n");
    printf("  Media Final: %.2f\n", media);
    printf("--------------------------------------------\n");
 
    /* --------------------------------------------------------
     * VERIFICAÇÃO DA SITUAÇÃO DO ALUNO
     * Utilizamos estrutura if-else if-else para classificar
     * o resultado com base na média obtida.
     * -------------------------------------------------------- */
    printf("  Situacao   : ");
 
    if (media >= 6.0) {
        /* Média suficiente para aprovação direta */
        printf("APROVADO! Parabens, Pedro!\n");
 
    } else if (media >= 4.0) {
        /* Média insuficiente, mas elegível à recuperação */
        printf("RECUPERACAO. Estude mais, Pedro!\n");
 
    } else {
        /* Média abaixo do mínimo para recuperação */
        printf("REPROVADO. Nao desista, Pedro!\n");
    }
 
    printf("============================================\n\n");
 
    return 0;   /* Indica ao sistema operacional que o programa encerrou com sucesso */
}
