#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vt_connect[100001];
vector<int> cnt_colors;
vector<int> idx_color;

int n, answer, st;
bool chk[100001][100001];

// void calc()
// {
//     // sort(cnt_colors.begin(), cnt_colors.end());
//     sort(cnt_colors.begin(), cnt_colors.end(), greater<int>());
//     for (int i=0; i<n; i++) answer += (i+1)*cnt_colors[i];
// }

int dfs(int idx)
{
    if (idx_color[idx] != -1) return idx_color[idx];
    idx_color[idx] = 0;

    for (int nxt : vt_connect[idx])
    {
        int color_nxt = dfs(nxt);
        if (color_nxt < 0) continue;
        chk[idx][color_nxt] = true;
    }

    int ret = 1;
    while (chk[idx][ret]) ret++;
    cnt_colors[ret]++;
    
    return idx_color[idx] = ret;
}

void init()
{
    scanf("%d", &n);
    cnt_colors.resize(n+1);
    idx_color.assign(n+1, -1);
    for (int i=1, a, b; i<n; i++)
    {
        st = a;
        scanf("%d%d", &a, &b);
        vt_connect[a].push_back(b);
        vt_connect[b].push_back(a);
    }
}

int main(int argc, char const *argv[])
{
    init();
    dfs(st);
    // calc();

    printf("%d\n", answer);

    return 0;
}
