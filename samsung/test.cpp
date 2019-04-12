#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int main(int argc, char const *argv[])
{
    pair<int, int> p = {-1, -3};
    pair<int, int> m = make_pair(0, 0)-p;
    printf("%d %d", m.first, m.second);
    return 0;
}
