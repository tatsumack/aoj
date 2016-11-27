// SEE: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_B

#include<algorithm>
#include<stdio.h>

#define MAX 500000

int n;
int A[MAX + 1];

void maxHeapfy(int A[], int root) {
    int left = root * 2;
    int right = root * 2 + 1;

    int max = root;
    if (left <= n && A[max] < A[left]) {
        max = left;
    }
    if (right <= n && A[max] < A[right]) {
        max = right;
    }

    if (max != root) {
        std::swap(A[root], A[max]);
        maxHeapfy(A, max);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &A[i]);
    }
    for (int i = n/2; i > 0; --i) maxHeapfy(A, i);
    for (int i = 1; i <= n; ++i) printf(" %d", A[i]);
    printf("\n");

    return 0;
}
