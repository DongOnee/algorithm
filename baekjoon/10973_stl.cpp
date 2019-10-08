#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> vt;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++) vt.push_back(i);

    do
    {
        for (auto x : vt) printf("%d ", x);
        printf("\n");
    } while (next_permutation(vt.begin(), vt.end()));
    
    return 0;
}