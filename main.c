#include <stdio.h>

int main(void) {
    int saldo = 1000, valorSaque, restante;
    int notas100, notas50, notas20, notas10, notas5, notas2, moedas1;
    int leitura, caractere, entradaValida, saqueValido;
    int opcao = 2;

    printf("Saldo disponivel: R$ %d,00\n", saldo);

    while (opcao != 3) {
        if (opcao == 1) {
            printf("Saldo disponivel: R$ %d,00\n", saldo);
        } else if (opcao == 2 && saldo == 0) {
            printf("Saldo insuficiente para realizar um novo saque.\n");
        } else if (opcao == 2) {
            saqueValido = 0;
            while (saqueValido == 0) {
                printf("Digite o valor do saque em reais: ");
                leitura = scanf("%d", &valorSaque);
                if (leitura == EOF) {
                    printf("\nProcesso encerrado.\n");
                    return 0;
                }
                entradaValida = (leitura == 1);
                while ((caractere = getchar()) != '\n' && caractere != EOF) {
                    if (caractere != ' ' && caractere != '\t' && caractere != '\r') {
                        entradaValida = 0;
                    }
                }
                if (entradaValida == 0) {
                    printf("Entrada invalida. Digite apenas um valor inteiro.\n");
                } else if (valorSaque <= 0) {
                    printf("Erro: informe um valor positivo.\n");
                    saqueValido = 1;
                } else if (valorSaque % 5 != 0) {
                    printf("Erro: o saque deve ser multiplo de 5.\n");
                    saqueValido = 1;
                } else if (valorSaque > saldo) {
                    printf("Erro: saldo insuficiente.\n");
                    saqueValido = 1;
                } else {
                    saqueValido = 1;
                    saldo -= valorSaque;
                    restante = valorSaque;

                    notas100 = restante / 100;
                    restante = restante % 100;

                    notas50 = restante / 50;
                    restante = restante % 50;

                    notas20 = restante / 20;
                    restante = restante % 20;

                    notas10 = restante / 10;
                    restante = restante % 10;

                    notas5 = restante / 5;
                    restante = restante % 5;

                    notas2 = restante / 2;
                    restante = restante % 2;

                    moedas1 = restante;

                    printf("Saque realizado: R$ %d,00\n", valorSaque);
                    printf("Notas entregues:\n");
                    if (notas100 > 0) printf("%d nota(s) de R$ 100\n", notas100);
                    if (notas50 > 0) printf("%d nota(s) de R$ 50\n", notas50);
                    if (notas20 > 0) printf("%d nota(s) de R$ 20\n", notas20);
                    if (notas10 > 0) printf("%d nota(s) de R$ 10\n", notas10);
                    if (notas5 > 0) printf("%d nota(s) de R$ 5\n", notas5);
                    if (notas2 > 0) printf("%d nota(s) de R$ 2\n", notas2);
                    if (moedas1 > 0) printf("%d nota(s) de R$ 1\n", moedas1);

                    printf("Saldo atualizado: R$ %d,00\n", saldo);
                }
            }
        }

        opcao = 0;
        while (opcao < 1 || opcao > 3) {
            printf("\nDeseja realizar uma nova transacao?\n");
            printf("1 - Consultar saldo\n");
            printf("2 - Realizar novo saque\n");
            printf("3 - Sair\n");
            printf("Escolha uma opcao: ");
            leitura = scanf("%d", &opcao);
            if (leitura == EOF) return 0;
            entradaValida = (leitura == 1);
            while ((caractere = getchar()) != '\n' && caractere != EOF) {
                if (caractere != ' ' && caractere != '\t' && caractere != '\r') {
                    entradaValida = 0;
                }
            }
            if (entradaValida == 0 || opcao < 1 || opcao > 3) {
                printf("Opcao invalida. Digite 1, 2 ou 3.\n");
                opcao = 0;
            }
        }
    }

    printf("Processo encerrado.\n");
    return 0;
}
```[cite: 5, 6]

---

### Passo a passo para adicionar no GitHub:
1. Abra o repositório **`-Sistema-de-Caixa-Eletr-nico`** no GitHub[cite: 5].
2. Clique no botão **Add file** (Adicionar arquivo) > **Create new file** (Criar novo arquivo).
3. No campo de nome do arquivo lá em cima, digite exatamente:
   ```text
   main.c
