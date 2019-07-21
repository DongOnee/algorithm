#include <cstdio>
#include <vector>
using namespace std;

#define MAXN 101
#define MAXM 10001

typedef pair<pair<int, int>, int> ppiii;

int costs[4] = {0, 2, 4, 7};
int map[MAXN][MAXN];
int n, m, ans;

vector<ppiii> vt;

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<n; }

int count_damaged(int row, int col, int size)
{
    int cnt = 0;
    for (int i=0; i<size; i++)
        for (int j=0; j<size; j++)
            if (chk(i+row, j+col))
                if (map[i+row][j+col] != 0) cnt++;
    
    return cnt;
}

void convert_value(int row, int col, int size, int before_value, int after_value)
{
    for (int i=0; i<size; i++)
        for (int j=0; j<size; j++)
            if (chk(i+row, j+col))
                if (map[i+row][j+col] == before_value) map[i+row][j+col] = after_value;
}

ppiii findOptimal(int row, int col, int size, int panel_size)
{
    int ret_r = -1, ret_c = -1, ret_cnt = 0;
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            if (!chk(i+row, j+col)) continue;
            int cnt = count_damaged(i+row, j+col, panel_size);
            if (ret_cnt < cnt)
            {
                ret_r = i+row, ret_c = j+col;
                ret_cnt = cnt;
            }
        }
    }

    return {{ret_r, ret_c}, ret_cnt};
}

int solve(int row, int col, int size, int panel_size, bool isFirst)
{
    int sum_cost = 0;
    while (panel_size > 1)
    {
        ppiii finded_optimal1 = findOptimal(row, col, size, panel_size);
        if (finded_optimal1.second == 0)
        {
            panel_size--;
            continue;
        }
        int cost1 = costs[panel_size];

        if (panel_size == 3 && isFirst)
        {
            int cost2 = solve(row, col, size, 2, false);
            int cost3 = solve(row, col, size, 3, false);
            if (cost2 < cost3)
            {
                panel_size--;
                continue;
            }
        }

        int cost2 = 0, remain_damaged = finded_optimal1.second;
        if (panel_size == 3 && remain_damaged < 6) // 2x2 판넬로 도금하는 경우를 찾자. 6이상이면 무적건 3x3 으로 쓰는게 이득
        {
            ppiii finded_optimal2 = findOptimal(finded_optimal1.first.first, finded_optimal1.first.second, 3, 2);

            cost2 += (remain_damaged * costs[1]);
            for (int i=0; i<3; i++) for (int j=0; j<3; j++) if (map[i+finded_optimal1.first.first][j+finded_optimal1.first.second] == 1)
            {
                vt.push_back({{i+finded_optimal1.first.first, j+finded_optimal1.first.second}, 1});
                map[i+finded_optimal1.first.first][j+finded_optimal1.first.second] = (isFirst? 3: 2);
                remain_damaged--;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int T; scanf("%d", &T);
    for (int tc=1; tc<=T; tc++)
    {
        ans = 0;

        scanf("%d%d", &n, &m);

        for (int i=0; i<n; i++) for (int j=0; j<n; j++) map[i][j] = 0;

        for (int i=0, a, b; i<m; i++)
        {
            scanf("%d%d", &a, &b); 
            map[a-1][b-1] = 1;
        }
        vt.clear();

        solve(0, 0, n, 3, true);

        printf("#%d %d\n", tc, ans);
    }
    return 0;
}
