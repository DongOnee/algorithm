/**
 * 18.12.19. 수요일
 */
#include <cstdio>
#include <algorithm>
using namespace std;


int main(int argc, char const *argv[])
{
    int N; scanf("%d", &N);
    int i=666;
    for (int j=i; 0<N; j=++i)
    {
        int cnt=0;
        while (j)
        {
            int tmp = j%10;
            j/=10;
            if (tmp == 6)
            {
                cnt++;
                if (cnt == 3) break;
            } else cnt=0;
        }
        if (cnt==3) N--;
    }

    printf("%d\n", i-1);

    return 0;
}
