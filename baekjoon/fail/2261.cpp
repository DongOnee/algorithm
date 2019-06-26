/**
 * 19.2.26.
 * ref. https://mygumi.tistory.com/294
 */
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, int> POINT;

queue<POINT> q;
POINT pt[100000];
int N;

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d %d", &pt[i].first, &pt[i].second);

    sort(pt, pt+N);

    q.push(make_pair(0, 1));
    
    
    return 0;
}
