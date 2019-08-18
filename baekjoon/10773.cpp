/**
 * 18.12.30.
 */
#include <cstdio>
#include <stack>
using namespace std;

stack<int> st;

int main(int argc, char const *argv[])
{
    int cmd; scanf("%d", &cmd);
    while (cmd--)
    {
        int input; scanf("%d", &input);
        if (input == 0) st.pop();
        else
        {
            st.push(input);
        }
    }
    
    int ret=0;
    while(!st.empty())
    {
        int top = st.top();
        st.pop();
        ret += top;
    }
    printf("%d\n", ret);
    return 0;
}
