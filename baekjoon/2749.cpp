/**
 * 19.2.25.
 * ref. https://m.blog.naver.com/PostView.nhn?blogId=jh05013&logNo=220999768783&proxyReferer=&proxyReferer=https%3A%2F%2Fwww.google.com%2F
 */
#include <cstdio>
#include <algorithm>
using namespace std;
#define mod 1000000

long mat[2][2] = {{1, 1}, {1, 0}};

int main(int argc, char const *argv[])
{
    long long n; scanf("%lld", &n);
    long multyp_[2][2] = {{1,0}, {0, 1}};

    while(n)
    {
        long tmp[2][2];
        if (n&1)
        {
            // multyp_ *= mat
            swap(tmp, multyp_);
            for (int i=0; i<2; i++) for (int j=0; j<2; j++) 
            {
                multyp_[i][j] = tmp[i][0] * mat[0][j] + tmp[i][1] * mat[1][j];
                multyp_[i][j] %= mod;
            }
        }
        // mat**
        swap(tmp, mat);
        for (int i=0; i<2; i++) for (int j=0; j<2; j++) 
        {
            mat[i][j] = tmp[i][0] * tmp[0][j] + tmp[i][1] * tmp[1][j];
            mat[i][j] %= mod;
        }
        n >>= 1;
    }
    printf("%ld\n", multyp_[0][1]);

    return 0;
}
