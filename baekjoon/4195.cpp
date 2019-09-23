/**
 * 19.9.23. 22:23 ~ 24:03
 * Fail
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

typedef pair<int, int> pii;

int cntFriends;
map<string, int> name_idx;
vector<int> idxConnectedGroup;
vector<int> cntGroup;
vector<int> idxGroup;

void init()
{
    cntFriends = 0;
    name_idx.clear();
    idxConnectedGroup.clear();
    cntGroup.clear();
    idxGroup.clear();
}

int calc(int idxs[])
{
    for (int i=0; i<2; i++)
        if (idxGroup[idxs[i]] != -1)
            while (idxConnectedGroup[idxGroup[idxs[i]]] != -1) 
                idxGroup[idxs[i]] = idxConnectedGroup[idxGroup[idxs[i]]];
    
    if (idxGroup[idxs[0]] == -1)
    {
        if (idxGroup[idxs[1]] == -1)
        {
            for (int i=0; i<2; i++) idxGroup[idxs[i]] = cntGroup.size();
            cntGroup.push_back(2);
            idxConnectedGroup.push_back(-1);
            return 2;
        }
        else
        {
            idxGroup[idxs[0]] = idxGroup[idxs[1]];
            return ++cntGroup[idxGroup[idxs[0]]];
        }
    }
    else
    {
        if (idxGroup[idxs[1]] == -1)
        {
            idxGroup[idxs[1]] = idxGroup[idxs[0]];
            return ++cntGroup[idxGroup[idxs[1]]];
        }
        else
        {
            if (idxGroup[idxs[0]] == idxGroup[idxs[1]]) return cntGroup[idxGroup[idxs[0]]];
            for (int i=0; i<2; i++) idxConnectedGroup[idxGroup[idxs[i]]] = cntGroup.size();
            cntGroup.push_back(cntGroup[idxGroup[idxs[0]]] +cntGroup[idxGroup[idxs[1]]]);
            idxConnectedGroup.push_back(-1);
            return cntGroup.back();
        }
    }
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
                idxGroup.push_back(-1);
            } else idxA = name_idx[a];

            if (name_idx.find(b) == name_idx.end())
            {
                name_idx.insert({b, cntFriends});
                idxB = cntFriends++;
                idxGroup.push_back(-1);
            } else idxB = name_idx[b];

            int idxs[2] = {idxA, idxB};
            cout << calc(idxs) << '\n';
        }
    }
    
    return 0;
}
/*
1
7
1 2
3 4
5 6
7 8
2 3
6 7
1 8

1
6
1 2
3 4
5 6
2 3
4 5
6 1

*/