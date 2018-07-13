#include <stdio.h>

int stack[100001];
int top;

void push()
{
    static int input=1;
    top++;
    stack[top] = input;
    input++;
    printf("+\n");
}

int pop()
{
    if (top==0) return -1;
    printf("-\n");
    return stack[top--];
}

int main(int argc, char const *argv[]) {
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

    }
    /* code */
    return 0;
}
