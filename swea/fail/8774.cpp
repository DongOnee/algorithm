#include <iostream>
#include <vector>
using namespace std;

#define MOD 1'000'000'007

vector<int> fib = {0, 1, 1};
vector<int> b = {1, 1, 2};

int main(int argc, char const *argv[])
{
    int T; cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case)
    {
        int n; cin >> n;
        
        if (fib.size() <= n)
        {
            for (int idx=fib.size(); idx <= n; ++idx)
            {
                fib.push_back(fib[idx-1] + fib[idx-2]);
                long long b_idx;
                for (int fib_idx = 1; fib_idx <= idx; ++fib_idx)
                    b_idx += (b[idx-fib_idx]*(fib[fib_idx]*fib[fib_idx]) % MOD)% MOD;
                b.push_back(b_idx);
            }
        }
        cout << b[n] << endl;
    }
    return 0;
}
