#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    bool isPrime[1000001];
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2; i<=M; i++) isPrime[i] = true;
    for(int i=2; i<=M; i++)
    {
        if(isPrime[i])
        {
            if (1000001 < (unsigned int) pow(i, 2) ) break;
            int j = i*i;
            while (j<=M)
            {
                isPrime[j] = false;
                j+=i;
            }
        }
    }
    for (int i=N; i<=M; i++) if(isPrime[i]) printf("%d\n", i);

    return 0;
}