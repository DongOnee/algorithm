/**
 * 13.3.26.
 */
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, hei[51], dp[51][500001];
vector<int> diffs;
bool diff_chk[500001];

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", hei+i);
    sort(hei, hei+n);
    int max_ret = 0;

    diffs.push_back(0);
    diffs.push_back(hei[0]);
    diff_chk[0]= true;
    diff_chk[hei[0]]= true;
    dp[0][hei[0]] = hei[0];
    for (int i=1; i<n; i++)
    {
        int segment = hei[i];

        // printf("\nduplicate====%d\n", segment);
        vector<int> tmp(diffs);
        for (auto diff : tmp)
        {
            // printf("%d ", diff);
            int plus_hei = dp[i-1][diff]+segment;
            
            // 큰거에 붙인다.
            int new_diff = diff+segment;
            
            if (dp[i-1][new_diff] < plus_hei)
            {
                dp[i][new_diff] = plus_hei;
                if (!diff_chk[new_diff]) 
                {
                    diff_chk[new_diff] = true;
                    diffs.push_back(new_diff);
                }
            }

            // 작은거에 붙인다.
            new_diff = abs(diff-segment);

            if (dp[i-1][new_diff] < plus_hei)
            {
                dp[i][new_diff] = plus_hei;
                if (!diff_chk[new_diff]) 
                {
                    diff_chk[new_diff] = true;
                    diffs.push_back(new_diff);
                }
            }
        }
        max_ret = max(max_ret, dp[i][0]);
    }

    printf("%d\n", (max_ret==0?-1:max_ret/2));

    return 0;
}



