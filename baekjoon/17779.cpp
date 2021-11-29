/**
 * 2020.09.01.
 */
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 20;
const int MAXDEF = 0x7fffffff;

int n, board[MAXN][MAXN];
int x, y, d1, d2, total;

int sum1area() {
    int ret = 0;
    for (int i = 0; i < x + d1; i++) {
        for (int j = 0; j <= y; j++) {
            if ( i + j < x + y ) ret += board[i][j];
        }
    }

    return ret;
}

int sum2area() {
    int ret = 0;
    for (int i = 0; i <= x + d2; i++) {
        for (int j = y + 1; j < n; j++) {
            if ( y - x < j - i ) ret += board[i][j];
        }
    }

    return ret;
}

int sum3area() {
    int ret = 0;
    for (int i = x + d1; i < n; i++) {
        for (int j = 0; j < y - d1 + d2; j++) {
            if ( i - j > x - y + 2 * d1 ) ret += board[i][j];
        }
    }

    return ret;
}

int sum4area() {
    int ret = 0;
    for (int i = x + d2 + 1; i < n; i++) {
        for (int j = y - d1 + d2; j < n; j++) {
            if ( i + j > x + y + 2 * d2 ) ret += board[i][j];
        }
    }

    return ret;
}

int run() {
    d1 = 1;
    d2 = 1;
    if (n <= x + d1 + d2 || y-d1 < 0 || n <= y + d2) return MAXDEF;
    
    int ret = MAXDEF;
    for (; 0 <= y - d1; d1++) {
        for (d2 = 1; y + d2 < n; d2++) {
            if (n <= x + d1 + d2 || y-d1 < 0 || n <= y + d2) continue;
            int sum1 = sum1area(); 
            int sum2 = sum2area();
            int sum3 = sum3area();
            int sum4 = sum4area();
            int sum5 = total - sum1 - sum2 - sum3 - sum4;
            int maxSum = max(sum1, max(sum2, max(sum3, max(sum4, sum5))));
            int minSum = min(sum1, min(sum2, min(sum3, min(sum4, sum5))));
            ret = min(ret, maxSum - minSum);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> board[i][j];
            total += board[i][j];
        }
    }

    int answer = MAXDEF;
    for ( x = 1; x < n - 1; x++) {
        for ( y = 1; y < n - 1; y++) {
            int ret = run();
            answer = min(answer, ret);
        }
    }
    cout << answer << "\n";

    return 0;
}
