// SEE: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_B

#include<stdio.h>
#include<algorithm>

#define MAX 1000
#define INFINITY 2000000000

int A[MAX];
int m[MAX][MAX];
int n;

void minimumCount() {
    for (int i = 0; i < n; ++i) m[i][i] = 0;

    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            m[i][j] = INFINITY;
            for (int k = i; k < j; ++k) {
                m[i][j] = std::min(m[i][j], m[i][k] + m[k+1][j] + A[i-1] * A[k] * A[j]);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &A[i - 1], &A[i]);
    }
    minimumCount();
    printf("%d\n", m[1][n]);
}
