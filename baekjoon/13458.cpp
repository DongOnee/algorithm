#include <cstdio>

int N; // 시험장 수
int A[1000000]; // 시험장 응시자 수
int B, C; // 총 감독관, 부감독관 감시 응시자 수

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &A[i]);
    scanf("%d %d", &B, &C);

    long long ret=0;

    for (int i=0; i<N; i++)
    {
        A[i] -= B;
        ret++;
        if (A[i]>0)
        {
            A[i] += C-1;
            ret += A[i]/C;
        }
    }

    printf("%lld\n", ret);

    return 0;
}
