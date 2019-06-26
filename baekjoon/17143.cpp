/**
 * 19.06.09 00:47 ~ 4:42
 */
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

struct shark
{
    int speed, direction, size;
};


int r, c, m, ans;
shark map[101][101];
shark cpmap[101][101];

int dir[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

bool chk(int row, int col) { return 0<=row&&row<r&&0<=col&&col<c; }
bool chk(pair<int, int> position) { return 0<=position.first&&position.first<r&&0<=position.second&&position.second<c; }

void catch_shark(int col)
{
    for (int row=0; row<r; row++)
    {
        if (map[row][col].size != 0)
        {
            ans += map[row][col].size;
            map[row][col] = {0, 0, 0};
            return ;
        }
    }
}

void move_sharks()
{
    for (int row=0; row<r; row++)
    {
        for (int col=0; col<c; col++)
        {
            if (map[row][col].size == 0) continue;
            shark tmp = map[row][col];
            pair<int, int> position = {row, col};
            int cnt = tmp.speed;
            map[row][col] = {0, 0, 0};

            pair<int, int> nex = { row + cnt*dir[tmp.direction][0], col + cnt*dir[tmp.direction][1] };
            while (!chk(nex))
            {
                if (nex.first < 0) nex.first *= -1;
                else if (nex.second < 0) nex.second *= -1;
                else if (nex.first >= r)
                {
                    nex.first -= (r-1) *2;
                    nex.first *= -1;
                }
                else if (nex.second >= c)
                {
                    nex.second -= (c-1) *2;
                    nex.second *= -1;
                }
                tmp.direction ^= 1;
            }

            if (cpmap[nex.first][nex.second].size < tmp.size) cpmap[nex.first][nex.second] = tmp;
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &r, &c, &m);
    for (int k=0; k<m; k++)
    {
        int a, b, s, d, z; scanf("%d%d%d%d%d", &a, &b, &s, &d, &z);
        map[a-1][b-1] = {s, d-1, z};
    }

    for (int k=0; k<c; k++)
    {
        catch_shark(k);
        move_sharks();
        swap(map, cpmap);
    }

    printf("%d\n", ans);
    return 0;
}
