/**
 * 2020.06.14. 11:37 ~ 11:58
 * 매우 쉬운 문제
 */
#include <cstdio>
using namespace std;

int main(int argc, const char* argv[])
{

    int ret = 0;

    for (int i=1; i<=72; i++)
    {
        char c = getchar();
        if (c == '\n') continue;
        if (i%2 && c == 'F') ret++;
    }

    printf("%d\n", ret);
        
    return 0;
}
