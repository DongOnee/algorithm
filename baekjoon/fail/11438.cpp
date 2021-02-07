#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN = 100'001;
vector<int> childs[MAXN];
int depths[MAXN], idx2count[MAXN], count2idx[2*MAXN];

int cnt = 1;

void dfs(int idx, int dept)
{
    depths[idx] = dept;
    count2idx[cnt] = idx;
    idx2count[idx] = cnt++;

    for (const int& nxt : childs[idx]) {
        if (depths[nxt] != -1) continue;

        dfs(nxt, dept+1);
        count2idx[cnt] = idx;
        idx2count[idx] = cnt++;
    }
}

void sol(int aIdx, int bIdx)
{
    int aCount = min(idx2count[aIdx], idx2count[bIdx]);
    int bCount = max(idx2count[aIdx], idx2count[bIdx]);

    int ans = aCount;
    while (++aCount <= bCount) {
        if (depths[count2idx[aCount]] < depths[count2idx[ans]]) {
            ans = aCount;
        }
    }

    cout << count2idx[ans] << '\n';
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        childs[a].push_back(b);
        childs[b].push_back(a);
    }

    memset(depths, -1, sizeof(depths));

    dfs(1, 0);

    int m; cin >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        sol(a, b);
    }

    return 0;
}
