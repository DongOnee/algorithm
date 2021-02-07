#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int const MINA = -1'000'000'001;

int n;
vector<int> arr,  position, sequence;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sequence.push_back(MINA);

    cin >> n;
    arr.resize(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        
        if (sequence.back() < arr[i]) {
            position.push_back(sequence.size());
            sequence.push_back(arr[i]);
        }
        else {
            auto itr = lower_bound(sequence.begin(), sequence.end(), arr[i]);
            *itr = arr[i];
            position.push_back(itr - sequence.begin());
        }
    }

    int seqIdx = sequence.size();

    cout << --seqIdx << '\n';

    vector<int> ansSeq;
    for (int i = n - 1; 0 <= i && 0 < seqIdx; --i) {
        if (position[i] == seqIdx) {
            seqIdx--;
            ansSeq.push_back(arr[i]);
        }
    }

    for (int i = ansSeq.size() - 1; 0<= i; --i) {
        cout << ansSeq[i] << ' ';
    }

    return 0;
}
