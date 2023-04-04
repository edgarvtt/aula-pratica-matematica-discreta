#include <stdio.h>
#include <stdlib.h>

void decompor_Fatores_Primos(int num, int divisor) {
    if (num == 1) {
        return;
    }
    else if (num % divisor == 0) {
        printf("%d ", divisor);
        decompor_Fatores_Primos(num/divisor, divisor);
    }
    else {
        decompor_Fatores_Primos(num, divisor+1);
    }
}

int main() {
    int num;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &num);

    printf("Os fatores primos de %d sao: ", num);
    decompor_Fatores_Primos(num, 2);

    return 0;
}
