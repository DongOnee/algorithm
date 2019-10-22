#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_WIDTH 100

int solution(vector<int> map_apple, int map_width, int map_height, int car_location)
{
    int answer = 0, idxEnd = car_location+1;
    vector<int> dp[2];
    dp[0].resize(map_width+2);
    dp[1].resize(map_width+2);
    bool toggle = false;

    for (int i=0; i<map_height; i++)
    {
        for (int j=car_location-1; j < idxEnd; j++)
        {
            dp[!toggle][j] = dp[toggle][j];
            if (j != 0) dp[!toggle][j] = max(dp[!toggle][j], dp[toggle][j-1]);
            if (j != map_width-1) dp[!toggle][j] = max(dp[!toggle][j], dp[toggle][j+1]);
        }
        toggle ^= true;
    }

    for (int i=0; i<map_width; i++) max(answer, dp[toggle][i]);
    return answer;
}

int main(int argc, char const *argv[])
{
    cout << solution({1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1}, 4, 5, 2) << '\n';
    return 0;
}
