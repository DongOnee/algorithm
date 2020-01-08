#include <cstdio>
#define MOD 10007

int n, k, answer;
int factorials[1001];

int fact(int input)
{
    if (factorials[input] == 0) return factorials[input] = ( input * fact(input-1) ) % MOD;
    return factorials[input];
}

int multiple(int input, int p)
{
    if (input == 1) return 1;
    int ans = 1, mul = input;
    while (p)
    {
        if (p % 2) ans *= mul;
        
        p >>= 1;
        mul *= mul;
        mul %= MOD;
        ans %= MOD;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    factorials[0] = 1, factorials[1] = 1, factorials[2] = 2;
    scanf("%d%d", &n, &k);

    answer = fact(n);
    answer *= multiple(fact(k), MOD-2);
    answer %= MOD;
    answer *= multiple(fact(n-k), MOD-2);
    answer %= MOD;

    printf("%d\n", answer);
    return 0;
}
