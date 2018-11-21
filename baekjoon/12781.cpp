/**
 * 18.11.16. 금요일
 * 이전에 실패한 문제를 다시 보았다.
 * http://jason9319.tistory.com/358 블로그를 참고하여 CCW 를 이용해보로독 한다
 */

#include <cstdio>
#include <utility>
#include <iostream>
using namespace std;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int op = a.first*b.second + b.first*c.second + c.first*a.second;
    op -= (a.second*b.first + b.second*c.first + c.second*a.first);
    if (op > 0)return 1;
    else if (op == 0)return 0;
    else return -1;
}

int isIntersect(pair<pair<int, int>, pair<int, int>> x, pair<pair<int, int>, pair<int, int>> y) {
    pair<int, int> a = x.first;
    pair<int, int> b = x.second;
    pair<int, int> c = y.first;
    pair<int, int> d = y.second;
    int ab = ccw(a, b, c)*ccw(a, b, d);
    int cd = ccw(c, d, a)*ccw(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b)swap(a, b);
        if (c > d)swap(c, d);
        return c <= b&&a <= d;
    }
    return ab < 0 && cd < 0;
}

int main(int argc, char const *argv[])
{
    pair<int, int> point[4];
    for (int i=0; i<4; i++)
    {
        int a, b;
        cin >> a >> b;
        point[i] = make_pair(a, b);
    }
    if (isIntersect(make_pair(point[0], point[1]), make_pair(point[2], point[3]))) printf("1\n");
    else printf("0\n");
    return 0;
}
