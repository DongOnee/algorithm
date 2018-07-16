#include <stdio.h>

int stack[100001];
int top;
char ans[200001];
int ans_top;

void push()
{
    static int input=1;
    top++;
    stack[top] = input;
    input++;
    // printf("+\n");
    ans[ans_top++] = '+';
}

int pop()
{
    if (top==0) return -1;
    ans[ans_top++] = '-';
    // printf("-\n");
    return stack[top--];
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        int tmp;
        scanf("%d", &tmp);

        while (stack[top] < tmp)
        {
            push();
        }
        int p = pop();
        if (p != tmp)
        {
            printf("NO\n");
            return 0;
        }
    }

    int k = 0;
    while ((n = ans[k++]) != '\0')
    {
        printf("%c\n", n);
    }

    return 0;
}
