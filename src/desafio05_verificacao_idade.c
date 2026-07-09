/* Biblioteca padrão de entrada e saída */
#include <stdio.h>
 
/* Constante que define a idade mínima exigida para votar */
#define IDADE_MINIMA_VOTO 18
 
int main() {
 
    /* ----- Declaração de variáveis ----- */
    int dia_nasc, mes_nasc, ano_nasc;   /* Data de nascimento do cidadão      */
    int dia_atual, mes_atual, ano_atual; /* Data atual fornecida pelo usuário  */
    int idade;                           /* Idade calculada em anos completos  */
 
    /* =========================================================================
     * BLOCO 1: ENTRADA DE DADOS - Data de nascimento
     * ========================================================================= */
    printf("=================================================\n");
    printf("   SISTEMA DE REGISTRO ELEITORAL\n");
    printf("=================================================\n\n");
 
    printf("Bem-vindo, Joaquim! Vamos verificar sua elegibilidade.\n\n");
 
    printf("Informe sua data de nascimento:\n");
 
    printf("  Dia   : ");
    scanf("%d", &dia_nasc);
 
    printf("  Mes   : ");
    scanf("%d", &mes_nasc);
 
    printf("  Ano   : ");
    scanf("%d", &ano_nasc);
 
    /* =========================================================================
     * BLOCO 2: ENTRADA DE DADOS - Data atual
     * =========================================================================
     * Em um sistema real, a data atual seria obtida automaticamente via
     * funções da biblioteca <time.h>. Aqui solicitamos ao usuário para
     * manter o código simples e didático.
     * ========================================================================= */
    printf("\nInforme a data de hoje:\n");
 
    printf("  Dia   : ");
    scanf("%d", &dia_atual);
 
    printf("  Mes   : ");
    scanf("%d", &mes_atual);
 
    printf("  Ano   : ");
    scanf("%d", &ano_atual);
 
    /* =========================================================================
     * BLOCO 3: CÁLCULO DA IDADE
     * =========================================================================
     * Passo 1: Calcula a diferença entre o ano atual e o ano de nascimento.
     * Passo 2: Verifica se o aniversário ainda NÃO ocorreu neste ano.
     *          - Se o mês atual for ANTES do mês de nascimento, ou
     *          - Se estiver no mesmo mês, mas o dia atual for ANTES do dia
     *            de nascimento,
     *          então subtrai 1 do total, pois o aniversário ainda não chegou.
     * ========================================================================= */
    idade = ano_atual - ano_nasc;
 
    /*
     * Verifica se o aniversário ainda não ocorreu no ano corrente.
     * A condição usa operador lógico OR (||) para cobrir dois subcasos:
     *   a) mês de nascimento ainda não chegou
     *   b) estamos no mês do aniversário, mas o dia ainda não chegou
     */
    if (mes_atual < mes_nasc || (mes_atual == mes_nasc && dia_atual < dia_nasc)) {
        idade--; /* Decrementa pois o aniversário ainda não ocorreu este ano */
    }
 
    /* =========================================================================
     * BLOCO 4: VERIFICAÇÃO E EXIBIÇÃO DO RESULTADO
     * =========================================================================
     * Compara a idade calculada com a constante IDADE_MINIMA_VOTO (18).
     * Exibe uma mensagem personalizada de acordo com o resultado.
     * ========================================================================= */
    printf("\n=================================================\n");
    printf("   RESULTADO DA VERIFICACAO\n");
    printf("=================================================\n");
    printf("  Cidadao : Joaquim\n");
    printf("  Idade   : %d anos\n", idade);
    printf("-------------------------------------------------\n");
 
    if (idade >= IDADE_MINIMA_VOTO) {
        /* Cidadão possui idade suficiente para votar */
        printf("  Status  : APTO PARA VOTAR\n");
        printf("\n  Parabens, Joaquim! Voce tem %d anos e possui\n", idade);
        printf("  idade suficiente para se registrar como eleitor.\n");
    } else {
        /* Cidadão ainda não atingiu a idade mínima */
        int anos_faltando = IDADE_MINIMA_VOTO - idade;
        printf("  Status  : NAO APTO PARA VOTAR\n");
        printf("\n  Infelizmente, Joaquim, voce tem %d anos e ainda\n", idade);
        printf("  nao atingiu a idade minima de %d anos.\n", IDADE_MINIMA_VOTO);
        printf("  Faltam %d ano(s) para que possa se registrar.\n", anos_faltando);
    }
 
    printf("=================================================\n");
 
    return 0; /* Encerra o programa com sucesso */
}
