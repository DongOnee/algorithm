/**
 * 18.12.6. 목요일 ~ 18.12.7. 금요일
 */
#include <cstdio>
#include <stack>
#include <utility>
using namespace std;

stack<pair<int, int>> st;

int N, H, M; // N: 세로줄   H: 가로점선      M: 가로실선
int ret=1e5;
bool map[31][11];

bool chk() {
    for (int vert_index=1; vert_index<=N; vert_index++)
    {
        int cur = vert_index;
        for (int hori_index=1; hori_index<=H; hori_index++)
        {
            if (map[hori_index][cur]) cur++;
            else if (map[hori_index][cur-1]) cur--;
        }
        if (cur != vert_index) return false;
    }
    return true;
}

void dfs(int horizon, int vertical, int count) {
    if (ret <= count) return;
    if (chk())
    {
        ret = count;
        return;
    }
    if (count == 3) return;
    for (int hori_index=horizon; hori_index<=H; hori_index++, vertical=1)
    {
        for (int vert_index=vertical; vert_index<N; vert_index++)
        {
            if (map[hori_index][vert_index])
            {
                vert_index++;
                continue;
            }
            if (vert_index+1 < N) if (map[hori_index][vert_index+1]) continue;
            map[hori_index][vert_index] = true;
            dfs(hori_index, vert_index+2, count+1);
            map[hori_index][vert_index] = false;
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &N, &M, &H);
    for (int i=0; i<M; i++)
    {
        int a, b; // a: 1~H     b: 1~N-1
        scanf("%d %d", &a, &b);
        map[a][b]=true;
    }

    dfs(1,1,0);

    if (ret>3) printf("-1\n");
    else printf("%d\n", ret);

    return 0;
}