// SEE http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B
#include<stdio.h>

bool FindByBinarySearch(int x, int A[], int left, int right) {
    int mid = (left + right) / 2;
    if (x == A[mid]) return true;
    if (x >= A[left] && x < A[mid]) return FindByBinarySearch(x, A, left, mid);
    if (x > A[mid] && x <= A[right]) return FindByBinarySearch(x, A, mid+1, right);

    return false;
}

int main() {
    int n, q, S[100000], T[50000];
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
        if (FindByBinarySearch(T[i], S, 0, n-1)) {
            ++C;
        }
    }

    printf("%d\n", C);

    return 0;
}
