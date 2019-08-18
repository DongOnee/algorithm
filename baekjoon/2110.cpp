/**
 * 19.2.18.
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int N, C;
int homes[200001];

int main(int argc, char const *argv[])
{
    scanf("%d%d", &N, &C);

    for (int i=0; i<N; i++) scanf("%d", homes+i);
    sort(homes, homes+N);

    int l=1, r=homes[N-1]-homes[0]; // 가능한 l : 가장 작은 차이?, r : 가장 큰 차이
    while(l<r)
    {
        int mid = (l+r+1)/2;
        int cnt =1, cur = homes[0];
        for (int i=1; i<N; i++)
        {
            if (homes[i] < cur + mid) continue;
            cnt++;
            cur = homes[i];
        }
        if (cnt < C) r = mid-1;     // 너무 듬성듬성 -> 촘촘하게 -> mid 를 줄임
        else l = mid;               // 너무 촘촘 -> 듬성듬성하게 -> mid 를 크게
    }

    printf("%d\n", l);
    return 0;
}
