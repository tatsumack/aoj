// SEE:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_C

#include<stdio.h>
#include<stdlib.h>

struct Node {
    Node* parent;
    Node* left;
    Node* right;
    int key;
};

Node * NIL = NULL;
Node * ROOT = NIL;

void Inorder (Node* n) {
    if (n == NIL) return;
    Inorder(n->left);
    printf(" %d", n->key);
    Inorder(n->right);
}
void Preorder (Node* n) {
    if (n == NIL) return;
    printf(" %d", n->key);
    Preorder(n->left);
    Preorder(n->right);
}

void insert (Node* n) {
    Node * r = ROOT;
    Node * t;
    while (r != NIL) {
        t = r;
        if (n->key < r->key) {
            r = r->left;
        }
        else {
            r = r->right;
        }
    }
    n->parent = t;

    if (ROOT == NIL) {
        ROOT = n;
    }
    else if(n->key < t->key) {
        t->left = n;
    }
    else {
        t->right = n;
    }
}

Node* find(int key) {
    Node* t = ROOT;
    while (t != NIL) {
        if ( t->key == key) {
            break;
        }
        else if (key < t->key) {
            t = t->left;
        }
        else {
            t = t->right;
        }
    }
    return t;
}
Node* getMinimum(Node* n) {
    while (n->left != NIL) {
        n = n->left;
    }
    return n;
}

Node* getSuccessor(Node* n) {
    if (n->right != NIL) return getMinimum(n->right);

    Node* p = n->parent;
    while (p != NIL && p->right == n) {
        n = p;
        p = p->parent;
    }

    return n;
}

void deleteFromParentNode (Node * n, Node * t) {
    if (n->parent == NIL) {
        ROOT = t;
        return;
    }
    if (n->parent->left == n) {
        n->parent->left = t;
    }
    else if (n->parent->right== n) {
        n->parent->right = t;
    }
}

void deleteNode (Node * n) {
    if (n == NIL) return;

    if (n->left == NIL && n->right == NIL) {
        deleteFromParentNode(n, NIL);
    }
    else if (n->left != NIL && n->right != NIL) {
        Node* t = getSuccessor(n);
        n->key = t->key;
        return deleteNode(t);
    }
    else if (n->left != NIL) {
        deleteFromParentNode(n, n->left);
        n->left->parent = n->parent;
    }
    else if (n->right != NIL) {
        deleteFromParentNode(n, n->right);
        n->right->parent = n->parent;
    }
    free(n);
    n = NULL;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char s[100];
        scanf("%s", s);
        if (s[0] == 'i') {
            int key;
            scanf("%d", &key);
            Node* n = (Node *) malloc(sizeof(Node));
            n->key = key;
            n->parent = n->left = n->right = NIL;
            insert(n);
        }
        else if (s[0] == 'p') {
            Inorder(ROOT);
            printf("\n");
            Preorder(ROOT);
            printf("\n");
        }
        else if (s[0] == 'f') {
            int key;
            scanf("%d", &key);
            if (find(key) != NIL) {
                printf("yes\n");
            }
            else {
                printf("no\n");
            }
        }
        else if (s[0] == 'd') {
            int key;
            scanf("%d", &key);
            deleteNode(find(key));
        }
    }
}

