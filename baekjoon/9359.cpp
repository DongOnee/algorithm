#include <cstdio>
#include <map>
#include <vector>
using namespace std;
#define MAXN 1000000000LL
#define MAXROOTN 31624

typedef long long ll;

ll a, b, n, ans;
ll factors[12];
int cntFactors;

vector<int> primes;
bool notPrime[MAXROOTN];

ll calc(ll input, bool isOverlap, int idx)
{
    ll ret = 0;

    for (; idx<cntFactors; idx++) ret += calc(input * factors[idx], !isOverlap, idx+1);
    ret += (isOverlap?-1:1) * (b/input - (a-1)/input);
    
    return ret;
}

void run()
{
    for (int i=0; i<cntFactors; i++) ans += calc(factors[i], true, i+1);
}

void getPrimeFactorization(ll input)
{
    for (auto primeNum : primes)
    {
        if (input % primeNum == 0)
        {
            factors[cntFactors++] = primeNum;
            while (input % primeNum == 0) input /= primeNum; 
        }
        if (input == 1) break;
    }
    if (input != 1) factors[cntFactors++] = input;
}

void init()
{
    scanf("%lld%lld%lld", &a, &b, &n);
    ans = b - a + 1;
    cntFactors = 0;
    getPrimeFactorization(n);
}

int main(int argc, char const *argv[])
{
    for (int i=2; i<MAXROOTN; i++)
    {
        if (!notPrime[i]) 
        {
            primes.push_back(i);
            for (int ii=i; ii<MAXROOTN; ii += i) notPrime[ii] = true;
        }
    }

    // freopen("9359_input.txt", "r", stdin);
    int tc; scanf("%d", &tc);
    for (int test_case=1; test_case<=tc; test_case++)
    {
        init();

        if (n != 1) run();

        printf("Case #%d: %lld\n", test_case, ans);
    }
    return 0;
}
