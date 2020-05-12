/**
 * 2020.05.12. 20:29 ~ 20:54
 * 쉬운 문제... 하지만 출력을 삼성 코테 처럼 출력해서 실패가 많이 떳다.
 * sol 함수의 출력, 그러니까 GCD 의 합을 int 로 바꾸어 제출 해 보았다.
 * 최대의 경우를 구해보면, n = 100 일때 총 4950 개의 쌍이 나오고
 * 가장큰 GCD 는 1,000,000 이다. (모든 값이 1,000,000 으로 세팅되었을 경우)
 * 그래서 sol 의 ret 이 가질 수 있는 값의 최대 값은 4,950,000,000 이 나오는데
 * 이 값은 int 가 허용하는 범위를 넘어버린다
 * 
 * 그래서 long long 을 사용해서 해결 하였다.
 */
#include <iostream>

using namespace std;

typedef long long ll;

int arr[100], n;

int gcd(int a, int b)
{
    return a == 0 ? b : gcd(b%a, a);
}

int sol()
{
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> arr[i];
    
    int ret = 0;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            ret += gcd(arr[i], arr[j]);

    return ret;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    for (int test_case = 1; test_case <= tc; test_case++)
    {
        cout << sol() << '\n';
    }
    return 0;
}
