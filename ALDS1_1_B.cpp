//SEE: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B

#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) { return a; }
    return gcd(b, a % b);
}

int main() {
    int a,b;

    scanf("%d %d", &a, &b);
    int result = gcd(a, b);

    printf("%d\n", result);

    return 0;
}

