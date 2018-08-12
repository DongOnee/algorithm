#include <stdio.h>
#include <string.h>

int stack[100001];
int count;
int top_c;

void push(int input)
{
    stack[top_c++] = input;
    count++;
}

int pop()
{
    if (count ==0) return -1;
    count--;
    return stack[--top_c];
}

int size()
{
    return count;
}

int empty()
{
    if (count == 0) return 1;
    return 0;
}

int top()
{
    if (count ==0) return -1;
    return stack[top_c-1];
}

int main(int argc, char const *argv[])
{
    count = 0;
    top_c = 0;

    int n;
    scanf("%d", &n);
    while (n--)
    {
        char command[6];
        scanf("%s", command);
        if (!strcmp(command, "pop"))
        {
            printf("%d\n",pop());
        }
        else if(!strcmp(command, "size"))
        {
            printf("%d\n", size());
        }
        else if(!strcmp(command, "empty"))
        {
            printf("%d\n", empty());
        }
        else if(!strcmp(command, "top"))
        {
            printf("%d\n", top());
        }
        else if(!strcmp(command, "push"))
        {
            int input;
            scanf("%d", &input);
            push(input);
        }
    }

    /* code */
    return 0;
}
