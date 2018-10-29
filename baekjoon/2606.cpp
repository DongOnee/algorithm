#include <iostream>
#include <cstdio>
using namespace std;

bool map[101][101] = {};
int count_computer;
int infection_count;

void infection(int x) {
    map[0][x] = true;
    infection_count++;
    for (int index=1; index<=count_computer; index++)
    {
        if (map[x][index] && !map[0][index])
        {
            map[x][index] = false;
            map[index][x] = false;
            infection(index);
        }
    }
}

int main(void) {
    int count_cmd;
    infection_count = 0;
    cin >> count_computer >> count_cmd;

    while(count_cmd--)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = true;
        map[y][x] = true;
    }
    infection(1);
    printf("%d\n", infection_count-1);

    return 0;
}