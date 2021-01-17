#include <iostream>

using namespace std;

typedef long long ll;

const int MAXAPP = 1'000'000;

ll roomCount;
ll appliCount[MAXAPP];
ll chief, sub;
ll ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> roomCount;
    for (int i = 0;  i < roomCount; ++i)
        cin >> appliCount[i];
    cin >> chief >> sub;

    for (int i = 0;  i < roomCount; ++i)
    {
        auto& remain = appliCount[i];
        remain -= chief;
        if (remain > 0)
        {
            remain += sub - 1;
            ans += remain / sub;
        }
    }

    cout << ans + roomCount << '\n';

    return 0;
}
