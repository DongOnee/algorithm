#include <iostream>
#include <string>
using namespace std;
#define MAXA 10000

int ans[MAXA+1];
string a, b;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    long aa = a.size(), bb = b.size();
    int tm = 1;
    while (true)
    {
        bool carry = false;
        int aaa = (aa<tm?0:a[aa-tm]-'0'), bbb = (bb<tm?0:b[bb-tm]-'0');
        if (aa < tm && bb < tm) 
        {
            if (ans[tm] == 1) tm++;
            break;
        }
        
        ans[tm] += aaa+bbb;
        if (ans[tm] >= 10)
        {
            ans[tm+1] += ans[tm]/10;
            ans[tm] %= 10;
        }
        tm++;
    }

    while (tm>1) cout << ans[--tm];

    return 0;
}
