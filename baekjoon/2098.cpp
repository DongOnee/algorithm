/**
 * DP 와 bit-mask 를 이용한 문제이다.
 * dp[i][k] : k 비트에 있는 모든 노드들을 순회한 후 i 노드에 있을때,
 *          나머지 노드들을 모두 순회한 후 0 으로 돌아올때 비용
 *          = min(j:i 와 연결된 모든 노드들) (cost[i][j] + dp[j][k | (1<<j)])
 *            : i 에서 j 로 순회 후, ... j 노드에 있을때 ....
 * 시작노드, 메인문에 있는 cout << ??? 부분, 에는 아무것이나 와도됨.
 * 결과는 동일함!!
 * 모든 노드를 순회하고 처음 시작하는 노드로 돌아온다고 했을때 경로는 원 으로 나타낼 수 있음.
 * 모든 노드를 순회하는 경로, 그러니까 원이 여러개 있다고 했을때,
 * 가장 짧은, 비용이 적은, 총 코스트 합이 적은 원은 단 하나.
 * 따라서 그 원의 어느 노드에서 시작하여도 상관 없이 최소를 구하게 되면 결국 그 원, 그 순회 경로가 나옴.
 *  -->   cout << run(7, (1<<7)) << '\n'; 이런식으로 해도 된다는말!
 * 하지만 n 이 8보다 작아버리면 문제가 생기기 때문에~ 0으로 하는게 좋다.
 */

#include <iostream>
#include <algorithm>

using namespace std;

#define INF 16'000'001

int n;
int cost[16][16];
int dp[16][1<<16];

/**
 * @brief dp값을 재귀 함수를 이용해 구하기 위한 함수 이다.
 * @return dp[cur][passedBit]을 (만들어) 리턴해준다.
 * @param cur 찾고자 하는 노드 인덱스
 * @param passedBit 이미 지나간 노드들을 bit 활성화 시킨 값
 */
int run(int cur, int passedBit)
{
    if (passedBit == (1<<n) -1) return dp[cur][passedBit] + (cost[cur][0]==0?INF:cost[cur][0]);
    int& ret = dp[cur][passedBit];
    if (ret > 0) return ret;
    ret = INF;
    for (int i=0; i<n; i++)
        if ( !((1 << i) & passedBit) && cost[cur][i] > 0)
            ret = min(ret, run(i, passedBit | (1<<i)) + cost[cur][i]);
    return ret;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> cost[i][j];

    cout << run(0, 1) << '\n';

    return 0;
}
