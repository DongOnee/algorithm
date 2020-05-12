/**
 * 2020.05.12. 21:21 ~ 21:33
 * 
 * 흠.. 너무 어렵게 생각하는 병이 돋아 버렸나보다.
 * fail 디렉토리를 보면 엄청난 똥꼬 쇼를 한게 보인다. 일일이 다 구하려고 한게 화근이었다.
 * 
 * 문제가 무엇을 원하는지 유추해보았다.
 * 일일이 계산하는것은 바라는게 아닐거란 말이다.
 * 
 * nCm 을 공식으로 하면 n!/{m!(n-m)!} 이다. 
 * 그리고 0의 개수를 구하는데, 그 말은 즉 10이 몇번 곱해지냐 이다.
 * 10을 만드려면, 2*5 이면 된다.
 * 따라서 분모, 분자의 2, 5 의 개수를 구한 후
 * 나눗셈이니까 각각 빼준다음
 * 그중 작은걸 답으로 하면 된다.
 */
#include <iostream>
#include <algorithm>

using namespace std;

int n, nn, m, mm, n_m, nn_mm;
int n2, n5, m2, m5;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    nn = n;
    mm = m;
    n_m = n-m;
    nn_mm = n_m;

    while (n)
    {
        n /= 2;
        n2 += n;
    }
    while (nn)
    {
        nn /= 5;
        n5 += nn;
    }

    while (m)
    {
        m /= 2;
        m2 += m;
    }
    while (mm)
    {
        mm /= 5;
        m5 += mm;
    }

    while (n_m)
    {
        n_m /= 2;
        m2 += n_m;
    }
    while (nn_mm)
    {
        nn_mm /= 5;
        m5 += nn_mm;
    }

    // cout << n2 << '\t' << n5 << '\t' << m2 << '\t' << m5 << '\n';
    // cout << n2-m2 << '\t' << n5-m5 << '\n';
    cout << min(n2-m2, n5-m5) << '\n';

    return 0;
}
