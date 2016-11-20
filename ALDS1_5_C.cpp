// SEE: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_C

#include <stdio.h>
#include <math.h>

struct Point {
    double x,y;
};

void makeKochCurve (Point * p1, Point * p2, int n, int maxDepth) {
    if (n > maxDepth) return;
    Point s = { p1->x + (p2->x - p1->x) / 3, p1->y + (p2->y - p1->y) / 3};
    Point t = { p1->x + (p2->x - p1->x) * 2 / 3, p1->y + (p2->y - p1->y) * 2 / 3};

    double th = M_PI * 60 / 180;
    Point u = { (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x , (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) +s.y};

    makeKochCurve(p1, &s, n + 1, maxDepth);
    printf("%.8f %.8f\n", s.x, s.y);
    makeKochCurve(&s, &u, n + 1, maxDepth);
    printf("%.8f %.8f\n", u.x, u.y);
    makeKochCurve(&u, &t, n + 1, maxDepth);
    printf("%.8f %.8f\n", t.x, t.y);
    makeKochCurve(&t, p2, n + 1, maxDepth);

}

int main() {
    Point s = {0,0};
    Point e = {100,0};

    int n;
    scanf("%d", &n);

    printf("%.8f %.8f\n", s.x, s.y);
    makeKochCurve(&s, &e, 1, n);
    printf("%.8f %.8f\n", e.x, e.y);

    return 0;
}
