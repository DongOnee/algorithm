/**
 *
 */
#include <cstdio>
#include <utility>
using namespace std;

int t;
int map[100002];
int cost[100002];

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    for(int tc=1, n; tc<=t; tc++)
    {
        int sol=0;
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", map+i);
        map[n+1] = 0;

        for (int i=1; i<=n; i++) cost[i] = map[i-1] + map[i+1];
        printf("\nsol: ");
        
        bool flag = true;
        while (flag)
        {
            // for (int i=0; i<n; i++) printf("%2d ", map[i+1]);
            // for (int i=0; i<n; i++) printf("%2d ", cost[i+1]);
            // printf("---cost\n\n");

            flag = false;
            int maxIndex=0;
            for (int i=0; i<=n; i++)
            {
                if (map[i]==0) continue;
                if (map[i-1]==0&&map[i+1]==0)
                {
                    printf("%d ",map[i]);
                    sol += map[i];
                    map[i] = 0;
                    i++;
                    continue;
                }
                flag=true;
                if (cost[maxIndex] < cost[i]) maxIndex = i;
            }
            cost[maxIndex-1] -= map[maxIndex];
            cost[maxIndex+1] -= map[maxIndex];
            map[maxIndex]=0;
            cost[maxIndex]=-1;
        }
        printf("\n#%d %d\n", tc, sol);
    }
    return 0;
}



/*
기회 비용이 큰걸 x
1 2 3 
2 4 2  =>  1, 3 채택

1 7 8  9  2
7 9 16 10 9  
7 1 -1 2 9
7 1 -1 0 -1


5
9
1 2 1 3 2 2 2 2 3
5
100000 100000 100000 100000 100000
10
1 7 1 4 9 10 8 2 9 9
10
10 5 8 9 5 6 8 7 2 8
20
70 22 52 79 32 47 56 78 17 76 58 32 71 22 90 42 42 2 59 100



*/

