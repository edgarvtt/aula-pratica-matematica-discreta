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

int inverso(int a, int m) {
  int m0 = m, t, q;
  int x0 = 0, x1 = 1;
  if (m == 1) {
    return 0;
  }
  while (a > 1) {
    q = a / m;
    t = m;
    m = a % m;
    a = t;
    t = x0;
    x0 = x1 - q * x0;
    x1 = t;
  }
  if (x1 < 0) {
    x1 += m0;
  }
  return x1;
}

int congruencia_chinesa(int a1, int b1, int a2, int b2, int a3, int b3, int *x) {
  int m1 = a1, m2 = a2, m3 = a3;
  int M1 = m2 * m3, M2 = m1 * m3, M3 = m1 * m2;
  if (mdc(m1, m2) != 1 || mdc(m1, m3) != 1 || mdc(m2, m3) != 1) {
    return 0;
  }
  int y1 = inverso(M1, m1), y2 = inverso(M2, m2), y3 = inverso(M3, m3);
  *x = (b1 * M1 * y1 + b2 * M2 * y2 + b3 * M3 * y3) % (m1 * m2 * m3);
  if (*x < 0) {
    *x += m1 * m2 * m3;
  }
  return 1;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
  int a1, b1, a2, b2, a3, b3;
  printf("Digite os valores de a1, b1, a2, b2, a3 e b3:\n");
  scanf("%d %d %d %d %d %d", &a1, &b1, &a2, &b2, &a3, &b3);
  int x;
  if (congruencia_chinesa(a1, b1, a2, b2, a3, b3, &x)) {
    printf("A solução é x ≡ %d (mod %d).\n", x, a1 * a2 * a3);
  } else {
    printf("Não existe solução única.\n");
  }
  return 0;
}
