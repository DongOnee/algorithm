#include <cstdio>
#include <map>
using namespace std;

int mmap[4][4];
map<int, bool> mp;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void dfs(int r, int c, int cnt, int val)
{
    val = val*10+mmap[r][c];
    if (cnt==6)
    {
        if (mp.count(val) == 0) mp[val] = true;
    }
    else
    {
        for (int i=0; i<4; i++)
        {
            int nr=r+dir[i][0], nc=c+dir[i][1];
            if (0<=nr&&nr<4&&0<=nc&&nc<4)
            {
                dfs(nr, nc, cnt+1, val);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    // freopen("2819_input.txt", "r", stdin);
    int tc; scanf("%d", &tc);
    for (int test_case=1; test_case<=tc; test_case++)
    {
        mp.clear();
        for (int i=0; i<4; i++) for (int j=0; j<4; j++) scanf("%d", mmap[i] +j);
        for (int i=0; i<4; i++) for (int j=0; j<4; j++) dfs(i, j, 0, 0);

        printf("#%d %ld\n", test_case, mp.size());
    }
    return 0;
}
