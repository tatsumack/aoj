// SEE: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_D
#include<stdio.h>
#include<algorithm>

#define MAX 1000
#define WMAX 10000

int main() {
    int n;
    int A[MAX], B[MAX], V[MAX], T[WMAX+1];

    scanf("%d", &n);
    int min = WMAX;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        B[i] = A[i];
        V[i] = false;
        min = std::min(min, A[i]);
    }
    std::sort(B, B+n);
    for (int i = 0; i < n; ++i) T[B[i]] = i;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (V[i]) continue;

        int cur = i;
        int num = 0;
        int sum = 0;
        int m = WMAX;
        while (true) {
            V[cur] = true;
            num++;
            sum += A[cur];
            m = std::min(m, A[cur]);
            cur = T[A[cur]];
            if (V[cur]) break;
        }
        ans += std::min(sum + (num - 2) * m, sum + (num - 2) * m + (m + min) * 2 - (m - min) * (num - 1));
    }
    printf("%d\n", ans);

    return 0;
}

