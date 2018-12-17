/**
 * 2018.12.17. 월요일
 * 다시 풀어보자
 */

#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
char map[51][51];

int BorW(int row, int col, char borw1, char borw2) {
    int ret = 0;
    for (int i=0; i<8; i++) for (int j=0; j<8; j++)
    {
        char comp;
        if ((i+j)%2==0) comp = borw1;
        else if ((i+j)%2==1) comp = borw2;
        if (map[row+i][col+j]!=comp) ret++;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    int sol = 65;
    scanf("%d %d", &N, &M);
    for (int row=0; row<N; row++) scanf("%s", map[row]);

    for (int row=0; row<N-7; row++) for (int col=0; col<M-7; col++)
        sol = min(sol, min(BorW(row, col, 'W', 'B'), BorW(row, col, 'B', 'W')));
    printf("%d\n", sol);
    return 0;
}
