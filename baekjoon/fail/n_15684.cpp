/**
 * 18.12.6. 목요일
 * give up 
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int N, H, M; // N : 세로선, H : 가로점선, M : 가로 선 갯수
bool map[30][10];
int hori_cnt[10];

int ret;

bool chk(int vert, int hori) { return 0<=vert&&vert<N-1&&0<=hori&&hori<H; }

void fullsearch(int vert, int count) {
    if (vert == N-1)  ret = count;
    else if (hori_cnt[vert]%2==0) fullsearch(vert+1, count);
    else if (hori_cnt[vert]%2==1)
    {
        // if (count == 3)
        for (int hori_index=0; hori_index<H; hori_index++)
        {
            if (map[hori_index][vert]) continue;
            if (chk(vert-1, hori_index)) if (map[vert-1][hori_index]) continue;
            if (chk(vert+1, hori_index)) if (map[vert+1][hori_index]) continue;
            map[hori_index][vert] = true;
            hori_cnt[vert]++;
            fullsearch(vert+1, count+1);
            hori_cnt[vert]--;
            map[hori_index][vert] = false;
        }
    }

}

int main(int argc, char const *argv[])
{
    ret = 300;
    scanf("%d %d %d", &N, &M, &H);
    for (int vert_index=0; vert_index<N-1; vert_index++) // 세로선
    {
        for (int hori_index=0; hori_index<H; hori_index++) // 가로선
            map[hori_index][vert_index] = false;
        hori_cnt[vert_index]=0;
    }

    for (int i=0; i<M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a-1][b-1] = true;
        hori_cnt[b-1]++;
    }

    fullsearch(0,0);

    if (ret > 3) printf("-1\n");
    else printf("%d\n", ret);

    return 0;
}
