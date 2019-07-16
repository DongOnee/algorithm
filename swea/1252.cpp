/**
 * 2019.07.11. 08:11 ~
 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXS 101
#define MAXN 10001

typedef struct optimal_return
{
    int row, col, cnt;
} opt_ret;

int map[MAXS][MAXS], cnt, ans[MAXN][3];
int costs[4] = {0, 2, 4, 7};
int s, n;
vector<opt_ret> vt;

bool chk(int row, int col) { return 0<row&&row<=s&&0<col&&col<=s; }

/**
 * row, col : 시작 좌표
 * size : 탐색하고자 하는 정사각형 너비
 * return : 정사각형 안에 벗겨진곳 갯수
 */
int calc_damaged(int row, int col, int size)
{
    int cnt=0;
    for (int i=0; i<size; i++)
        for (int j=0; j<size; j++)
            if (map[i+row][j+col] == 1) cnt++;

    return cnt;
}

/**
 * row, col : 시작 좌표
 * size : 탐색하고자 하는 정사각형 너비
 * panel_size  : 도금판 너비
 * return : panel_size 인 도금판을 이용하여 덮었을때 가장 많이 복구되는 곳?
 */
opt_ret optimize(int row, int col, int size, int panel_size)
{
    int max_r = -1, max_c = -1, max_cnt = 0;
    for (int i=0; i<size-panel_size+1; i++)
        for (int j=0; j<size-panel_size+1; j++)
        {
            if (!chk(i+row+panel_size-1, j+col+panel_size-1)) continue;
            int cnt = calc_damaged(i+row, j+col, panel_size);
            if (max_cnt < cnt)
            {
                max_cnt = cnt;
                max_r = i+row;
                max_c = j+col;
            }
        }
    
    return { max_r, max_c, max_cnt };
}

void set_values(int row, int col, int panel_size, int before, int after)
{
    for (int i=0; i<panel_size; i++)
        for (int j=0; j<panel_size; j++)
            if (map[i+row][j+col] == before) map[i+row][j+col] = after;
}

int solve(int row, int col, int panel_size, bool isFirst)
{
    int sum_cost = 0;
    while (panel_size > 1)
    {
        // 전체 map 에서 panel_size 를 이용하였을때 가장 많이 복구되는 곳을 찾는다.
        opt_ret optimals1 = optimize(row, col, s, panel_size);
        if (optimals1.cnt == 0) break; // 없으면 끝
        int cost1 = costs[panel_size]; // 가격.

        // 처음 실행되는 것이고, panel_size 가 3이면?
        if (isFirst && panel_size == 3)
        {
            int cost_1 = solve(row, col, 3, false); // optimals1 을 3으로 하고..
            int cost_2 = solve(row, col, 2, false); // optimals1 을 2로 하고..
            if (cost_2 < cost_1)
            {
                panel_size = 2;
                continue;
            }
        }

        int cost2 = 0;
        if (panel_size == 3)
        {
            // 2 로 한번 해보자.
            opt_ret optimals2 = optimize(optimals1.row, optimals1.col, 3, 2);
            cost2 = costs[2];
            set_values(optimals2.row, optimals2.col, 2, 1, 2);
            
            opt_ret optimals3;
            do 
            {
                optimals3 = optimize(optimals1.row, optimals1.col, 3, 2);
                if (optimals3.cnt > 1)
                {
                    cost2 += costs[2];
                    set_values(optimals3.row, optimals3.col, 2, 1, 2);
                }
            } while (optimals3.cnt > 1);
        }

        cost2 += costs[1] * calc_damaged(optimals1.row, optimals1.col, panel_size);
        set_values(optimals1.row, optimals1.col, panel_size, 2, 1);

        if (cost1 <= cost2)
        {
            set_values(optimals1.row, optimals1.col, panel_size, 1, isFirst ? 3: 4);
            sum_cost += cost1;
            if (isFirst) vt.push_back({optimals1.row, optimals1.col, panel_size});
        }
        else
            panel_size--;
    }
}

int main(int argc, char const *argv[])
{
    int T; scanf("%d", &T);
    for (int tc=1; tc<=T; tc++)
    {
        scanf("%d%d", &s, &n);
        memset(map, 0, sizeof(map));
        for (int i=0, r, c; i<n; i++)
        {
            scanf("%d%d", &r, &c);
            map[r][c] = 1;
        }

        cnt = 0;
        solve(0, 0, 3, true);
    }
    return 0;
}
