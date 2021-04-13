#include <iostream>
#include <algorithm>

using namespace std;

const int MAXP = 10;
const int MAXS = 2;
const int INF = 987654321;

int time_p_to_s[MAXP][MAXS];
int pr[MAXP], pc[MAXP], person_count;
int sr[MAXS], sc[MAXS], sk[MAXS];
int vt[2][MAXP], vidx[2];
int ans;

void init()
{
    person_count = 0;
    ans = INF;
    vidx[0] = vidx[1] = 0;

    int board_size; cin >> board_size;
    int tmp, idxs = 0;;
    for (int r = 0; r < board_size; ++r) for (int c = 0; c < board_size; ++c) {
        cin >> tmp;
        if (tmp == 1) {
            pr[person_count] = r, pc[person_count++] = c;
        }
        else if (tmp > 1) {
            sr[idxs] = r, sc[idxs] = c, sk[idxs++] = tmp;
        }
    }

    for (int p = 0; p < person_count; ++p) {
        for (int s = 0; s < MAXS; ++s) {
            time_p_to_s[p][s] = abs(pr[p]-sr[s]) + abs(pc[p]-sc[s]);
        }
    }
}

void sol()
{
    int times[MAXS][MAXP+1];
    times[0][0] = times[1][0] = -INF;
    for (int s = 0; s < MAXS; ++s) {
        for (int i = 1; i <= vidx[s]; ++i) times[s][i] = vt[s][i-1] + 1;
        sort(times[s] + 1, times[s] + 1 + vidx[s]);
    }

    for (int s = 0; s < MAXS; ++s) {
        for (int i = 4; i <= vidx[s]; ++i) {
            if (times[s][i] < times[s][i-3] + sk[s]) times[s][i] = times[s][i-3] + sk[s];
        }
    }

    ans = min(ans, max(times[0][vidx[0]] + sk[0], times[1][vidx[1]] + sk[1]));
    // ans = min(ans, max(
    //             (vidx[0] == 0?0:times[0][vidx[0]-1] + sk[0]), 
    //             (vidx[1] == 0?0:times[1][vidx[1]-1] + sk[1])));
}

void dfs(int p_idx)
{
    if (p_idx == person_count) {
        sol();
        return;
    }

    for (int s = 0; s < MAXS; ++s) {
        vt[s][vidx[s]++] = time_p_to_s[p_idx][s];
        dfs(p_idx+1);
        --vidx[s];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >>T;
    for (int tc = 1; tc <=T; ++tc) {
        init();
        dfs(0);

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
