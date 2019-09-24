// 시간을 줄여보기 위해서 list 를 이용해서 erase 의 효율을 올려주는것을 도모했으나,
// random access 가 안되서 시간 초과가 나오는것 같다.
#include <cstdio>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

typedef pair<int, int> pii;

vector<int> cmds;
list<int> sections;
int g, p;

int main(int argc, char const *argv[])
{
    scanf("%d%d", &g, &p);

    for (int i=0; i<g; i++) sections.push_back(i-g);
    for (int i=0, input; i<p; i++)
    {
        scanf("%d", &input);
        cmds.push_back(input);
    }

    int ans = 0;
    for (int x : cmds)
    {
        list<int>::iterator itr = lower_bound(sections.begin(), sections.end(), -x);
        if (itr == sections.end()) break;
        sections.erase(itr);

        ans++;
    }

    printf("%d\n", ans);

    return 0;
}