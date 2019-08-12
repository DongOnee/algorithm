#include <iostream>
#include <utility>
using namespace std;

typedef pair<int, int> pii;

pii arr[16];

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    if (n%2 == 1) cout << "0\n";
    else
    {
        arr[1] = {2, 1};
        n /= 2;
        for (int i=2; i<=n; i++)
        {
            arr[i] = {2*(arr[i-1].first + arr[i-1].second) + arr[i-1].first, (arr[i-1].first + arr[i-1].second)};
        }
        cout << arr[n].first + arr[n].second << '\n';
    }
    
    return 0;
}
