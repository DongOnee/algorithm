/**
 * 18.12.30.
 */
#include <cstdio>

bool visit[10001];
bool prime[10001];

bool chk_prime(int num) {
    if (visit[num]) return prime[num];
    visit[num] = true;
    for (int i=2; i*i<=num; i++)
        if (num%i == 0) return false;
    prime[num]=true;
    return true;
}

int main(int argc, char const *argv[])
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int input; scanf("%d", &input);

        int a=1, b=input-1;
        for (int i=2; 2*i<=input; i++)
        {
            if (chk_prime(i))
            {
                if (chk_prime(input-i))
                {
                    if (a<i) a=i, b=input-i;
                }
            }
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}
