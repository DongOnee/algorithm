#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 100000

int n;
int parent_of_[MAXN+1];
int road[MAXN+1][MAXN+1];
vector<int> childs_of_[MAXN+1];

long long answer;

int main(int argc, char const *argv[])
{
    int T; cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case)
    {   
        cin >> n;
        answer = 0;

        for (int i=1; i<=n; ++i)
        {
            for (int j=1; j<=n; ++j)
                road[i][j] = 0;
            childs_of_[i].clear();
        }

        for (int idx = 2; idx <= n; ++idx)
        {
            cin >> parent_of_[idx];
            childs_of_[parent_of_[idx]].push_back(idx);
            road[parent_of_[idx]][idx] = 1;
            road[idx][parent_of_[idx]] = 1;
        }

        queue<int> qu;
        qu.push(1);
        while (!qu.empty())
        {
            int f = qu.front();
            sort(childs_of_[f].begin(), childs_of_[f].end());
        }

    }
    return 0;
}
