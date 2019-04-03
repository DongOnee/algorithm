#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    stack<int> st;
    long long int tmp = 0x68B46DDB9346F4;
    long long int tmp2 = 0xD1ABCCBD6E2DD8;
    long long int tmp3 = 0xD26DDDAF76F5E8;


    // printf("%lld\n", tmp);
    printf("%lld\n", tmp3);

    while(tmp3)
    {
        st.push(tmp3%2);
        tmp3 /= 2;
    }

    while(!st.empty())
    {
        printf("%d", st.top());
        st.pop();
    }
    printf("\n");


    return 0;
}
/*
tmp2
0110
1000
1011
0100
0110
1101
1101
1011
1001
0011
0100
0110
1111
0100





tmp3
1101
0010
0110
1101
1101
1101
1010
1111
0111
0110
1111
0101
1110
1000


int codes[10] = {13, 25, 19, 61, 35, 49, 47, 59, 55, 11};

56bit

0001101
0010011
0110111
0111011
0101111
0111011
0111101
0111101
*/