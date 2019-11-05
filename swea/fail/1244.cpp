#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, ans[6], cnt;

int main(int argc, char const *argv[])
{
    // freopen("1244_input.txt", "r", stdin);
    int t; scanf("%d", &t);
    for (int test_case=1; test_case<=t; test_case++)
    {
        cnt = 0;
        scanf("%d%d", &n, &k);
        while (n)
        {
            ans[cnt] = n%10;
            n/=10;
            cnt++;
        }

        // 가장 큰수 만들기
        int idx_complete = cnt;
        while (k && idx_complete)
        {
            int idx_max = idx_complete-1;
            for (int i = idx_complete-2; 0<=i; i--)
            {
                if (ans[idx_max] <= ans[i]) idx_max = i;
            }
            if (ans[idx_max] == ans[idx_complete-1])
            {
                idx_complete--;
                continue;
            }

            swap(ans[idx_max], ans[--idx_complete]);
            k--;
        }
        // k 가 짝수면 그만 홀수면 가장 작은것 둘 자리 교환
        if (k%2 == 1) swap(ans[1], ans[0]);
        printf("#%d ", test_case);
        for (int i=cnt; 0<i; i--) printf("%d", ans[i-1]);
        printf("\n");
    }
    return 0;
}
