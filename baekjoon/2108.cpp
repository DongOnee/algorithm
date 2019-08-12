/**
 * 18.12.26. 수요일
 */
#include <cstdio>
#include <algorithm>

int count[8001];

int main(int argc, char const *argv[])
{
    int N; scanf("%d", &N);

    int sum=0;
    for (int i=0; i<N; i++)
    {
        int input; scanf("%d", &input);
        sum += input;
        count[input+4000]++;
    }

    int count_sum=0;
    int middle=-4001;
    int max_count_num=-4000;
    bool max_count = false;
    int st=-4001, en=4001;
    for (int i=-4000; i<4001; i++)
    {
        if (count[i+4000] == 0) continue;
        count_sum += count[i+4000];
        if (middle==-4001&&N<2*count_sum) middle=i;
        if (count[i+4000] > count[max_count_num+4000])
        {
            max_count=false;
            max_count_num=i;
        }
        else if (count[i+4000] == count[max_count_num+4000])
        {
            if (!max_count)
            {
                max_count_num=i;
                max_count= true;
            }
        }
        if (st==-4001) st=i;
        if (count_sum==N) en=i;
    }

    // printf("%d\n", ((sum%N)*2<N)?sum/N:sum/N+1);
    printf("%d\n", sum/N+(std::abs(sum%N)*2<N?0:((sum<0)?-1:1)));
    printf("%d\n", middle);
    printf("%d\n", max_count_num);
    printf("%d\n", en-st);
    return 0;
}
