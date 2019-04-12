/**
 * 19.4.8. 17:10~
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int n, map[22][22], sol;

void slideLeft()
{
    for (int slideRow = 0; slideRow<n; slideRow++)
    {
        int i=0, j=1;
        while (i<n && j<n)
        {
            if (map[slideRow][i] == 0)
            {
                if (map[slideRow][j] != 0)
                {
                    map[slideRow][i] = map[slideRow][j];
                    map[slideRow][j] = 0;
                }
                j++;
            }
            else
            {
                if (map[slideRow][j] == map[slideRow][i])
                {
                    map[slideRow][i] *= 2;
                    map[slideRow][j] = 0;
                    i++;
                    j++;
                }
                else if (map[slideRow][j] == 0) j++;
                else
                {
                    if (i-j == 1 || i-j == -1)
                    {
                        i++;
                        j++;
                    }
                    else 
                    {
                        map[slideRow][++i] = map[slideRow][j];
                        map[slideRow][j++] = 0;
                    }
                }
            }
        }
    }
}

void slideRight()
{
    for (int slideRow = 0; slideRow<n; slideRow++)
    {
        int i=n-1, j=n-2;
        while (0<=i && 0<=j)
        {
            if (map[slideRow][i] == 0)
            {
                if (map[slideRow][j] != 0)
                {
                    map[slideRow][i] = map[slideRow][j];
                    map[slideRow][j] = 0;
                }
                j--;
            }
            else
            {
                if (map[slideRow][j] == map[slideRow][i])
                {
                    map[slideRow][i] *= 2;
                    map[slideRow][j] = 0;
                    i--;
                    j--;
                }
                else if (map[slideRow][j] == 0) j--;
                else
                {
                    if (i-j == 1 || i-j == -1)
                    {
                        i--;
                        j--;
                    }
                    else 
                    {
                        map[slideRow][--i] = map[slideRow][j];
                        map[slideRow][j--]=0;
                    }
                }
            }
        }
    }
}

void slideUp()
{
    for (int slideCol = 0; slideCol<n; slideCol++)
    {
        int i=0, j=1;
        while (i<n && j<n)
        {
            if (map[i][slideCol] == 0)
            {
                if (map[j][slideCol] != 0)
                {
                    map[i][slideCol] = map[j][slideCol];
                    map[j][slideCol] = 0;
                }
                j++;
            }
            else
            {
                if (map[j][slideCol] == map[i][slideCol])
                {
                    map[i][slideCol] *= 2;
                    map[j][slideCol] = 0;
                    i++;
                    j++;
                }
                else if (map[j][slideCol] == 0) j++;
                else
                {
                    if (i-j == 1 || i-j == -1)
                    {
                        i++;
                        j++;
                    }
                    else 
                    {
                        map[++i][slideCol] = map[j][slideCol];
                        map[j++][slideCol] = 0;
                    }
                }
            }
        }
    }
}

void slideDown()
{
    for (int slideCol = 0; slideCol<n; slideCol++)
    {
        int i=n-1, j=n-2;
        while (0<=i && 0<=j)
        {
            if (map[i][slideCol] == 0)
            {
                if (map[j][slideCol] != 0)
                {
                    map[i][slideCol] = map[j][slideCol];
                    map[j][slideCol] = 0;
                }
                j--;
            }
            else
            {
                if (map[j][slideCol] == map[i][slideCol])
                {
                    map[i][slideCol] *= 2;
                    map[j][slideCol] = 0;
                    i--;
                    j--;
                }
                else if (map[j][slideCol] == 0) j--;
                else
                {
                    if (i-j == 1 || i-j == -1)
                    {
                        i--;
                        j--;
                    }
                    else 
                    {
                        map[--i][slideCol] = map[j][slideCol];
                        map[j--][slideCol] = 0;
                    }
                }
            }
        }
    }
}

void dfs(int cnt)
{
    if (cnt == 5)
    {
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) sol = (sol>map[i][j]?sol:map[i][j]);
        return ;
    }

    int arr[n][n];
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) arr[i][j] = map[i][j];
    
    slideLeft();
    dfs(cnt+1);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) map[i][j] = arr[i][j];
    slideRight();
    dfs(cnt+1);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) map[i][j] = arr[i][j];
    slideUp();
    dfs(cnt+1);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) map[i][j] = arr[i][j];
    slideDown();
    dfs(cnt+1);
}

int main(int argc, char const *argv[])
{
    sol = 0;
    scanf("%d", &n);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%d", map[i]+j);

    dfs(0);

    printf("%d\n", sol);

    return 0;
}
