#include <cstdio>
int n;
char map[1<<10][1<<11];

void build(int step, int r, int c)
{
    int height = (1<<step) -1, width = (1<<(step+1)) -3;
    if (step%2==0)
    {
        for (int i=0; i<width; i++) map[r][c+i] = '*';
        for (int i=1; i<height; i++)
        {
            map[r+i][c+i] = '*';
            map[r+i][c+width-1-i] = '*';
        }
    }
    else
    {
        for (int i=0; i<width; i++) map[r+height-1][c+i] = '*';
        for (int i=1; i<height; i++)
        {
            map[r+height-1-i][c+i] = '*';
            map[r+height-1-i][c+width-1-i] = '*';
        }
    }
}

void run()
{
    int r=0, c=0, nn = n;
    while (nn)
    {
        // printf("r:%d\nc:%d\n", r, c);
        build(nn, r, c);
        int height = (1<<nn) -1, width = (1<<(nn+1)) -3;
        if (nn%2) r += height/2;
        else r += 1;
        c += width/4+1;
        nn--;
    }
}

void sol()
{
    int height = (1<<n) -1, width = (1<<(n+1)) -3;
    if (n%2) width = width/2 +1;
    // printf("height %d\twidth %d\n", height, width);

    for (int i=0; i<height; i++)
    {
        for (int j= 0; j<width; j++) printf("%c", map[i][j]);
        printf("\n");
        if (n%2) width++;
        else width--;
    }
}

void init()
{
    scanf("%d", &n);
    int height = (1<<n) -1, width = (1<<(n+1)) -3;
    for (int i=0; i<height; i++) for (int j= 0; j<width; j++) map[i][j] = ' ';
}

int main(int argc, char const *argv[])
{
    init();
    run();
    sol();
    return 0;
}
