#include <cstdio>
#include <vector>
#include <unordered_map>
// #include <map>
#include <string>
using namespace std;

vector<int> idxPar, cntGrp;

void init(int input)
{
    idxPar.clear();
    cntGrp.clear();
    for (int i=0; i<2*input; i++)
    {
        idxPar.push_back(i);
        cntGrp.push_back(1);
    }
}

int findFunc(const int idx)
{
    if (idxPar[idx] == idx) return idx;
    else return idxPar[idx] = findFunc(idxPar[idx]);
}

int unionFunc(int idxA, int idxB)
{
    int idxGrpA = findFunc(idxA);
    int idxGrpB = findFunc(idxB);
    
    if (idxGrpA != idxGrpB)
    {
        idxPar[idxGrpB] = idxGrpA;
        cntGrp[idxGrpA] += cntGrp[idxGrpB];
        cntGrp[idxGrpB] = 1;
    }
    return cntGrp[idxGrpA];
}

int main(int argc, char const *argv[])
{
    int T; scanf("%d", &T);
    while (T--)
    {
        // map<string, int> name_idx;
        unordered_map<string, int> name_idx;
        int cntFriends = 0;

        int f; scanf("%d", &f);
        init(f);
        while (f--)
        {
            char a[2][21];
            scanf("%s %s", a+0+0, a+1+0);
            if (name_idx.count(a[0]) == 0) name_idx[a[0]] = cntFriends++;
            if (name_idx.count(a[1]) == 0) name_idx[a[1]] = cntFriends++;
            printf("%d\n", unionFunc(name_idx[a[0]], name_idx[a[1]]));
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