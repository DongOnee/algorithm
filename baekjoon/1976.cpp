#include <iostream>
#include <vector>
using namespace std;

#define MAXN 200
#define MAXN_PLUS_1 201
#define MAXM 1000

int n, m, board[MAXN_PLUS_1][MAXN_PLUS_1], group[MAXN_PLUS_1];
vector<int> trav;

int find(int idx)
{
    if (idx == group[idx]) return idx;
    return group[idx] = find(group[idx]);
}

void merge(int a, int b)
{
    group[find(b)] = find(a);
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++) 
            cin >> board[i][j];
        group[i] = i;
    }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (board[i][j])
                merge(i, j);

    for (int i=0, a; i<m; i++)
    {
        cin >> a;
        trav.push_back(a);
    }

    bool ret = true;
    for (auto& x : trav)
    {
        if (find(trav[0]) != find(x))
        {
            ret = false;
            break;
        }
    }

    cout << (ret?"YES":"NO")<< '\n';

    return 0;
}
