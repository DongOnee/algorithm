/**
 * 19.2.7.
 * 이전에 풀었던 문제??
 * 이분탐색에 대해서 공부해보도록 하자
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;
int A[100000];

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", A+i);

    sort(A, A+N);

    scanf("%d", &M);
    for (int i=0; i<M; i++)
    {
        int input; scanf("%d", &input);
        int left_index = 0;
        int right_index = N-1;
        while(1)
        {
            int mid_index = (left_index+right_index)/2;
            if (A[mid_index] == input)
            {
                printf("1\n");
                break;
            }
            else if (left_index >= right_index)
            {
                printf("0\n");
                break;
            }
            else if (A[mid_index] < input) left_index = mid_index+1;
            else right_index = mid_index;
        }
    }

    return 0;
}
