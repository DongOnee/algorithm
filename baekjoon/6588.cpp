#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1'000'001;

bool isNotPrime[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    
    for (int i = 4; i < MAXN; i += 2) isNotPrime[i] = true;

    for (int i = 3; i < MAXN; i += 2)
    {
        if (!isNotPrime[i])
        {
            for (int j = 2*i; j < MAXN; j += i) isNotPrime[j] = true;
        }
    }


    while (1)
    {
        cin >> n;
        if (n == 0) break;

        int a = 3, b = n - 3;
        while ((isNotPrime[a] || isNotPrime[b]) && a <= b)
        {
            a += 2;
            b = n - a;
        }

        if (a <= b) cout << n << " = " << a << " + " << b << "\n";
        else cout << "Goldbach's conjecture is wrong.";
    }

    return 0;
}
