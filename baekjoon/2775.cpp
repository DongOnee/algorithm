#include <iostream>
#include <algorithm>
using namespace std;

int d[15][15];

int calc(int floor, int room)
{
    if (d[floor][room] == 0) return calc(floor, room-1) + calc(floor-1, room);
    return d[floor][room];
}

int main(int argc, char const *argv[]) {
    for(int i=1; i<15; i++)
    {
        d[0][i] = i;
        d[i][1] = 1;
    }

    int test_case; scanf("%d\n", &test_case);
    while(test_case--)
    {
        int k, n;
        cin >> k >> n;

        cout << calc(k, n) << endl;
    }
    return 0;
}
