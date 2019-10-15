#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1000000];

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", arr+i);

    sort(arr, arr+n, greater<int>());

    for (int i=0; i<n; i++) printf("%d\n", arr[i]);
    return 0;
}
