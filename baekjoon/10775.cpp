// 엄청난 시간... 맞았습니다 나오긴한다.
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

vector<int> cmds;
vector<int> sections;
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
        vector<int>::iterator itr = lower_bound(sections.begin(), sections.end(), -x);
        if (itr == sections.end()) break;
        sections.erase(itr);
        ans++;
    }

    printf("%d\n", ans);

    return 0;
}