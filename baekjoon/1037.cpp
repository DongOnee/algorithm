#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 50

int n, arr[MAXN];

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", arr+i);

    sort(arr, arr+n);

    printf("%d\n", arr[0]*arr[n-1]);
    return 0;
}
