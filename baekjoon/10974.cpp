#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> vt;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0, a; i<n; i++)
    {
        scanf("%d", &a);
        vt.push_back(a);
    }

    int idxStart = n-1;
    while (idxStart > 0 && (vt[idxStart-1] > vt[idxStart])) idxStart--;

    if (idxStart == 0) printf("-1\n");
    else
    {
        int cmp = vt[idxStart-1];
        for (int i=0; i< idxStart-1; i++) printf("%d ", vt[i]);
        sort(vt.begin()+idxStart-1, vt.end());
        
        int x = upper_bound(vt.begin()+idxStart, vt.end(), cmp)-vt.begin();
        x = vt[x];
        printf("%d ", x);
        for (int idx = idxStart-1; idx<n; idx++) if (vt[idx] != x) printf("%d ", vt[idx]);
    }
    
    
    return 0;
}

/*
5
3 1 2 5 4

5
3 1 4 5 2
*/