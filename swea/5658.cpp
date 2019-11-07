#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, ans;
char tmp, inputs[30];
vector<int> vt;

void prep()
{
    vt.clear();
    scanf("%d%d%s", &n, &k, inputs);
}

void run()
{
    int len = n/4;
    for (int ptrStart = 0; ptrStart < len; ptrStart++)
    {
        int ret = 0;
        for (int i=0; i<n; i++)
        {
            int c = inputs[(i+ptrStart)%n];

            if (c >= 'A') c = c - 'A' + 10;
            else c -= '0';
            ret += c;

            if ((i+1)%len == 0)
            {
                bool flag = true;
                for (int x : vt) if (x == ret) 
                {
                    flag = false;
                    break;
                }
                if (flag) vt.push_back(ret);
                ret = 0;
            }
            else ret  <<= 4;
        }
    }
    sort(vt.rbegin(), vt.rend());
    ans = vt[k-1];
}

int main(int argc, char const *argv[])
{
    // freopen("5658_input.txt", "r", stdin);
    int t; scanf("%d", &t);
    for (int test_case=1; test_case<=t; test_case++)
    {
        prep();
        run();
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
