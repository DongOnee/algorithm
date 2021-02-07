#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1'000;
const int MAXA = 1'000;

int n;
vector<int> arr, cnt, prevIdx;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        arr.emplace_back();
        cin >> arr.back();
        cnt.push_back(1);
        prevIdx.push_back(i);

        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i] && cnt[j] >= cnt[i]) {
                cnt[i] = cnt[j] + 1;
                prevIdx[i] = j;
            }
        }
    }

    int ansCnt = 0, ansIdx = -1;
    for (int i = 0; i < n; ++i) {
        if (ansCnt < cnt[i]) {
            ansIdx = i;
            ansCnt = cnt[i];
        }
    }

    cout << ansCnt << '\n';

    vector<int> answerVector;
    while (ansIdx != prevIdx[ansIdx]) {
        answerVector.push_back(arr[ansIdx]);
        ansIdx = prevIdx[ansIdx];
    }

    cout << arr[ansIdx] << ' ';
    while (false == answerVector.empty()) {
        cout << answerVector.back() << ' ';
        answerVector.pop_back();
    }

    return 0;
}
