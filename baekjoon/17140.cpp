/**
 * 19.06.09. 11:17 ~
 */
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int r, c, k, ans;
int map[100][100];
int max_row, max_col;

void R()
{
    int cnt_col=0;
    for (int row_index=0; row_index<max_row; row_index++)
    {
        vector<pair<int, int>> vvt(101, {0, 101});
        for (int col_index=0; col_index<max_col; col_index++)
        {
            int maprc = map[row_index][col_index];
            if (maprc == 0) continue;
            vvt[maprc].second = maprc;
            vvt[maprc].first++;
        }
        sort(vvt.begin(), vvt.end());

        int kk =0;
        for (auto x : vvt)
        {
            if (x.first == 0) continue;
            map[row_index][kk++] = x.second;
            map[row_index][kk++] = x.first;
        }
        cnt_col = max(cnt_col, kk);
        while (kk<max_col) map[row_index][kk++] = 0;
    }
    max_col = max(max_col, cnt_col);
}

void C()
{
    int cnt_row=0;
    for (int col_index=0; col_index<max_col; col_index++)
    {
        vector<pair<int, int>> vvt(101, {0, 101});
        for (int row_index=0; row_index<max_row; row_index++)
        {
            int maprc = map[row_index][col_index];
            if (maprc == 0) continue;
            vvt[maprc].second = maprc;
            vvt[maprc].first++;
        }
        sort(vvt.begin(), vvt.end());

        int kk =0;
        for (auto x : vvt)
        {
            if (x.first == 0) continue;
            map[kk++][col_index] = x.second;
            map[kk++][col_index] = x.first;
        }
        cnt_row = max(cnt_row, kk);
        while (kk<max_row) map[kk++][col_index] = 0;
    }
    max_row = max(max_row, cnt_row);
}

int main(int argc, char const *argv[])
{
    max_row = 3, max_col=3;
    scanf("%d%d%d", &r, &c, &k);
    for (int i=0; i<max_row; i++) for (int j=0; j<max_col; j++) scanf("%d", map[i]+j);

    while (map[r-1][c-1] != k)
    {
        if (max_row >= max_col) R();
        else C();
        ans++;

        // for (int i=0; i<max_row; i++)
        // { 
        //     for (int j=0; j<max_col; j++) printf("%d ", map[i][j]);
        //     puts("");
        // } 
        // puts("");
        if (ans >100)
        {
            ans = -1;
            break;
        }
    }

    printf("%d\n", ans);

    return 0;
}
