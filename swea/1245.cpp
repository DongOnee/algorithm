/**
 * 19.3.24.
 */
#include <cstdio>
#include <utility>
#include <math.h>
#include <algorithm>
using namespace std;

int n, point[10], m[10];

int main(int argc, char const *argv[])
{
    int T; scanf("%d", &T);
    for (int tc=0; tc<T; tc++)
    {
        scanf("%d", &n);
        for (int i=0; i<n; i++) scanf("%d", point+i);
        sort(point, point+n);
        for (int i=0; i<n; i++) scanf("%d", m+i);

        printf("#%d ", tc+1);

        for (int i=0; i<n-1; i++)
        {
            pair<int, int> left = {point[i], m[i]};
            pair<int, int> right = {point[i+1], m[i+1]};

            double sol = 0.0;
            int a = 

            printf("%.10f ", left.first + sol);
        }
        printf("\n");
    }
    return 0;
}


