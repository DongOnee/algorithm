/**
 * 19.9.23. 21:29 ~ 22:23
 * Fail Time over
 */
#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> relations;
int cntFriends;
map<string, int> name_idx;

void init()
{
    relations.clear();
    cntFriends = 0;
    name_idx.clear();
}

int bfs(int idxStart)
{
    int ret = 0;
    queue<int> qu;
    qu.push(idxStart);
    vector<bool> visited(cntFriends);
    visited[idxStart] = true;

    while(!qu.empty())
    {
        int f = qu.front(); qu.pop();
        ret++;
        for (int x:relations[f])
        {
            if (visited[x]) continue;
            visited[x] = true;
            qu.push(x);
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--)
    {
        init();

        int f; cin >> f;
        while (f--)
        {
            string a, b;
            int idxA, idxB;
            cin >> a >> b;
            if (name_idx.find(a) == name_idx.end())
            {
                name_idx.insert({a, cntFriends});
                idxA = cntFriends++;
                relations.push_back(vector<int>());
            } else idxA = name_idx[a];
            if (name_idx.find(b) == name_idx.end())
            {
                name_idx.insert({b, cntFriends});
                idxB = cntFriends++;
                relations.push_back(vector<int>());
            } else idxB = name_idx[b];

            relations[idxA].push_back(idxB);
            relations[idxB].push_back(idxA);

            cout << bfs(idxA) << endl;
        }
    }
    
    return 0;
}
/*
2
3
Fred Barney
Barney Betty
Betty Wilma
3
Fred Barney
Betty Wilma
Barney Betty
*/