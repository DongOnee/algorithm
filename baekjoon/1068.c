#include <stdio.h>

int d[51][51] ={ 0, };
int root;
int sol;
int excp;

int q[51];
int count;
int init;

int pop()
{
    count--;
    return q[init++];
}

void push(int input)
{
    q[init+count] = input;
    count++;
}

void print_d(int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++) printf("%d", d[i][j]);
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    sol = 0;

    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int tmp;
        scanf("%d", &tmp);

        if (tmp == -1) root = i;
        else
        {
            d[tmp][0] +=1;
            d[tmp][d[tmp][0]] = i;
        }
    }

    scanf("%d", &excp);
    if (excp == root)
    {
        printf("0\n");
        return 0;
    }
    count = 1;
    init = 0;
    q[0] = root;

    while(count != 0)
    {
        int visit = pop();
        if (d[visit][0] == 0 || (d[visit][0] == 1 && d[visit][1] == excp))
        {
            sol++;
            continue;
        }
        for (int i=1; i<=d[visit][0]; i++)
        {
            if (d[visit][i] != excp) push(d[visit][i]);
        }
    }

    printf("%d\n", sol);

    return 0;
}
