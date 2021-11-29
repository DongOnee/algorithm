/**
 * 2020.08.05. 13:49 ~
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXQ = 5001;

int n, q;
int board[MAXQ][MAXQ];
bool visited[MAXQ];

int sol(int k, int v) {
    int ret = 0;
    // initialize
    for (int i = 1; i <= n; ++i) {
        visited[i] = false;
    }

    // loof
    priority_queue<pair<int, int>> pq;
    pq.push({0, v});
    while (false == pq.empty()) {
        int currentUSADO = -pq.top().first;
        int currentVideoIndex = pq.top().second;
        pq.pop();

        if (true == visited[currentVideoIndex]) {
            continue;
        }
        visited[currentVideoIndex] = true;

        if (k < currentUSADO) {
            ret++;
        }
        for (int i = 1; i <= n; i++) {
            if (false == visited[i] && 0 < board[currentVideoIndex][i]) {
                pq.push({ -(currentUSADO + board[currentVideoIndex][i]), i});
            }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1, a, b, r; i < n; i++) {
        cin >> a >> b >> r;
        board[a][b] = r;
        board[b][a] = r;
    }

    for (int i=0, k, v; i<q; i++) {
        cin >> k >> v;
        cout << sol(k, v) << endl; 
        // videos[k].emplace_back(v);
    }
    
    return 0;
}
