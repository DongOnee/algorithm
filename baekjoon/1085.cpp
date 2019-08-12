/**
 * 18.12.21. 금요일
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);

    printf("%d\n", min(x, min(y, min(w-x, h-y))));

    return 0;
}
