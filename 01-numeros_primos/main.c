#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int e_primo(x,divisor) {

    int x,divisor;

    if (divisor == 1) {
        return 1;
    }
    if (x % divisor == 0) {
        return 0;
    }
    return e_primo(x, divisor - 1);
}

int main() {

    setlocale(LC_ALL, "Portuguese"); /*adicionar linguagem pt-br */

    int num;
    printf("Digite um n�mero inteiro: ");
    scanf("%d", &num);
    if (num < 2) {
        printf("%d n�o � primo.\n", num);
    }
    else if (e_primo(num, num - 1)) {
        printf("%d � primo.\n", num);
    }
    else {
        printf("%d n�o � primo.\n", num);
    }
    return 0;
}
