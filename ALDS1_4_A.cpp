// SEE http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_A

#include<stdio.h>

int main() {
    int n, q, S[10000], T[500];
    int C = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d", &T[i]);
    }

    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < n; ++j) {
            if (T[i] == S[j]) {
                ++C;
                break;
            }
        }
    }

    printf("%d\n", C);

    return 0;
}
