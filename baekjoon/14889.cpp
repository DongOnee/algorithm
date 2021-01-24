#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 20;

int people_count;
int abilities[MAXN][MAXN];
int ans = 987654321;

vector<int> team1, team2;

void dfs(int idx, int team_count)
{
    if (idx == people_count) {
        int ab1 = 0, ab2 = 0;
        for (int x : team1) {
            for (int y : team1) {
                ab1 += abilities[x][y];
            }
        }

        for (int x : team2) {
            for (int y : team2) {
                ab2 += abilities[x][y];
            }
        }

        ans = min(ans, abs(ab1 - ab2));

        return;
    }

    if (team_count == people_count / 2) {
        team2.emplace_back(idx);
        dfs(idx+1, team_count);
        team2.pop_back();
    }
    else if (idx - team_count == people_count / 2) {
        team1.emplace_back(idx);
        dfs(idx+1, team_count+1);
        team1.pop_back();
    }
    else {
        team1.emplace_back(idx);
        dfs(idx+1, team_count+1);
        team1.pop_back();

        team2.emplace_back(idx);
        dfs(idx+1, team_count);
        team2.pop_back();
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> people_count;
    for (int row = 0; row < people_count; ++row)
        for (int col = 0; col < people_count; ++col)
            cin >> abilities[row][col];

    team1.emplace_back(0);

    dfs(1, 1);
    
    cout << ans << '\n';

    return 0;
}
