#include <cstdio>

int n;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    int width = 4*n-3, height = width;
    bool toggle = true;
    int cnt = 0;
    for (int i=0; i<height; i++)
    {
        if (i%2)
        {
            for (int c=0; c<cnt; c++) printf("* ");
            for (int c=0; c<width-4*cnt; c++) printf(" ");
            for (int c=0; c<cnt; c++) printf(" *");
            if (!toggle) cnt--;
        }
        else
        {
            for (int c=0; c<cnt; c++) printf("* ");
            for (int c=0; c<width-4*cnt; c++) printf("*");
            for (int c=0; c<cnt; c++) printf(" *");

            if (toggle && cnt == n-1) toggle = false;
            else if (toggle) cnt++;
        }
        // printf("%d ", cnt);
        printf("\n");
    }
    return 0;
}
