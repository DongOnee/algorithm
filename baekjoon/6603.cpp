/**
 * 19.4.12.
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int n, arr[14];

int main(int argc, char const *argv[])
{
    while (true)
    {
        scanf("%d", &n);
        if (n==0) break;
        for (int i=0; i<n; i++) scanf("%d", arr+i);
        sort(arr, arr+n);

        for (int a=0; a<n; a++)
            for (int b=a+1; b<n; b++) 
                for (int c=b+1; c<n; c++) 
                    for (int e=c+1; e<n; e++) 
                        for (int f=e+1; f<n; f++) 
                            for (int g=f+1; g<n; g++) printf("%d %d %d %d %d %d\n", arr[a], arr[b], arr[c], arr[e], arr[f], arr[g]);
        printf("\n");
    }
    return 0;
}
