#include <iostream>
#include <list>
#include <string>
using namespace std;

list<string> lst;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    while (n--)
    {
        string name, cmd;
        cin >> name >> cmd;
        if (cmd == "enter") lst.push_back(name);
        else lst.remove(name);
    }

    return 0;
}
