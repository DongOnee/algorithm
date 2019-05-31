/**
 * 19.1.11.
 */
#include <cstdio>
int N, B;
int A[5][5];

void mat(int matrix1[5][5], int matrix2[5][5])
{
    
}

void mul(int po)
{
    int sol[5][5]= {0, };
    
    while(po){
        if (po % 2 == 1)
        {
        }
        po >>= 1;
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &B);
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) scanf("%d", &A[i][j]);

    if (B!=1) mul(B);

    for (int i=0; i<N; i++) 
    {
        for (int j=0; j<N; j++) printf("%d ", A[i][j]);
        printf("\n");
    }
    return 0;
}
