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
    while (T--)
    {
        int input; scanf("%d", &input);

        int mult = input;
        for (int i=2; mult!=1; i++)
        {
            if (mult%i == 0)
            {
                mult /= i;
                int count=1;
                while ( mult%i == 0)
                {
                    count++;
                    mult/=i;
                }
                printf("%d %d\n", i, count);
            }
        }
    }
    return 0;
}
