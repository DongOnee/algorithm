/**
 * DP와 bit-mask 를 이용한 문제이다.
 * 문제 제출을 보면 많은 시도를 하였는데 이유는 다른사람의 코드와 10배 이상의 시간 차이가 있어서 
 * 원인 파악을 위해 많은 시도를 해보았다.
 * 원인은 dp 이중 배열을 선언할때 문제이었다.
 * 같은 값, 의미을 갖는 dp[i][j] 와 dp[j][i] 가 있을때 
 * j 값을 1 더 큰 값으로 이동할때 차이가 난다.
 * dp[10000000][10] 으로 선언한 경우
 * dp[i][j+1] 은 바로 다음 포인터 접근을 하지만
 * dp[10][10000000] 으로 선언한 경우
 * dp[j+1][i] 는 [10000000] 포인터 이동후 접근을 하기 때문에
 * 내부적으로 오래 걸릴 수 밖에 없다.
 * 따라서 아래 dp[1<<15][100] 을 dp[100][1<<15] 로 바꾼후 실행하면
 * 속도 향상을 볼 수 있다.
 * 
 * dp[r][state] : state 비트들을 
 */
#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int n, k, r[15], rp[15];
string arr[15];
ll dp[1<<15][100];

ll gcd(ll a, ll b)
{
    return a?gcd(b%a, a):b;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cin >> k;

    ll par = 1;
    for (int i=0; i<n; i++)
    {
        par *= (i+1);
        rp[i] = 1;
        for (char x : arr[i])
        {
            r[i] = (r[i]*10+x-'0')%k;
            rp[i] = rp[i]*10%k;
        }
    }

    dp[(1<<n)-1][0] = 1;
    for (int passBit = (1<<n)-1; 0<passBit; passBit--)
        for (int i = 0; i<n; i++)
            if ((passBit & (1<<i)))
                for (int kk = 0; kk < k; kk++)
                    dp[passBit ^ (1<<i)][kk] += dp[passBit][(kk*rp[i]+r[i])%k];

    ll son = dp[0][0];

    ll g = gcd(son, par);
    cout << son/g <<'/' << par/g;

    return 0;
}
