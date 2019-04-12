/**
 * 19.4.10. 13:46~14:57
 */
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

queue<pair<int, int>> qu;
bool chains[4][8];

void turn(int n, int dir) // 1~4, 1: 시계방향, -1 : 반시계 방향
{
    bool tmp = chains[n][0];
    for (int i=0; i<7; i++) chains[n][(8+i*dir)%8] = chains[n][(8+dir+i*dir)%8];
    chains[n][(8-dir)%8] = tmp;
}
// 0 1 2 3 4 5 6 7 : 반시계 방향 -1
// 0    (8+1) % 8   ()
// 0 7 6 5 4 3 2 1 : 시계 뱡향 1

void pre_turn(int a, int b)
{
    a-=1;
    qu.push({a, b});
    for (int i=a-1, dir=-b; 0<=i; i--)
    {
        if (chains[i][2] != chains[i+1][6]) qu.push({i, dir});
        else break;
        dir*=-1;
    }
    for (int i=a+1, dir=-b; i<4; i++)
    {
        if (chains[i][6] != chains[i-1][2]) qu.push({i, dir});
        else break;
        dir*=-1;
    }
    while(!qu.empty())
    {
        pair<int, int> f = qu.front();
        qu.pop();
        turn(f.first, f.second);
    }

    // for (int i=0; i<4; i++)
    // {
    //     printf("\n");
    //     for (int j=0; j<8; j++) printf("%d", chains[i][j]);
    // }
    // printf("\n");
}

int main(int argc, char const *argv[])
{
    for (int i=0, a; i<4; i++)
    {
        scanf("%d", &a);
        for (int j=7; 0<=j; j--)
        {
            chains[i][j] = a%10;
            a /= 10;
        }
    }

    int cmd_;
    scanf("%d", &cmd_);
    while (cmd_--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        pre_turn(a, -b);
    }

    int sol = 0;
    for (int i=0; i<4; i++) sol += chains[i][0]<<i;
    printf("%d\n", sol);


    return 0;
}







/*
    0 
  7   1
6       2
 5     3
    4
*/
