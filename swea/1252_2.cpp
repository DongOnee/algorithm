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

/**
 * row, col 점을 시작으로 너비가 size 인 정사각형에서 panel_size 인 도금판으로 
 * 도금할때 가장 많이 벗겨진 부분을 도금할 수 있는 곳과 벗겨진 부분 갯수.
 */
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

/**
 * row, col 점을 시작으로 너비가 size 인 정 사각형에서 panel_size 인 도금판으로
 * 도금할때 생기는 cost 를 return 한다.
 */
int solve(int row, int col, int size, int panel_size, bool isFirst)
{
    int sum_cost = 0;
    while (panel_size > 1) // 3 or 2
    {
        ppiii finded_optimal1 = findOptimal(row, col, size, panel_size);
        if (finded_optimal1.second == 0) break;

        // 도금판의 크기가 3일때 남은 부분에 대해서 도금판을 3 또는 2로 시작할때 코스트를 구한다.
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
        // 일단 optimal1 부분을 덮는다.
        int cost1 = costs[panel_size];

        // panel_size 가 3일때, 3 사이즈 도금판으로 덮은 곳을 2 사이즈 도금판으로 덮어보자?
        int cost2 = 0, remain_damaged = finded_optimal1.second;
        if (panel_size == 3) // 2x2 판넬로 도금하는 경우를 찾자. 
        {
            ppiii finded_optimal2 = findOptimal(finded_optimal1.first.first, finded_optimal1.first.second, 3, 2);
            cost2 += costs[2];
            convert_value(finded_optimal2.first.first, finded_optimal2.first.second, 2, 1, 2);

            ppiii finded_optimal3;
            do
            {
                finded_optimal3 = findOptimal(finded_optimal1.first.first, finded_optimal1.first.second, 3, 2);
                if (finded_optimal3.second > 1)
                {
                    cost2 += costs[2];
                    convert_value(finded_optimal3.first.first, finded_optimal3.first.second, 2, 1, 2);
                }
            } while (finded_optimal3.second > 1);
        }
        // find 1x1 area
        cost2 += costs[1] * count_damaged(finded_optimal1.first.first, finded_optimal1.first.second, panel_size);
        
        // reset
        convert_value(finded_optimal1.first.first, finded_optimal1.first.second, panel_size, 2, 1);

        if (cost1 <= cost2)
        {
            convert_value(finded_optimal1.first.first, finded_optimal1.first.second, panel_size, 1, isFirst ? 3 : 4);
            sum_cost += cost1;
            if (isFirst) vt.push_back({finded_optimal1.first, panel_size});
        }
        else panel_size--;
    }

    // panel size == 1
    for (int i=0; i<size; i++) for (int j=0; j<size; j++) if(map[i][j] == 1)
    {
        sum_cost += costs[1];
        if (isFirst) vt.push_back({{i, j}, 1});
    }
    if (!isFirst) convert_value(row, col, size, 4, 1);

    return sum_cost;
}

int main(int argc, char const *argv[])
{
    int T; scanf("%d", &T);
    for (int tc=1; tc<=T; tc++)
    {
        scanf("%d%d", &n, &m);

        for (int i=0; i<n; i++) for (int j=0; j<n; j++) map[i][j] = 0;

        for (int i=0, a, b; i<m; i++)
        {
            scanf("%d%d", &a, &b); 
            map[a-1][b-1] = 1;
        }
        vt.clear();

        solve(0, 0, n, 3, true);

        printf("#%d %ld", tc, vt.size());
        for (auto x:vt) printf("%d %d %d", x.first.first, x.first.second, x.second);
        printf("\n");
    }
    return 0;
}
