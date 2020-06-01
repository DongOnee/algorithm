#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for (int i=1; i<=n; i++) dq.push_back(i);

    while (--n)
    {
        dq.pop_front();
        int a = dq.front();
        dq.pop_front();
        dq.push_back(a);
    }

    cout << dq.front() << endl;

    return 0;
}
