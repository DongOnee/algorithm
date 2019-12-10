#include <cstdio>

int a[5] = {0, 1, 2, 0, 1};
int aa[3][2];

int main(int argc, char const *argv[])
{
    for (int i=0; i<3; i++) scanf("%d%d", aa[i]+0, aa[i]+1);
    
    int idx;
    for (idx=0; idx<3; idx++)
    {
        
        int x = aa[a[idx+1]][0] - aa[idx][0];
        int y = aa[a[idx+1]][1] - aa[idx][1];
        
        int xx = aa[a[idx+2]][0] - aa[idx][0];
        int yy = aa[a[idx+2]][1] - aa[idx][1];

        if (x * xx == -y * yy) break;
    }
    
    printf("%d %d\n", aa[a[idx+1]][0] + aa[a[idx+2]][0] - aa[idx][0], aa[a[idx+1]][1] + aa[a[idx+2]][1] - aa[idx][1]);
    return 0;
}
