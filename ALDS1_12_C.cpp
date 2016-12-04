// SEE: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A

#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

#define MAX 10000
#define INFINITY 300000

int n;
int color[MAX], d[MAX];

vector< pair<int, int> > adj[MAX];

enum Color {
    WHITE,
    GRAY,
    BLACK
};

void dijkstra() {
    priority_queue<pair<int, int> >PQ;
    for (int i = 0; i < n; ++i) {
        color[i] = WHITE;
        d[i] = INFINITY;
    }
    d[0] = 0;
    PQ.push(make_pair(0,0));

    while (!PQ.empty()) {
        pair<int, int> p = PQ.top();
        PQ.pop();
        int target = p.second;

        color[target] = BLACK;
        if (d[target] < p.first * -1) continue;

        for (int j = 0; j < adj[target].size(); ++j) {
            int v = adj[target][j].first;
            if (color[v] != BLACK) {
                if(adj[target][j].second + d[target] < d[v]) {
                    d[v] = d[target] + adj[target][j].second;
                    color[v] = GRAY;
                    PQ.push(make_pair(d[v] * -1, v));
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", i, d[i]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int id, k;
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; ++j) {
            int t, c;
            scanf("%d %d", &t, &c);
            adj[id].push_back(make_pair(t,c));
        }
    }
    dijkstra();
    return 0;
}

