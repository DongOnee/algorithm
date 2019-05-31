/**
 * 19.3.14.
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int n, height[50], dp[50][500001];

int main(int argc, char const *argv[])
{
    scanf("%d", &n);

    for (int i=0; i<n; i++) scanf("%d", height+i);

    sort(height, height+n);
    for (int i=0; i<n; i++) for (int j=0; j<500001; j++) dp[i][j] = -1;
    dp[0][height[0]] = 0;

    for (int index=1; index<n; index++)
    {
        int seg_hei = height[index];
        for (int diff=0, s, l, su, s2, l2, su2; diff<500001; diff++)
        {
            // diff : 내가 차이 내고 싶은 만큼
            dp[index][diff] = dp[index-1][diff]; // seg 를 안쓰면 되는거잖아? 이전에 최대로 만들어 뒀던거 

            s = diff + seg_hei; // 작은거에  seg 붙이는데
            su = seg_hei - diff; // 작은거에 seg 를 붙이는데 더 커짐
            l = diff - seg_hei; // 큰거에   seg 붙이는데
            // s, su, l 은 이전 단계에서 ? 큰거랑 작은거 차이?

            if (s > 500000) s2 = -1; // 그런게 없어
            else if (dp[index-1][s] == -1) s2 = -1; // s 만큼 차이나는걸 만들수 없어
            else s2 = dp[index-1][s] + seg_hei; // s 만큼 차이나는것중 작은거에 seg 를 쌓는다.
            dp[index][diff] = max(dp[index][diff], s2);
            
            if (su < 0) su2 = -1;
            else if (dp[index-1][su] == -1) su2 = -1;
            else su2 = dp[index-1][su] + su;
            dp[index][diff] = max(dp[index][diff], su2);

            if (l < 0) l2 = -1;
            else if (dp[index-1][l] == -1) l2 = -1;
            else l2 = dp[index-1][l];
            dp[index][diff] = max(dp[index][diff], l2);
        }
    }

    printf("%d\n", dp[n-1][0]);
    return 0;
}
