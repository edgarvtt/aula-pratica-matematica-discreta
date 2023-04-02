#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>


bool primo_recursivo(unsigned long long n, unsigned long long i) {

    if (i > n/2) {
        return true;
    }

    if (n % i == 0) {
        return false;
    }

    return primo_recursivo(n, i+1);
}


void lista_primos_recursivo(unsigned long long n, unsigned long long i) {

    if (i > n) {
        return;
    }

    if (primo_recursivo(i, 2)) {
        printf("%llu ", i);
    }

    lista_primos_recursivo(n, i+1);
}

int main() {

    setlocale(LC_ALL, "Portuguese");
    unsigned long long n;
    printf("Digite o maior número que deseja testar: ");
    scanf("%llu", &n);

    printf("Números primos: ");
    lista_primos_recursivo(n, 2);
    printf("\n");

    return 0;
}
