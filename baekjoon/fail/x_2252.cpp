/**
 * 19.2.14.
 */
#include <cstdio>
#include <queue>
using namespace std;

int N, M;
int pre_[32001];
int next_[32001];

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    
    for (int i=0; i<M; i++)
    {
        int A, B; scanf("%d %d", &A, &B);
        int k;
        for (k=B; pre_[k] > 0; k=pre_[k]);
        pre_[k] = A;
        B=k;
        for (k=A; next_[k] >0; k=next_[k]);
        next_[k] = B;
    }
/*
    printf("\tpre\tnext\n");
    for (int i=1; i<=N; i++)
    {
        printf("%d|\t%d\t%d\n", i, pre_[i], next_[i]);
    }
*/
    for (int i=1; i<=N; i++)
    {
        if(pre_[i] == 0)
        {
            for(int j=i; j!=0; j=next_[j]) printf("%d ", j);
        }
    }
    return 0;
}



/*
1 2 3

1 3
q : 1 3

2 3
q : 2 1 3

1 2

q ; 1 2 3

*/

