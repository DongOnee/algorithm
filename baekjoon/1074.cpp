/**
 * 18.12.20. 목요일
 */
#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;

int n, x, y;

int calc(int _x, int _y, int cnt, int po) {
    if (po==0) return cnt;
    if (x>=_x+pow(2, po-1))
    {
        _x += pow(2, po-1);
        cnt += 2*pow(4, po-1);
    }
    if (y>=_y+pow(2, po-1))
    {
        _y += pow(2, po-1);
        cnt += pow(4, po-1);
    }
    return calc(_x, _y, cnt, po-1);
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &n, &x, &y);
    int i=0, _max=max(x, y);
    while (pow(2, ++i)<=_max);
    printf("%d\n", calc(0,0,0,i));

    return 0;
}