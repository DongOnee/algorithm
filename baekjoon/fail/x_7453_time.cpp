/**
 * 19.4.12.
 */
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, sol;
vector<int> arr[4];

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0, input[4]; i<n; i++)
        for (int j=0; j<4; j++)
        {
            scanf("%d", input+j);
            arr[j].push_back(input[j]);
        }
    for (int i=0; i<4; i++) sort(arr[i].begin(), arr[i].end());

    for (int a=0; a<n; a++)
    {
        int preR_b = 0;
        for (int b=preR_b; b<n; b++)
        {
            int preR=n;
            for (int c=0; c<n; c++)
            {
                long long sum = arr[0][a] + arr[1][b] + arr[2][c];
                int l=0, r=preR, d=-1;
                while (l<r)
                {
                    int mid = (l+r)/2;
                    long long tmp = sum+arr[3][mid];
                    if (tmp < 0) l = mid+1;
                    else if (tmp>0) r = mid;
                    else
                    {
                        preR_b = b;
                        preR = mid;
                        d = mid;
                        break;
                    }
                }
                if (d==-1) continue;
                for (int i=0; d+i<n; i++)
                {
                    if (arr[3][d]==arr[3][d+i]) sol++;
                    else break;
                }
                for (int i=1; 0<=d-i; i++)
                {
                    if (arr[3][d]==arr[3][d-i]) sol++;
                    else break;
                }
            }
        }
    }
    printf("%d\n", sol);
    return 0;
}
