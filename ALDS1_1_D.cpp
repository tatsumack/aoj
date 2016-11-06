//SEE: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_D

#include <stdio.h>
#include <algorithm>

int GetMaxProfit(int R[], int N) {
    int max, min;
    min = R[0];
    max = R[1] - R[0];
    for (int i = 1; i < N; ++i) {
        max = std::max(R[i] - min, max);
        min = std::min(R[i], min);
    }
    return max;
}

int main() {
    int N;
    int R[200000];

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &R[i]);
    }

    int result = GetMaxProfit(R, N);
    printf("%d\n", result);

    return 0;
}

