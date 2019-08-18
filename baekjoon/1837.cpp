/**
 * 19.4.5.
 */
#include <cstdio>
#include <algorithm>
using namespace std;

char inputChar[110];
bool notPrime[1000003];
int k;

bool calc(int z)
{
    int ret =0;
    for (int i=0; inputChar[i]; i++) ret = (ret*10 + (inputChar[i]-'0')) % z;
    return ret==0;
}

int main(int argc, char const *argv[])
{
    scanf("%s%d", inputChar, &k);
    for (int i=2; i<1000003; i++)
    {
        if (notPrime[i]) continue;
        for (int j=i+i; j<1000003; j+=i) notPrime[j] = true;
    }

    for (int i=2; i<k; i++)
    {
        if (notPrime[i]) continue;
        if (calc(i))
        {
            printf("BAD %d\n", i);
            return 0;
        }
    }
    printf("GOOD\n");
    return 0;
}
