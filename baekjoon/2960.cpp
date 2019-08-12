/**
 * 18.12.29. 토요일 
 */
#include <cstdio>

bool arr[1001];

int main(int argc, char const *argv[])
{
    int N, K; scanf("%d %d", &N, &K);
    int start =  2;
    while (1)
    {
        int ret;
        for (; start<=N; start++) if (!arr[start]) {ret=start;break;}
        for (int i=1; i*ret <=N; i++)
        {
            if (arr[i*ret]) continue;
            arr[i*ret] = true;
            // printf("k : %d\ti : %d\tret : %d\n", K, i, ret);
            if (--K == 0)
            {
                printf("%d\n", ret*i);
                return 0 ;
            }
        }
    }
    return 0;
}
