#include <cstdio>

int N;
int map[20][20];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int max;

bool chk(int row, int col) { return 0<=row&&row<N&&0<=col&&col<N; }

bool mv(int dir_code) {
    bool ret = false;

    if (dir_code == 0)
    {
        for (int col=0; col<N; col++)
        {
            int zero_cnt=0;
            for (int row=N-1; row >=0; row--)
            {
                if (map[row][col]==0)
                {
                    zero_cnt++;
                    continue;
                }

                int next_row=row-1;
                if (!chk(next_row, col)) 
                {
                    map[row+zero_cnt][col] = map[row][col];
                    if (zero_cnt != 0) 
                    {
                        map[row][col]=0;
                        ret = true;
                    }
                    break;
                }
                while (map[next_row][col]==0)
                {
                    next_row--;
                    if (!chk(next_row, col)) break;
                }
                if (!chk(next_row, col))
                {
                    map[row+zero_cnt][col] = map[row][col];
                    if(zero_cnt!=0) 
                    {
                        map[row][col]=0;
                        ret = true;
                    }
                    break;
                }
                if (map[row][col] == map[next_row][col])
                {
                    map[row+zero_cnt][col] =2*map[row][col];
                    map[next_row][col]=0;
                    if (zero_cnt != 0) 
                    {
                        map[row][col]=0;
                        ret = true;
                    }
                    zero_cnt += (row-next_row);
                    row = next_row;
                }
                else
                {
                    map[row+zero_cnt][col] = map[row][col];
                    if (zero_cnt != 0) 
                    {
                        map[row][col]=0;
                        ret = true;
                    }
                    zero_cnt += (row-next_row-1);
                    row = next_row+1;
                }
            }
        }
    }
    else if (dir_code == 1)
    {
        for (int col=0; col<N; col++)
        {
            int zero_cnt=0;
            for (int row=0; row<N; row++)
            {
                if (map[row][col]==0)
                {
                    zero_cnt++;
                    continue;
                }

                int next_row=row+1;
                if (!chk(next_row, col)) 
                {
                    map[row-zero_cnt][col] = map[row][col];
                    if (zero_cnt != 0) 
                    {
                        map[row][col]=0;
                        ret = true;
                    }
                    break;
                }
                while (map[next_row][col]==0)
                {
                    next_row++;
                    if (!chk(next_row, col)) break;
                }
                if (!chk(next_row, col))
                {
                    map[row-zero_cnt][col] = map[row][col];
                    if(zero_cnt!=0) 
                    {
                        map[row][col]=0;
                        ret = true;
                    }
                    break;
                }
                if (map[row][col] == map[next_row][col])
                {
                    map[row-zero_cnt][col] =2*map[row][col];
                    map[next_row][col]=0;
                    if (zero_cnt != 0) 
                    {
                        map[row][col]=0;
                        ret = true;
                    }
                    zero_cnt += (next_row-row);
                    row = next_row;
                }
                else
                {
                    map[row-zero_cnt][col] = map[row][col];
                    if (zero_cnt != 0) 
                    {
                        map[row][col]=0;
                        ret = true;
                    }
                    zero_cnt += (next_row-row-1);
                    row = next_row-1;
                }
            }
        }
    }
    else if (dir_code == 2)
    {
        for (int row=0; row<N; row++)
        {
            int zero_cnt=0;
            for (int col=N-1; col>=0; col--)
            {
                if (map[row][col]==0)
                {
                    zero_cnt++;
                    continue;
                }

                int next_col=col-1;
                if (!chk(row, next_col)) 
                {
                    map[row][col+zero_cnt] = map[row][col];
                    if (zero_cnt != 0) 
                    {
                        map[row][col]=0;
                        ret = true;
                    }
                    break;
                }
                while (map[row][next_col]==0)
                {
                    next_col--;
                    if (!chk(row, next_col)) break;
                }
                if (!chk(row, next_col))
                {
                    map[row][col+zero_cnt] = map[row][col];
                    if(zero_cnt!=0) 
                    {
                        map[row][col]=0;
                        ret = true;
                    }
                    break;
                }
                if (map[row][col] == map[row][next_col])
                {
                    map[row][col+zero_cnt] =2*map[row][col];
                    map[row][next_col]=0;
                    if (zero_cnt != 0) 
                    {
                        map[row][col]=0;
                        ret = true;
                    }
                    zero_cnt += (col-next_col);
                    col = next_col;
                }
                else
                {
                    map[row][col+zero_cnt] = map[row][col];
                    if (zero_cnt != 0) 
                    {
                        map[row][col]=0;
                        ret = true;
                    }
                    zero_cnt += (col-next_col-1);
                    col = next_col+1;
                }
            }
        }
    }
    else {
        for (int row=0; row<N; row++)
        {
            int zero_cnt=0;
            for (int col=0; col<N; col++)
            {
                if (map[row][col]==0)
                {
                    zero_cnt++;
                    continue;
                }

                int next_col=col+1;
                if (!chk(row, next_col)) 
                {
                    map[row][col-zero_cnt] = map[row][col];
                    if (zero_cnt != 0) 
                    {
                        map[row][col]=0;
                        ret = true;
                    }
                    break;
                }
                while (map[row][next_col]==0)
                {
                    next_col++;
                    if (!chk(row, next_col)) break;
                }
                if (!chk(row, next_col))
                {
                    map[row][col-zero_cnt] = map[row][col];
                    if(zero_cnt!=0) 
                    {
                        map[row][col]=0;
                        ret = true;
                    }
                    break;
                }
                if (map[row][col] == map[row][next_col])
                {
                    map[row][col-zero_cnt] =2*map[row][col];
                    map[row][next_col]=0;
                    if (zero_cnt != 0) 
                    {
                        map[row][col]=0;
                        ret = true;
                    }
                    zero_cnt += (next_col-col);
                    col = next_col;
                }
                else
                {
                    map[row][col-zero_cnt] = map[row][col];
                    if (zero_cnt != 0) 
                    {
                        map[row][col]=0;
                        ret = true;
                    }
                    zero_cnt += (next_col-col-1);
                    col = next_col-1;
                }
            }
        }
    }
    return ret;
}

void dfs(int count) {
    int tmp[20][20];
    for (int i=0;i<N;i++) for(int j=0;j<N;j++) tmp[i][j]=map[i][j];
    for (int i=0; i<4; i++)
    {
        if(mv(i))
        {
            if (count!=5) dfs(count+1);
            for (int i=0;i<N;i++) 
                for(int j=0;j<N;j++) {
                    if (max<map[i][j]) max=map[i][j];
                    map[i][j]=tmp[i][j];
                }
        }
    }
}

int main(int argc, char const *argv[])
{
    max=0;
    scanf("%d", &N);
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) {
        scanf("%d", &map[i][j]);
        if (max<map[i][j]) max = map[i][j];
    }

    dfs(1);

    printf("%d\n", max);

    return 0;
}
