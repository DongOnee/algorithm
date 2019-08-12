/**
 * 18.12.21. 금요일
 */
#include <cstdio>

#define MAXNUM 10000

int cnt_arr[MAXNUM];

int main(int argc, char const *argv[])
{
    int N; scanf("%d", &N);
    for (int i=0; i<N; i++)
    {
        int input; scanf("%d", &input);
        cnt_arr[input-1]++;
    }

    for (int i=1; i<=MAXNUM; i++) for(int j=0; j<cnt_arr[i-1]; j++) printf("%d\n", i);
    return 0;
}
