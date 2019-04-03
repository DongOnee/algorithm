/**
 * 19.3.23.
 */
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int line;
char map[8][9];

int search_(int row, int col)
{
    int ret = 2;
    stack<char> st;
    int i=0;
    if (row + line >8) ret--;
    else
    {
        for (; i<line/2; i++) st.push(map[row+i][col]);
        if (line%2) i++;
        for (; i<line; i++)
        {
            char tp = st.top();
            st.pop();
            if (tp != map[row+i][col])
            {
                stack<char> emp;
                swap(st, emp);
                ret--;
                break;
            }
        }
    }

    if (col + line > 8) ret--;
    else
    {
        for (i=0; i<line/2; i++) st.push(map[row][col+i]);
        if (line%2) i++;
        for (; i<line; i++)
        {
            char tp = st.top();
            st.pop();
            if (tp != map[row][col+i])
            {
                stack<char> emp;
                swap(st, emp);
                ret--;
                break;
            }
        }
    }
    return ret;
}


int main(int argc, char const *argv[])
{
    for (int tc=0, sol; tc<10; tc++)
    {
        sol = 0;

        scanf("%d", &line);

        for (int row=0; row<8; row++) scanf("%s", map[row]);

        for (int row=0; row<8; row++)
            for (int col=0; col<8; col++)
                sol += search_(row, col);

        printf("#%d %d\n", tc+1, sol);
    }
    return 0;
}
