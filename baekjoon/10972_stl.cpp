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
    
    if(next_permutation(vt.begin(), vt.end()))
        for (int x : vt) printf("%d ", x);
    else printf("-1\n");
    
    return 0;
}

/*
5
3 1 2 5 4

5
3 1 4 5 2
*/