/**
 * 2019.10.04. 17:06 ~ 17:20
 */
#include <iostream>
#include <string.h>
using namespace std;

typedef struct _test
{
    bool chk[21];
    _test() { empty(); }
    void add(int x) { chk[x] = true; }
    void remove(int x) { chk[x] = false; }
    bool check(int x) { return chk[x]; }
    void toggle(int x) { chk[x] ^= 1; }
    void all() { for (int i=1; i<21; i++) chk[i] = true; }
    void empty() { for (int i=1; i<21; i++) chk[i] = false; }
}test_str;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    test_str tt;
    while (n--)
    {
        string s;
        int i;
        cin >> s;
        if (s == "all") tt.all();
        else if (s == "empty") tt.empty();
        else if (s == "add")
        {
            cin >> i;
            tt.add(i);
        }
        else if (s == "remove")
        {
            cin >> i;
            tt.remove(i);
        }
        else if (s == "check")
        {
            cin >> i;
            cout << tt.check(i) << '\n';
        }
        else if (s == "toggle")
        {
            cin >> i;
            tt.toggle(i);
        }
    }
    return 0;
}
