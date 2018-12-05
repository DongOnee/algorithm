/**
 * 18.12.05. 수요일
 * DP 를 이용하여 풀이
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int t[15], p[15], d[16][2];

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d %d", &t[i], &p[i]);
        // t[i]=0;p[i]=0;d[i][0]=0;d[i][1]=0;
    }

    for (int index=N-1; 0<=index; index--)
    {
        if (index+t[index] > N)
        {
            d[index][0] = max(d[index+1][0], d[index+1][1]);
            d[index][1] = 0;
            continue;
        }
        d[index][0] = max(d[index+1][0], d[index+1][1]);
        d[index][1] = p[index] + max(d[index+t[index]][0], d[index+t[index]][1]);
    }

    printf("%d\n", max(d[0][0], d[0][1]));
    return 0;
}
