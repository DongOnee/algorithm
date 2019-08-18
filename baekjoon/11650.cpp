/**
 * 18.12.29. 토요일
 * ref. https://dongyeollee.github.io/2018/03/04/Al/11650/
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int N; scanf("%d", &N);
    pair<int, int> arr[100000];
    for (int i=0; i<N; i++)
    {
        int x, y;
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    sort(arr, arr+N);
    
    for (int i=0; i<N; i++) printf("%d %d\n", arr[i].first, arr[i].second);

    return 0;
}
