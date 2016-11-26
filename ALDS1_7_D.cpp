// SEE: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_D
#include<stdio.h>

#define MAX 40

int n, pos, k;
int PRE[MAX];
int IN[MAX];
int POS[MAX];

void Postorder (int l, int r) {
    if (l >= r) return;
    int root = PRE[pos++];
    int target = 0;
    for (int i = 0; i < n; ++i) {
        if (IN[i] == root) {
            target = i;
            break;
        }
    }

    Postorder(l, target);
    Postorder(target + 1, r);
    POS[k++] = root;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &PRE[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &IN[i]);
    }

    k = pos = 0;
    Postorder(0, n);

    for (int i = 0; i < n; ++i) {
        if (i > 0) printf(" ");
        printf("%d", POS[i]);
    }
    printf("\n");
}

