/**
 *  Union - Find Algorithm 을 사용하여 풀어 보도록 한다.
 */
#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

typedef struct _node{
    int row;
    int col;
    int radar;
    int root_index;
}Node;

int ret;
Node* nodes;

int findFunc(int index) {
    if (nodes[index].root_index == index) return index;
    return nodes[index].root_index = findFunc(nodes[index].root_index);
}

void isUnion(int input_index, int compare_index) {
    int distance = (nodes[input_index].row - nodes[compare_index].row)*(nodes[input_index].row - nodes[compare_index].row);
    distance += (nodes[input_index].col - nodes[compare_index].col)*(nodes[input_index].col - nodes[compare_index].col);
    distance -= (nodes[input_index].radar + nodes[compare_index].radar)*(nodes[input_index].radar + nodes[compare_index].radar);
    if (distance > 0) return;

    int root_of_input = findFunc(input_index);
    int root_of_compare = findFunc(compare_index);
    nodes[root_of_input].root_index = root_of_compare;
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    for (int test_case=0; test_case<T; test_case++)
    {
        ret = 0;
        int enemy;
        scanf("%d", &enemy);
        nodes = new Node[enemy];
        for (int input_index=0; input_index<enemy; input_index++)
        {
            int enemy_row, enemy_col, enemy_radar;
            scanf(" %d%d%d", &enemy_row, &enemy_col, &enemy_radar);
            nodes[input_index] = Node({enemy_row, enemy_col, enemy_radar, input_index});
            for (int compare_index=0; compare_index<input_index; compare_index++)
            {
                isUnion(input_index, compare_index);
            }
        }

        int ret=0;
        for (int i=0; i<enemy; i++) if(nodes[i].root_index == i) ret++;

        printf("%d\n", ret);

        delete[] nodes;
    }
    return 0;
}