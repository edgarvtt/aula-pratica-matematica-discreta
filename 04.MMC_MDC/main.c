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

int mmc(int a, int b) {
    int m = mdc(a, b);
    return (a / m) * b;
}

int main() {

    setlocale(LC_ALL, "Portuguese");
    int a, b;
    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &a, &b);
    printf("O MDC de %d e %d e: %d\n", a, b, mdc(a, b));
    printf("O MMC de %d e %d e: %d\n", a, b, mmc(a, b));
    return 0;
}

