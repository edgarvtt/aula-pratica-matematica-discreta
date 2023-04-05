#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int mdc(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return mdc(b, a % b);
    }
}

int main() {

    setlocale(LC_ALL, "Portuguese");
    int num1, num2, resultado;
    printf("Digite dois números: ");
    scanf("%d %d", &num1, &num2);

    resultado = mdc(num1, num2);

    printf("O MDC de %d e %d é %d", num1, num2, resultado);

    return 0;
}
