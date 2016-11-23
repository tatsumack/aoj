// SEE: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_B
#include<stdio.h>
#include<string>
#include<algorithm>

#define MAX 100000
#define NIL -1


struct Node {
    public:
        int id;
        int parent;
        int left;
        int right;
        int height;
        int depth;
        int sibling;
        int degree;
};

Node N[MAX];

void setDepth(Node& n, int depth) {
    Node* cur = &n;
    cur->depth = depth;
    if (cur->right != NIL) setDepth(N[cur->right], depth + 1);
    if (cur->left != NIL) setDepth(N[cur->left], depth + 1);
}

int setHeight(Node& n) {

    int hl = 0, hr = 0;
    if (n.left != NIL) {
        hl = setHeight(N[n.left]) + 1;
    }
    if (n.right != NIL) {
        hr = setHeight(N[n.right]) + 1;
    }

    return n.height = std::max(hl, hr);
}


void print(Node n, int id) {
    std::string type;
    if (n.parent == NIL) {
        type = "root";
    }
    else if (n.left == NIL && n.right == NIL) {
        type = "leaf";
    }
    else {
        type = "internal node";
    }

    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", id, n.parent, n.sibling, n.degree, n.depth, n.height, type.c_str());
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        N[i].id = i;
        N[i].parent = NIL;
        N[i].left = NIL;
        N[i].right = NIL;
        N[i].height = NIL;
        N[i].depth = NIL;
        N[i].sibling = NIL;
        N[i].degree = NIL;
    }

    for (int i = 0; i < n; ++i) {
        int id, lc, rc;
        scanf("%d %d %d", &id, &lc ,&rc);
        N[id].left = lc;
        N[id].right = rc;

        int deg = 0;
        if (lc != NIL) {
            ++deg;
            N[lc].parent = id;
            if (rc != NIL) N[lc].sibling = rc;
        }
        if (rc != NIL) {
            ++deg;
            N[rc].parent = id;
            if (lc != NIL) N[rc].sibling = lc;
        }

        N[id].degree = deg;
    }

    int root = NIL;
    for (int i = 0; i < n; ++i) {
        if (N[i].parent == NIL) {
            root = i;
            break;
        }
    }

    setDepth(N[root], 0);
    setHeight(N[root]);

    for (int i = 0; i < n; ++i) print(N[i], i);

}
