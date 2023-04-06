#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int mdc(int a, int b) {
  if (b == 0) {
    return a;
  }
  return mdc(b, a % b);
}

int inverso(int a, int m, int x, int y) {
  if (m == 0) {
    return a == 1 ? x : 0;
  }
  int d = mdc(m, a % m);
  int x1 = x, y1 = y, x2 = 1, y2 = 0;
  if (a % m != 0) {
    x2 = x - (a / m) * x1;
    y2 = y - (a / m) * y1;
  }
  return inverso(m, a % m, x2, y2);
}

int congruencia_chinesa(int n, int *a, int *b, int *x) {
  int i, j;
  int M[n], Mi[n], y[n];
  int Mprod = 1;
  for (i = 0; i < n; i++) {
    Mprod *= a[i];
  }
  for (i = 0; i < n; i++) {
    M[i] = Mprod / a[i];
    Mi[i] = inverso(M[i], a[i], 1, 0);
    y[i] = b[i] * M[i] * Mi[i];
    for (j = 0; j < i; j++) {
      y[i] += y[j] * (M[j] * Mi[j]) % Mprod;
      if (y[i] >= Mprod) {
        y[i] -= Mprod;
      }
    }
  }
  *x = y[n - 1];
  return 1; // solução encontrada
}

int main() {
    setlocale(LC_ALL, "Portuguese");
  int n, i;
  printf("Digite o número de congruências:\n");
  scanf("%d", &n);
  int a[n], b[n];
  printf("Digite os valores de a e b para cada congruência:\n");
  for (i = 0; i < n; i++) {
    scanf("%d %d", &a[i], &b[i]);
  }
  int x;
  if (congruencia_chinesa(n, a, b, &x)) {
    printf("A solução é x ≡ %d (mod ", x);
    for (i = 0; i < n; i++) {
      printf("%d", a[i]);
      if (i < n - 1) {
        printf(", ");
      }
    }
    printf(").\n");
  } else {
    printf("Não existe solução única.\n");
  }
  return 0;
}
