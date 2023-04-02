#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int inverso_recursao(int a, int b, int x, int y)
{
    if (b == 0) {
        return x;
    }
    int q = a / b;
    int r = a % b;
    return inverso_recursao (b, r, y, x - q*y);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int a, b;
    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);
    int inverso = inverso_recursao(a, b, 1, 0);
    if (inverso < 0) {
        inverso += b;
    }
    printf("O inverso de %d mod %d é %d\n", a, b, inverso);
    return 0;
}
