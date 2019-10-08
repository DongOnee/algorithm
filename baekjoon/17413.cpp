#include <cstdio>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    char input;
    bool isOpen=false;
    stack<char> sk;
    while (true)
    {
        scanf("%c", &input);
        if (input == '\n') break;
        if (input == '<')
        {
            isOpen = true;
            while (!sk.empty())
            {
                printf("%c", sk.top());
                sk.pop();
            }
        }

        if (isOpen)
        {
            printf("%c", input);
            if (input == '>') isOpen = false;
        }
        else
        {
            if (input == ' ')
            {
                while (!sk.empty())
                {
                    printf("%c", sk.top());
                    sk.pop();
                }
                printf("%c", input);
            }
            else sk.push(input);
        }
    }
    while (!sk.empty())
    {
        printf("%c", sk.top());
        sk.pop();
    }
    return 0;
}
