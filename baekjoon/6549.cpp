/**
 * 19.2.26.
 * ref. https://jason9319.tistory.com/44
 * 이분탐색? 세그먼트 tree???
 */
#include <cstdio>

int n;
long long heights[100000];

int main(int argc, char const *argv[])
{
    while(true)
    {
        scanf("%d", &n);
        if (n==0) break;

        for (int i=0; i<n; i++) scanf("%d", heights+i);
    }
    return 0;
}
