// you can use includes, for example:
// #include <algorithm>
#include <vector>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &T) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int>::iterator winter = T.begin();
    vector<int>::iterator summer = T.end()-1;
    int winter_max = *winter;
    int summer_min = *summer;

    while (*summer > winter_max)
    {
        summer_min = (summer_min < *summer ? summer_min : *summer);
        summer--;
    }

    return summer - T.begin();

    // bool turn = false; // true : winter, false summer;
    // while (winter < summer)
    // {
    //     if (turn)
    //     {
    //         while (*winter <= winter_max) winter++;
    //         turn = false;
    //     }
    //     else 
    //     {
    //         while (*summer > winter_max)
    //         {
    //             summer_min = (summer_min < *summer ? summer_min : *summer);
    //             summer--;
    //         }
    //         turn = true;
    //     }
    // }
}