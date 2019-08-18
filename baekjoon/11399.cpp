/**
 * 19.1.4.
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int N, p[1000];

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &p[i]);
    sort(p, p+N);
    int sol=0;
    for (int i=0; i<N; i++) sol += (N-i)*p[i];
    printf("%d\n", sol);
    
    return 0;
}
