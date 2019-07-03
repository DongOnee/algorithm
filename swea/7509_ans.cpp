#include <bits/stdc++.h>

// divide and conquer + floyd - warshall

using namespace std;

const int SZ = 1 << 14;
int H, W, Q, C[10000][3];
long long tree[2 * SZ][9], L[10000], R[10000];

// t 배열에다가 a 와 b 를 연결...?
void combine(long long * t, long long * a, long long * b)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            t[i * 3 + j] = 0x7fffffffffffffffLL;
            for (int k = 0; k < 3; k++) t[i * 3 + j] = min(t[i * 3 + j], a[i * 3 + k] + b[k * 3 + j]);
            // t[i*3 + j] : t 배열에서 i 행에서 j 행까지 가는 최단거리?
        }
}

void get_min(long long * ret, int s, int e)
{
    cout << "get_min function" << endl;
    static long long r1[9], r2[9], temp[9];
    for (int i = 0; i < 9; i++) r1[i] = r2[i] = (i % 3 == i / 3 ? 0 : 0x3fffffffffffffffLL);
    for (s += SZ, e += SZ; s <= e; s >>= 1, e >>= 1)
    {
        printf(" s: %6d\t e: %6d\t~e: %6d", s, e, ~e);
        if (s & 1)
        {
            combine(temp, r1, tree[s]);
            for (int i = 0; i < 9; i++) r1[i] = temp[i];
            s++;
        }
        if (~e & 1)
        {
            combine(temp, tree[e], r2);
            for (int i = 0; i < 9; i++) r2[i] = temp[i];
            e--;
        }
        printf(" =>  s: %6d\t e: %6d\t~e: %6d\n", s, e, ~e);
    }
    combine(ret, r1, r2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	freopen("input_7509_2.txt", "r", stdin);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        long long ans = 0;
        cin >> H >> W >> Q;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++) cin >> C[i][j];
            for (int j = W; j < 3; j++) C[i][j] = 0x7fffffff;

            for (int j = 0; j < 3; j++)
                for (int k = j; k < 3; k++)
                {
                    tree[SZ + i][j * 3 + k] = 0;
                    for (int l = j; l <= k; l++) tree[SZ + i][j * 3 + k] += C[i][l];

                    tree[SZ + i][k * 3 + j] = tree[SZ + i][j * 3 + k];
                }
        }

        if (W == 3)
        {
            // ㄷ 자 모양으로 y0 에ㅓ y2로 이동할 경우.
            L[0] = C[0][0] + C[0][1] + C[0][2];
            for (int i = 1; i < H; i++) L[i] = min(L[i - 1], 1LL * C[i][1]) + C[i][0] + C[i][2];
            R[H - 1] = C[H - 1][0] + C[H - 1][1] + C[H - 1][2];
            for (int i = H - 2; i >= 0; i--) R[i] = min(R[i + 1], 1LL * C[i][1]) + C[i][0] + C[i][2];
        }

        for (int n = SZ - 1; n; n--) combine(tree[n], tree[2 * n], tree[2 * n + 1]);
        while (Q--)
        {
            int x1, y1, x2, y2;
            long long res;
            static long long temp[9];
            cin >> x1 >> y1 >> x2 >> y2;
            if (--x1 > --x2) swap(x1, x2), swap(y1, y2);
            get_min(temp, x1, x2);
            res = temp[--y1 * 3 + --y2];
            if (W == 3)
            {
                cout << "res : " << res << endl;
                if (y1 != 1 && y2 != 1) res = min(res, temp[(2 - y1) * 3 + (2 - y2)] + L[x1] - C[x1][2 - y1] + R[x2] - C[x2][2 - y2]);
                if (y1 != 1) res = min(res, temp[(2 - y1) * 3 + y2] + L[x1] - C[x1][2 - y1]);
                if (y2 != 1) res = min(res, temp[y1 * 3 + 2 - y2] + R[x2] - C[x2][2 - y2]);
                cout << "res : " << res << endl;
            }
            ans += res;
        }
        cout << '#' << t + 1 << ' ' << ans << '\n';
    }
    return 0;
}

/*

3
5 2 4
0 1
0 1
0 0
1 0
1 0
1 1 5 2
1 2 5 1
3 1 3 2
5 1 1 1
6 3 5
1 9 2
3 4 1
2 5 3
4 2 2
3 1 5
2 6 3
1 1 1 3
1 1 6 3
6 1 6 3
3 1 4 3
6 2 2 3
5 3 4
0 1 0
0 1 0
0 1 0
0 1 0
0 0 0
1 1 1 3
1 1 5 3
3 1 3 3
5 1 1 3
 */