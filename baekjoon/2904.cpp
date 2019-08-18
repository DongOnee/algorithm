/**
 * 19.4.3.
 */
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n;
int paper[101];

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", paper+i);

    sort(paper, paper+n);
    int maxValue = paper[n-1];

    vector<int> de;
    de.push_back(2);
    for (int i=3; i<=maxValue; i+=2)
    {
        bool flag=true;
        for (auto x : de)
        {
            if (i%x==0)
            {
                flag=false;
                break;
            }
            if (i < x*x) break;
        }
        if (flag) de.push_back(i);
    }
// 2 3 5 7 11
    int solValue=1, solCnt=0;
    for (auto x : de)
    {
        int sum = 0;
        int sibal[101] = {0, };
        for (int i=0; i<n; i++)
        {
            int ii = x;
            while (paper[i]%ii ==0)
            {
                ii*=x;
                sibal[i]++;
            }
            sum += sibal[i];
        }
        int ssibal = sum/n;
        if (ssibal==0) continue;
        solValue *= pow(x, ssibal);
        for (int i=0; i<n; i++)
        {
            if (sibal[i] < ssibal) solCnt += ssibal-sibal[i];
        }
    }

    printf("%d %d\n", solValue, solCnt);

    return 0;
}
