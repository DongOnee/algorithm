#include <stdio.h>

int main(int argc, char const *argv[])
{
    // input data
    int n;
    scanf("%d", &n);

    // init data
    int d[10]= {}; // d[j] : j로 끝나는 숫자의 갯수

    // Algorithm
    int po = 1;

    while(po <= n)
    {
        int a = n / po;
        int b = a % 10;
        int c = n % po;
        a /= 10;

        // printf("%d\t%d\t%d\n", a, b, c);
        if (a == 0)
        {
            for (int i=1; i<b; i++) d[i] += po;
            d[b] +=c+1;
        }
        else
        {
            if (b == 0)
            {
                d[0] += (a-1)*po + c+1;
                for (int i=1; i<10; i++) d[i] += a*po;
            }
            else
            {
                d[0] += a*po;
                for (int i=1; i<b; i++) d[i] += (a+1)*po;
                for (int i=b; i<10; i++) d[i] += a*po;
                d[b] += c+1;
            }
        }
        po *=10;
    }

    // print
    for (int i=0; i<10; i++) printf("%d ", d[i]);
    puts("");

    return 0;
}
