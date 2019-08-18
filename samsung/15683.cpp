/**
 * 11:33
 */
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<pair<int, int>, int> lader_info;

int n, m, map[9][9], lader[9][9], sol;
vector<lader_info> laders;
const vector<vector<pair<int, int>>> dir[5] ={
    { {{1, 0}}, {{0, 1}}, {{-1, 0}}, {{0, -1}} },
    { {{-1, 0}, {1, 0}}, {{0, -1}, {0, 1}} },
    { {{-1, 0}, {0, -1}}, {{-1, 0}, {0, 1}}, 
      {{1, 0}, {0, 1}}, {{1, 0}, {0, -1}} },
    { {{0, -1}, {-1, 0}, {0, 1}},
      {{-1, 0}, {0, 1}, {1, 0}},
      {{0, 1}, {1, 0}, {0, -1}}, 
      {{1, 0}, {0, -1}, {-1, 0}} },
    { {{-1, 0}, {0, -1}, {1, 0}, {0, 1}} },
};

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<m; }

void dfs(int cnt)
{
    if (cnt == laders.size())
    {
        int ret = 0;
        for (int i=0; i<n; i++) for (int j=0; j<m; j++)
            if (lader[i][j] == 0) ret++;
        sol = min(sol, ret);
        return ;
    }
    lader_info l = laders[cnt];
    int lRow = l.first.first;
    int lCol = l.first.second;
    for (auto x : dir[l.second])
    {
        for (auto y : x)
        {
            for (int i=0; chk(lRow+i*y.first, lCol+i*y.second); i++)
            {
                int nextRow = lRow+i*y.first;
                int nextCol = lCol+i*y.second;
                if (lader[nextRow][nextCol] == -1) break;
                lader[nextRow][nextCol]++;
            }
        }
        dfs(cnt+1);
        for (auto y : x)
        {
            for (int i=0; chk(lRow+i*y.first, lCol+i*y.second); i++)
            {
                int nextRow = lRow+i*y.first;
                int nextCol = lCol+i*y.second;
                if (lader[nextRow][nextCol] == -1) break;
                lader[nextRow][nextCol]--;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) for (int j=0, tmp; j<m; j++) 
    {
        scanf("%d", &tmp);
        map[i][j] = tmp;
        if (tmp != 0)
        {
            if (tmp < 6) laders.push_back({{i, j}, tmp-1});
            else lader[i][j] = -1;
        }
    }
    sol = 987654321;

    dfs(0);

    printf("%d\n", sol);

    return 0;
}
