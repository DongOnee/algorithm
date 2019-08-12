#include <cstdio>
#include <utility>
#include <queue>
#include <math.h>
using namespace std;

queue<pair<pair<int, int>, int>> qu;

int r, c, t;
int map[51][51];
int sub[51][51];
pair<int, int> cleaner[2];
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

bool chk(int row, int col) { return 0<=row&&row<r&&0<=col&&col<c; }

void extend()
{
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            if (map[i][j] == -1) continue;
            int slice = map[i][j]/5;
            for (int k=0; k<4; k++)
            {
                int new_i = i+dir[k][0];
                int new_j = j+dir[k][1];
                if (!chk(new_i, new_j)) continue;
                else if (map[new_i][new_j] == -1) continue;
                sub[new_i][new_j] += slice;
                map[i][j] -= slice;
            }
        }
    }

    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            map[i][j] += sub[i][j];
            sub[i][j] = 0;
        }
    }
}

void cleaner_oper()
{
    int cur_r = cleaner[0].first;
    int cur_c = cleaner[0].second;
    int cur = 0;
    for (int k=0; k<4; k++)
    {
        while(chk(cur_r-dir[k][0], cur_c+dir[k][1]))
        {
            int next_r = cur_r - dir[k][0];
            int next_c = cur_c + dir[k][1];
            if (map[next_r][next_c] == -1) break;
            int next_ = map[next_r][next_c];
            map[next_r][next_c] = cur;
            cur = next_;
            cur_r = next_r;
            cur_c = next_c;
        }
    }

    cur_r = cleaner[1].first;
    cur_c = cleaner[1].second;
    cur = 0;
    for (int k=0; k<4; k++)
    {
        while(chk(cur_r+dir[k][0], cur_c+dir[k][1]))
        {
            int next_r = cur_r + dir[k][0];
            int next_c = cur_c + dir[k][1];
            if (map[next_r][next_c] == -1) break;
            int next_ = map[next_r][next_c];
            map[next_r][next_c] = cur;
            cur = next_;
            cur_r = next_r;
            cur_c = next_c;
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &r, &c, &t);
    int cleaner_index=0;
    for (int i=0; i<r; i++) for (int j=0; j<c; j++)
    {
        scanf("%d", map[i]+j);
        if (map[i][j] == -1) cleaner[cleaner_index++] = {i, j};
    }

    while (t--)
    {
        extend();
        cleaner_oper();
    }

    int ret = 2;
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) ret += map[i][j];

    printf("%d\n", ret);

    return 0;
}
