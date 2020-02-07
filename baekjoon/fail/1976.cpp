#include <cstdio>
#include <vector>
using namespace std;

int n, m;
int map[200][200];
vector<bool> trip;

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%d", map[i]+j);
    for (int i=0, input; i<m; i++)
    {
        scanf("%d", &input);
        trip.push_back(input);
    }

    for (int k=0; k<n; k++) for (int i=0; i<n; i++) for (int j=0; j<n; j++) if(map[i][k] & map[k][j]) map[i][j] = true;

    int prev = trip[0];
    bool ret = true;
    for (int i=1; i<m; i++)
    {
        if (!map[prev][i])
        {
            ret = false;
            break;
        }
        prev = i;
    }

    printf("%s\n", ret?"YES":"NO");

    return 0;
}
