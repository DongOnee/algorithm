/**
 * 19.4.9. 16:18~17:08
 */
#include <cstdio>
#include <deque>
#include <utility>
using namespace std;

int n, m, k, a[11][11];
deque<pair<int, pair<int, int>>> trees;
int feed[11][11];

int dir[8][2] = { {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0} };

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<n; }

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++)
    {
        scanf("%d", a[i]+j);
        feed[i][j] = 5;
    }
    for (int i=0, x, y, z; i<m; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        trees.push_back(make_pair(z, make_pair(x-1, y-1)));
    }

    while (k--)
    {
        // 봄
        deque<pair<int, pair<int, int>>> deadTrees;
        sort(trees.begin(), trees.end());
        int sz = trees.size();
        while (sz--)
        {
            pair<int, pair<int, int>> tree = trees.front();
            trees.pop_front();
            if (feed[tree.second.first][tree.second.second] < tree.first) deadTrees.push_back(tree);
            else
            {
                feed[tree.second.first][tree.second.second] -= tree.first;
                tree.first++;
                trees.push_back(tree);
            }
        }

        // 여름
        while (!deadTrees.empty())
        {
            pair<int, pair<int, int>> deadTree = deadTrees.front();
            deadTrees.pop_front();
            feed[deadTree.second.first][deadTree.second.second] += deadTree.first/2;
        }

        // 가을
        sz = trees.size();
        for (int i=0; i<sz; i++)
        {
            pair<int, pair<int, int>> tree = trees[i];
            if (tree.first%5 == 0)
            {
                for (int i=0; i<8; i++)
                {
                    int row = tree.second.first+dir[i][0];
                    int col = tree.second.second+dir[i][1];

                    if (chk(row, col)) trees.push_back({1, {row, col}});
                }
            }
        }

        // 겨울
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) feed[i][j] += a[i][j];
    }

    printf("%ld\n", trees.size());

    return 0;
}
