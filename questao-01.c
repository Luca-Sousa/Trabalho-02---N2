#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definificação de variáveis verdadeiro e Falso
#define true 1;
#define false 0;

int verifica_forma_xy(char* string) {

    int tamanho = strlen(string);
    int meio = tamanho / 2;
    int i, j;

    //Verificação se o tamanho da String Concatenada é Impar
    if (tamanho % 2 != 0) {
        return false; // Não está na forma XY
    }

    // Verificar se a segunda metade é o reverso da primeira metade
    for (i = 0, j = strlen(string) - 1; i < meio; i++, j--) {
        if (string[i] != string[j]) {
            return false; // Não está na forma XY
        }
    }
    
    return true; // Está na forma XY
}

//Função Principal
int main() {
    char x[100];
    char y[100];
    char string[200];

    printf("Digite o(s) Caractere(s) de x: ");
    scanf("%s", x);

    printf("Digite o(s) Caractere(s) de y: ");
    scanf("%s", y);

    /* A Função copia os caracteres da string de origem para a string de
    destino até encontrar o caractere nulo. */
    strcpy(string, x);

    // A Função irá fazer a concatenação das duas strings.
    strcat(string, y);

    if (verifica_forma_xy(string)) {
        printf("A string '%s' esta na forma XY.\n", string);
    }
    else {
        printf("A string '%s' nao esta na forma XY.\n", string);
    }

    return 0;
}
