/**
 * 18.12.05. 수요일
 */
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

int N, M, map[8][8];
int init_zero, min_zero;

pair<int, int> stack[64];
int stack_size;
pair<int, int> cctv[5][64];
int cctv_size[5];

int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

bool chk(int row, int col) { return 0<=row&&row<N&&0<=col&&col<M; }

int go(int row, int col, int _dir) {
    int ret=0;
    int _row = row;
    int _col = col;
    while(true)
    {
        _row += dir[_dir][0];
        _col += dir[_dir][1];
        if (!chk(_row, _col)) break;
        if (map[_row][_col] == 6) break;
        else if (map[_row][_col] == 0)
        {
            ret++;
            stack[stack_size++] = {_row, _col};
            map[_row][_col] = -1;
            init_zero--;
        }
    }
    return ret;
}

void clear(int count) {
    int _count = count;
    while(_count--)
    {
        pair<int, int> tmp = stack[--stack_size];
        map[tmp.first][tmp.second] = 0;
        init_zero++;
    }
}

void dfs(int cctv_list, int cctv_index) {
    if (cctv_list == 5) min_zero = min(min_zero, init_zero);
    else if (cctv_index == cctv_size[cctv_list]) dfs(cctv_list+1, 0);
    else if (cctv_list == 1)
    {
        for (int i=0; i<4; i++)
        {
            int tmp = go(cctv[cctv_list][cctv_index].first, cctv[cctv_list][cctv_index].second, i);
            dfs(cctv_list, cctv_index+1);
            clear(tmp);
        }
    }else if (cctv_list == 2)
    {
        for (int i=0; i<2; i++)
        {
            int tmp = go(cctv[cctv_list][cctv_index].first, cctv[cctv_list][cctv_index].second, i*2);
            tmp += go(cctv[cctv_list][cctv_index].first, cctv[cctv_list][cctv_index].second, i*2+1);
            dfs(cctv_list, cctv_index+1);
            clear(tmp);
        }
    }else if (cctv_list == 3)
    {
        for (int i=0; i<4; i++)
        {
            int tmp = go(cctv[cctv_list][cctv_index].first, cctv[cctv_list][cctv_index].second, i/2);
            tmp += go(cctv[cctv_list][cctv_index].first, cctv[cctv_list][cctv_index].second, i%2+2);
            dfs(cctv_list, cctv_index+1);
            clear(tmp);
        }
    }else if (cctv_list == 4)
    {
        for (int i=0; i<4; i++)
        {
            int tmp = go(cctv[cctv_list][cctv_index].first, cctv[cctv_list][cctv_index].second, i);
            tmp += go(cctv[cctv_list][cctv_index].first, cctv[cctv_list][cctv_index].second, (i+1)%4);
            tmp += go(cctv[cctv_list][cctv_index].first, cctv[cctv_list][cctv_index].second, (i+2)%4);
            dfs(cctv_list, cctv_index+1);
            clear(tmp);
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    init_zero=0; min_zero=64;
    for (int i=0; i<N; i++) for (int j=0; j<M; j++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp == 0) init_zero++;
        else if (tmp == 5) cctv[0][cctv_size[0]++] = {i, j};
        else if (tmp < 5) cctv[tmp][cctv_size[tmp]++] = {i, j};
        map[i][j] = tmp;
    }

    for (int j=0; j<cctv_size[0]; j++)
        for (int i=0; i<4; i++) go(cctv[0][j].first, cctv[0][j].second, i);
    stack_size = 0;

    dfs(1, 0);

    printf("%d\n", min_zero);
    return 0;
}
