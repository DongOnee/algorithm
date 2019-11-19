#include <cstdio>
#include <queue>
using namespace std;

int n, m;
char map[21][21];
bool visited[20][20][16][4];
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

typedef struct _info
{
    int r, c, di, mem;
    _info() : r(0), c(0), di(0), mem(0) {};
    void go() 
    {
        r = (r+dir[di][0]+n)%n;
        c = (c+dir[di][1]+m)%m;
    }
}cur_info;
queue<cur_info> qu;

void init()
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) scanf("%s", map[i]);
    while (!qu.empty()) qu.pop();
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) for (int k=0; k<16; k++) for (int g=0; g<4; g++) visited[i][j][k][g] = false;
    qu.push(cur_info());
    visited[0][0][0][0] = true;
}

bool run()
{
    while (!qu.empty())
    {
        long sz = qu.size();
        while(sz--)
        {
            cur_info f = qu.front(); qu.pop();

            if (map[f.r][f.c] == '@') return true;
            else if (map[f.r][f.c] == '?')
            {
                for (int di=0; di<4; di++)
                {
                    cur_info ff = f;
                    ff.di = di;
                    ff.go();
                    if (visited[ff.r][ff.c][ff.mem][ff.di]) continue;
                    visited[ff.r][ff.c][ff.mem][ff.di] = true;
                    qu.push(ff);
                }
            }
            else 
            {
                if (map[f.r][f.c] == '.') ;
                else if (map[f.r][f.c] == '>') f.di = 0;
                else if (map[f.r][f.c] == 'v') f.di = 1;
                else if (map[f.r][f.c] == '<') f.di = 2;
                else if (map[f.r][f.c] == '^') f.di = 3;
                else if (map[f.r][f.c] == '_')
                {
                    if (f.mem == 0) f.di = 0;
                    else f.di = 2;
                }
                else if (map[f.r][f.c] == '|')
                {
                    if (f.mem == 0) f.di = 1;
                    else f.di = 3;
                }
                else if (map[f.r][f.c] == '+')
                {
                    f.mem++;
                    f.mem %= 16;
                }
                else if (map[f.r][f.c] == '-')
                {
                    f.mem += 15;
                    f.mem %= 16;
                }
                else f.mem = map[f.r][f.c] - '0';

                f.go();
                if (visited[f.r][f.c][f.mem][f.di]) continue;
                visited[f.r][f.c][f.mem][f.di] = true;
                qu.push(f);
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    // freopen("1824_input2.txt", "r", stdin);
    int tc; scanf("%d", &tc);
    for (int test_case=1; test_case<=tc; test_case++)
    {
        init();
        printf("#%d %s\n", test_case, (run())?"YES":"NO");
    }
    return 0;
}
