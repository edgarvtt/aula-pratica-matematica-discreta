#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int mdc_ec(int a, int b, int *s, int *t) {

    if (b == 0) {
        *s = 1;
        *t = 0;
        return a;
    }


    int mdc = mdc_ec(b, a % b, s, t);

    int tmp = *s;
    *s = *t;
    *t = tmp - (a / b) * (*t);

    return mdc;
}

int main() {

    setlocale(LC_ALL, "Portuguese");
    int a, b, s, t;

    printf("Digite dois números inteiros: ");
    scanf("%d %d", &a, &b);

    int mdc = mdc_ec(a, b, &s, &t);

    printf("mdc(%d, %d) = %d\n", a, b, mdc);
    printf("s = %d || t = %d\n", s, t);

    return 0;
}
