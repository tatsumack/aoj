//SEE: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_B

#include <stdio.h>
#include <algorithm>

void trace(int a[], int size) {
    for (int i = 0; i < size; ++i) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");
}

void SelectionSort(int A[], int N) {
    int count  = 0;
    for (int i = 0; i < N; ++i) {
        int min = i;
        for (int j = i; j < N; ++j) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        if (i != min) {
            std::swap(A[i], A[min]);
            count++;
        }
    }

    trace(A, N);
    printf("%d\n", count);
}

int main() {
    int N;
    int A[100];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    SelectionSort(A, N);
    return 0;
}

