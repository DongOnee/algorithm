#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1'000'000;
const int INF = 1'000'000'000;

int n, arr[MAXN + 1];
vector<int> vt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vt.push_back(-INF - 1);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        if (vt.back() < arr[i]) {
            vt.push_back(arr[i]);
        }
        else {
            *(lower_bound(vt.begin(), vt.end(), arr[i])) = arr[i];
        }
    }

    cout << vt.size() -1 << '\n';

    return 0;
}


