#include <iostream>

using namespace std;

typedef int (*func_pt)(int,int);

const int MAXN = 11;

int plus_fnc(int a, int b) { return a + b; }
int minus_fnc(int a, int b) { return a - b; }
int multi_fnc(int a, int b) { return a * b; }
int rema_fnc(int a, int b) { return a / b; }

int operate_count[4];
int arr[MAXN];
int ans_min = 1'000'000'001, ans_max = -1'000'000'001;
int n;

func_pt operate[4] = {
    plus_fnc,
    minus_fnc,
    multi_fnc,
    rema_fnc
};

void dfs(int idx, int current) 
{
    if (idx == n-1) {
        ans_min = min(ans_min, current);
        ans_max = max(ans_max, current);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (operate_count[i] == 0) continue;
        --operate_count[i];
        dfs(idx+1, operate[i](current, arr[idx+1]));
        ++operate_count[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < 4; ++i) cin >> operate_count[i];

    dfs(0, arr[0]);

   cout << ans_max << '\n' << ans_min << '\n';

    return 0;
}
