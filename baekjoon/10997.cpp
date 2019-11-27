#include <cstdio>

int n;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    int l = 0, r = -1, ww = 4*n-3, hh = (n==1?1:4*n-1);
    bool toggle = true;
    for (int h=0; h<hh; h++)
    {
        int m = ww - (l+(r==-1?0:r))*2;
        if (h%2) // 1 3 5 7 9 ...
        {
            for (int i=0; i<l-1; i++) printf("* ");
            if (m<0 || r == 0) printf("*");
            else printf("* ");

            if (r > 0)
            {
                for (int i=0; i<m; i++) printf(" ");

                for (int i=0; i<r; i++) printf(" *");
            }
            if (!toggle)
            {
                l--;
                r--;
            }
        }
        else // ****** 0 2 4 6 8 ...
        {
            for (int i=0; i<l-1; i++) printf("* ");
            if (m < 0) printf("*");
            else if (0<l) printf("* ");
            
            for (int i=0; i<m; i++) printf("*");

            for (int i=0; i<r; i++) printf(" *");

            if (toggle)
            {
                if (h==2*n)
                {
                    toggle = false;
                    l--;
                }
                else
                {
                    l++;
                    r++;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
