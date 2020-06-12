/**
 * 2020.06.12. 20:17 ~ 22:26
 * 굉장히 쉬운 문제
 */
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, f;
    cin >> n >> f;
   
    n = (n / 100) * 100;
    int rem = n % f;
    rem = rem==0?0:(f - rem);

    if (rem < 10) cout << '0';
    cout << rem << '\n';

    return 0;
}
