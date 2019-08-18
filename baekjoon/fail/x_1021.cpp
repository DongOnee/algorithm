/**
 * 2019.3.7.
 */
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

struct node 
{
    int num;
    struct node * prev;
    struct node * next;
};

struct node nodes[51];
struct node * head;
struct node * tail;

int n, m;
vector<int> vt;

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        nodes[i].num = i;
        nodes[i].prev = nodes+(i+n-1)%n;
        nodes[i].next = nodes+i%n+1;
    }
    for (int i=0, a; i<m; i++)
    {
        scanf("%d", &a);
        vt.push_back(a);
    }
    head = nodes+1;
    tail = nodes+n;
    return 0;
}
