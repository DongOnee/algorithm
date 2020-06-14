/**
 * 2020.06.14. 12:06 ~ 12:30
 * next_permutation 을 사용한거 말고는 특별한거 없다.
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int candidate[5] = {0, 0, 0, 0, 0};
int selected[5] = {0, 0, 1, 1, 1};

int gcd(int a, int b)
{
    return (a == 0?b:gcd(b%a, a));
}

int main(int argc, const char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    for (int i=0; i<5; i++)
    {
        cin >> candidate[i];
    }

    int ans = 98765432;

    do
    {
        int ret = 1;
        for (int i=0; i<5; i++)
        {
            if (selected[i] == 0) continue;
            int gcdValue = gcd(ret, candidate[i]);
            ret = ret * candidate[i] / gcdValue;
        }

        ans = min(ans, ret); 
    } while (next_permutation(begin(selected), end(selected)));

    cout << ans << '\n';

    return 0;
}
