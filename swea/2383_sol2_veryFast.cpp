#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
 
#define INF 1000

typedef struct _stair
{
    int x, y, k;
}stair_info;

typedef struct _person {
    int x, y;
    int dist_a, dist_b;
}person_info;

int n, ans, A[15][2], B[15][2], cnt, r;
bool check[15];
stair_info stair[2];
person_info person[10];
 
void dfs(int l, int last, int a_cnt, int b_cnt)
{   
    int max = 0;
    if (l >= last)
    {
        if (a_cnt == 0) max = B[b_cnt-1][1];
        else if (b_cnt == 0) max = A[a_cnt-1][1];
        else max = (A[a_cnt - 1][1] > B[b_cnt - 1][1] ? A[a_cnt - 1][1] : B[b_cnt - 1][1]);
        ans = min(ans, max);

        return;
    }

    // 0 번 출구로 가는 경우 구하기
    int idx = 0, dist = INF;
    for (int i = 0; i < last; i++) 
    {
        if ((person[i].dist_a <= dist) && !check[i]) 
        {
            dist = person[i].dist_a;
            A[a_cnt][0] = person[i].dist_a;
            A[a_cnt][1] = person[i].dist_a + stair[0].k + 1; // 계단입구 ~ 계단끝까지 시간
            idx = i;
        }
    }
    check[idx] = true;// 해당인덱스 
    if (a_cnt >= 3) 
    {
        if (A[a_cnt - 3][0] == A[a_cnt][0]) A[a_cnt][0] += 1;
        else if (A[a_cnt - 3][0] > A[a_cnt][0]) A[a_cnt][0] = A[a_cnt - 3][0] + 1;
        if (A[a_cnt - 3][1] > A[a_cnt][0]) A[a_cnt][1] = A[a_cnt - 3][1] + stair[0].k , A[a_cnt][0] = A[a_cnt - 3][1];
    }
    dfs(l + 1, last, a_cnt + 1, b_cnt);
    check[idx] = false;

    // 1 번 출구로 가는 경우 구하기
    dist = INF;
    for (int i = 0; i < last; i++) {
        if ((person[i].dist_b <= dist) && !check[i]) {
            dist = person[i].dist_b;
            B[b_cnt][0] = person[i].dist_b;
            B[b_cnt][1] = person[i].dist_b + stair[1].k + 1; //계단입구, 계단끝까지 시간
            idx = i;
        }
    }
    check[idx] = true;
    if(b_cnt>=3)
    {
        if (B[b_cnt - 3][0] == B[b_cnt][0]) B[b_cnt][0] += 1;
        else if (B[b_cnt - 3][0] > B[b_cnt][0]) B[b_cnt][0] = B[b_cnt - 3][0] + 1;
        if (B[b_cnt - 3][1] > B[b_cnt][0]) B[b_cnt][1] = B[b_cnt - 3][1] + stair[1].k, B[b_cnt][0] = B[b_cnt - 3][1];
    }
    dfs(l + 1, last, a_cnt, b_cnt + 1);
    check[idx] = false;
}

void init()
{
    scanf("%d", &n);
    cnt = 0, r = 0, ans = INF;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0, value; j < n; j++) 
        {
            scanf("%d", &value);
            if (value == 1) person[cnt++] = {i, j, 0, 0};
            if (value > 1) stair[r++] = {i, j, value};
        }
    }

    for (int i = 0; i < cnt; i++) 
    {
        person[i].dist_a = abs(person[i].x - stair[0].x) + abs(person[i].y - stair[0].y);
        person[i].dist_b = abs(person[i].x - stair[1].x) + abs(person[i].y - stair[1].y);
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int test_case = 1; test_case <= t; test_case++) 
    {
        init();
        dfs(0, cnt, 0, 0);
        
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}