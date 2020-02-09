#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 500
#define MAXM 25000

typedef pair<int, int> pii;

int n, m;
int prev_score[MAXN+1], new_score[MAXN+1];
vector<pii> rank_team;

void run()
{
    int ret = 0;

    for (int numTeam=1; numTeam<=n; numTeam++)
        rank_team.push_back({new_score[numTeam], numTeam});
    
    sort(rank_team.begin(), rank_team.end());

    if (rank_team.size() != n) ret = 2;

    for (int i=1; i<n && ret == 0; i++)
    {
        if (rank_team[i].first == rank_team[i-1].first)
        {
            ret = 1;
            break;
        }
    }

    if (ret == 2) cout << "?";
    else if (ret == 1) cout << "IMPOSSIBLE";
    else
        for (auto& x : rank_team) cout << x.second << ' ';
    cout <<'\n';    
}

void init()
{
    rank_team.clear();

    cin >> n;
    for (int rank=1, numTeam; rank<=n; rank++)
    {
        cin >> numTeam;
        prev_score[numTeam] = rank;
        new_score[numTeam] = rank;
    }

    cin >> m;
    for (int a, b; m; --m)
    {
        cin >> a >> b;
        if (prev_score[a] < prev_score[b]) ++new_score[a], --new_score[b];
        else --new_score[a], ++new_score[b];
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case)
    {
        init();
        run();
    }

    return 0;
}
