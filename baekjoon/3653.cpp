#include <cstdio>
#include <cstring>

#define MAX_N 100000
#define MAX_M 100000

int n, m;
int idxBook[MAX_N + 1], seg[8*MAX_N];

// pos 에 val 을 넣으면 x~y 의 범위의 값을 의미하는 seg[idxSeg] 를 업데이트?
int update(int pos, int val, int idxSeg, int x, int y)
{
    if (y < pos || pos < x) return seg[idxSeg];
    if (x == y) return seg[idxSeg] = val;
    int mid = (x + y) >> 1;
    return seg[idxSeg] = update(pos, val, idxSeg * 2, x, mid) + update(pos, val, idxSeg * 2 + 1, mid+1, y);
}

// l~r 까지의 합을 구하는데 x~y의 합은 seg[idxSeg] 이다.
int query(int l, int r, int idxSeg, int x, int y)
{
    if (y < l || r < x) return 0;
    if (l <= x && y <= r) return seg[idxSeg];
    int mid = (x + y) >> 1;
    return query(l, r, idxSeg * 2, x, mid) + query(l, r, idxSeg * 2 + 1, mid + 1, y);
}

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(idxBook, 0, sizeof(idxBook));
        memset(seg, 0, sizeof(seg));
        scanf("%d%d", &n, &m);

        int idx = m + 1;
        for (int i = idx; i <= m + n; i++)
        {
            update(i, 1, 1, 1, n + m);
            idxBook[i - m] = i;
        }

        // for (int i = idx; i <= m + m; i++) printf("seg[%d] : %d idxBook[%d] : %d\n", i, seg[i], i - m, idxBook[i - m]);

        for (int i=0, a; i<m; i++)
        {
            scanf("%d", &a);
            printf("%d ", query(1, idxBook[a]-1, 1, 1, n + m));
            update(idxBook[a], 0, 1, 1, n + m);
            idxBook[a] = --idx;
            update(idx, 1, 1, 1, n + m);
        }
        printf("\n");
    }

    return 0;
}
