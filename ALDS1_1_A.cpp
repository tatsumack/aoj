//SEE: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_A

#include <stdio.h>

void trace(int a[], int size) {
    for (int i = 0; i < size; ++i) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");
}

void InsertionSort(int A[], int N) {
    int j = 0;
    for (int i = 1; i < N; ++i) {
        trace(A, N);
        int key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            --j;
        }
        A[j+1] = key;
    }
    trace(A, N);
}

int main() {
    int N;
    int A[100];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    InsertionSort(A, N);
    return 0;
}

