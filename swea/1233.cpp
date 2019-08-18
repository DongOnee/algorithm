/**
 * 19.3.20.
 */
#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    for (int test_case=0, numberOfNodes; test_case<10; test_case++)
    {
        bool result = false;
        scanf("%d", &numberOfNodes);
        for (int i=1, node_number; i<=numberOfNodes; i++)
        {
            scanf("%d ", &node_number);
            string cmd;
            cin.clear();
            getline(cin, cmd);
            if (result) continue;

            stringstream ss(cmd);
            int oper ,c_node[2] = {0, 0};
            ss >> oper;
            ss >> c_node[0];
            ss >> c_node[1];

            if (oper == '+' || oper == '-' || oper == '*' || oper == '/')
            {
                if (c_node[0] == 0 || c_node[1] == 0) result = true;
            }
            else
            {
                if (c_node[0] != 0 && c_node[1] != 0) result = true;
            }
        }

        printf("#%d ", test_case+1);

        if (result) printf("0\n");
        else printf("1\n");
    }
    return 0;
}
