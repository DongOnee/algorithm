/**
 * 19.3.20.
 */
#include <cstdio>
#include <stack>
using namespace std;

int length;
char *ptr;

int pushpush();

int pushpush(int mult)
{
    char input_;
    scanf("%c", &input_);
    length--;
    if (input_ == '(') return mult*pushpush();
    return mult * (input_ - '0');
}

int pushpush()
{
    stack<int> st;
    while(true)
    {
        char input_;
        scanf("%c", &input_);
        if (input_ == '\n') continue;

        length--;
        if (input_ == ')') break;
        else if (input_ == '(') st.push(pushpush());
        else if (input_ == '*')
        {
            int tp = st.top();
            st.pop();
            st.push(pushpush(tp));
        }
        else if (input_ == '+') continue;
        else st.push(input_-'0');
        if (length <= 0) break;
    }

    int sol = 0;
    while(!st.empty())
    {
        int tp = st.top();
        st.pop();
        sol += tp;
    }

    return sol;
}

int main(int argc, char const *argv[])
{
    for (int i=0; i<10; i++)
    {
        scanf("%d", &length);

        int sol = pushpush();

        printf("#%d %d\n", i+1, sol);
    }
    return 0;
}
