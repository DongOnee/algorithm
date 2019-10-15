#include <cstdio>
#include <cstring>

int n, m, t;
int locDVD[100001], tree[200001];

void update(int idx, int val)
{
    while (idx < 200001)
    {
        // printf("idx : %d\n", idx);
        tree[idx] += val;
        idx += idx&(-idx);
    }
}

int query(int idx)
{
    int ret = 0;
    while (idx>0)
    {
        ret += tree[idx];
        idx -= idx&(-idx);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        memset(locDVD, 0, sizeof(locDVD));
        memset(tree, 0, sizeof(tree));
        scanf("%d%d", &n, &m);
        for (int i=1; i<=n; i++)
        {
            locDVD[i] = i + m;
            update(i+m, 1);
        }
        for (int i=0, a; i<m; i++)
        {
            scanf("%d", &a);
            printf("%d ", query(locDVD[a]-1));
            update(locDVD[a], -1);
            locDVD[a] = m - i;
            update(locDVD[a], 1);
        }
    }
    return 0;
}
