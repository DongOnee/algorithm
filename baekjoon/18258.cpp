/**
 * 기본적인 큐에 대한 문제이다.
 * 
 * string 비교하는 것에 대해서 알 수 있엇다.
 */
#include <iostream>
#include <string>

using namespace std;

int qu[2000000];
int fidx, tidx;

void command()
{
    string cmd;
    cin >> cmd;
    
    if (cmd == "push")
    {
        int a; cin >> a;
        qu[tidx++] = a;
    }
    else if (cmd == "pop")
        cout << (fidx==tidx?-1:qu[fidx++]) << '\n';
    else if (cmd == "front")
        cout << (fidx==tidx?-1:qu[fidx]) << '\n';
    else if (cmd == "back")
        cout << (fidx==tidx?-1:qu[tidx-1]) << '\n';
    else if (cmd == "size")
        cout << tidx - fidx << '\n';
    else if (cmd == "empty")
        cout << ((tidx == fidx)?1:0) << '\n';
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    while (n--)
        command();

    return 0;
}
