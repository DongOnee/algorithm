/**
 * 19.4.5.
 */
#include <cstdio>

int h, w, n, map[1001][1001];
int dir[2][2] = { {1, 0}, {0, 1}};

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &h, &w, &n);
    for (int i=0; i<h; i++) for (int j=0; j<w; j++) scanf("%d", map[i]+j);

    int rows, cols;
    while (n--)
    {
        int cur_row=0, cur_col=0;
        while (cur_row < h && cur_col < w)
        {
            int tmp = map[cur_row][cur_col];
            map[cur_row][cur_col] += 1;
            map[cur_row][cur_col] %= 2;
            cur_row += dir[tmp][0];
            cur_col += dir[tmp][1];
        }
        rows=cur_row, cols=cur_col;
    }
    printf("%d %d\n", rows+1, cols+1);
    return 0;
}


/*
1 0 1 1
0 1 0 0
1 0 1 0
      x

0 1 1 1
0 0 1 0
1 0 0 1
  x

1 1 1 1 x
1 0 1 0
0 1 0 1

0 0 0 0
1 0 1 0
0 1 0 1
    x

1 0 0 0
0 1 1 0
0 0 1 1 x

0 1 0 0
0 0 0 1
0 0 1 0
x

1 1 0 0
1 0 0 1
1 0 1 0
      x

0 0 1 0
1 0 1 1
1 0 0 1
