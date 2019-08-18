/*
 * 두 선분이 교차하려면 ... http://stack07142.tistory.com/110 참조
 * ccw..? http://jason9319.tistory.com/358 참조
 */

#include <stdio.h>

typedef struct point
{
    int x;
    int y;
} point;

int ccw(point a, point b, point c)
{
    // 선분 ab, 점 c
    int op = (a.x*b.y-b.x*a.y)+(b.x*c.y-c.x*b.y)+(c.x*a.y-a.x*c.y);
    if (op>0) return 1;
    else if (op == 0) return 0;
    return -1;
}

int main(int argc, char const *argv[])
{
    // data
    point A, B, C, D;
    scanf("%d %d %d %d %d %d %d %d", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y, &D.x, &D.y);

    int ab = ccw(A, B, C) * ccw(A, B, D);
    int cd = ccw(C, D, A) * ccw(C, D, B);

    return 0;
}
