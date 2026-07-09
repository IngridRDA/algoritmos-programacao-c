#include <stdio.h>   /* Biblioteca padrão de entrada e saída */

/* --------------------------------------------------------
 * Função: celsiusParaFahrenheit
 * Descrição: Converte uma temperatura de Celsius para
 *            Fahrenheit usando a fórmula oficial.
 * Parâmetro: celsius  — temperatura em graus Celsius (float)
 * Retorno  : temperatura equivalente em Fahrenheit (float)
 * -------------------------------------------------------- */
float celsiusParaFahrenheit(float celsius) {
    /*
     * A fórmula F = (C * 9/5) + 32 é o padrão internacional
     * de conversão entre as duas escalas.
     * Usamos 9.0/5.0 (divisão entre floats) para evitar
     * truncamento inteiro, garantindo precisão decimal.
     */
    return (celsius * 9.0 / 5.0) + 32.0;
}

/* --------------------------------------------------------
 * Função: exibirResultado
 * Descrição: Exibe na tela a temperatura original em Celsius
 *            e o resultado convertido em Fahrenheit,
 *            de forma amigável para a usuária.
 * -------------------------------------------------------- */
void exibirResultado(float celsius, float fahrenheit) {
    printf("\n");
    printf("  ==========================================\n");
    printf("       RESULTADO DA CONVERSAO DE MARIA      \n");
    printf("  ==========================================\n");
    printf("  Temperatura em Celsius   : %.2f  C\n", celsius);
    printf("  Temperatura em Fahrenheit: %.2f  F\n", fahrenheit);
    printf("  ==========================================\n");
    printf("\n");
}

/* --------------------------------------------------------
 * Função: validarEntrada
 * Descrição: Verifica se a temperatura informada está dentro
 *            de um intervalo fisicamente plausível.
 *            O zero absoluto é -273.15 °C — abaixo disso
 *            não existe temperatura na natureza.
 * Retorno  : 1 se válida, 0 se inválida
 * -------------------------------------------------------- */
int validarEntrada(float celsius) {
    /* Zero absoluto: limite inferior físico da temperatura */
    const float ZERO_ABSOLUTO = -273.15;

    if (celsius < ZERO_ABSOLUTO) {
        printf("\n  [ERRO] Temperatura abaixo do zero absoluto ");
        printf("(%.2f C).\n", ZERO_ABSOLUTO);
        printf("  Valor fisicamente impossivel. Tente novamente.\n\n");
        return 0; /* Entrada inválida */
    }
    return 1; /* Entrada válida */
}

/* --------------------------------------------------------
 * Função principal (main)
 * Descrição: Ponto de entrada do programa. Coordena a
 *            leitura da entrada, validação e exibição
 *            do resultado para a Maria.
 * -------------------------------------------------------- */
int main(void) {
    float tempCelsius;     /* Temperatura digitada pela usuária */
    float tempFahrenheit;  /* Resultado após a conversão       */
    int   entradaValida;   /* Flag de controle de validação    */

    /* Boas-vindas — contextualiza o programa para a usuária */
    printf("\n  ==========================================\n");
    printf("    Bem-vinda, Maria! Vamos converter sua   \n");
    printf("    temperatura para a escala Fahrenheit.   \n");
    printf("  ==========================================\n\n");

    /*
     * Loop de leitura com validação:
     * Repetimos a pergunta enquanto a entrada for inválida,
     * garantindo que o programa não prossiga com dados ruins.
     */
    do {
        printf("  Digite a temperatura em Celsius: ");

        /*
         * scanf retorna o número de itens lidos com sucesso.
         * Verificamos se foi exatamente 1 para detectar
         * entradas não numéricas (letras, símbolos, etc.).
         */
        if (scanf("%f", &tempCelsius) != 1) {
            /* Limpa o buffer do teclado em caso de entrada inválida */
            while (getchar() != '\n');
            printf("\n  [ERRO] Entrada invalida. Digite apenas numeros.\n\n");
            entradaValida = 0;
        } else {
            /* Valida se o valor está dentro do intervalo físico */
            entradaValida = validarEntrada(tempCelsius);
        }

    } while (!entradaValida);

    /* ── Conversão ─────────────────────────────────────── */
    tempFahrenheit = celsiusParaFahrenheit(tempCelsius);

    /* ── Exibição do resultado ─────────────────────────── */
    exibirResultado(tempCelsius, tempFahrenheit);

    printf("  Boa viagem aos Estados Unidos, Maria!\n\n");

    return 0; /* Encerramento bem-sucedido do programa */
}
