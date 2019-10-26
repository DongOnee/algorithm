#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    int T; cin >> T;
    for (int test_case = 1; test_case <= T; test_case++)
    {
        int N, M, arr[100];
        int arr_min = 2000000000, arr_sum = 0, arr_max = -1;
        cin >> N; // 케익 갯수
        for (int idx = 0; idx < N; idx++)
        {
            cin >> arr[idx];
            arr_sum += arr[idx];
            arr_min = (arr[idx] > arr_min) ? arr_min : arr[idx];
            arr_max = (arr[idx] < arr_max) ? arr_max : arr[idx];
        }
        cin >> M; // 자를 수 있는 최대 횟수

        double between = (double) arr_max - arr_min;
        int divider[100] = { 0 };
        for (int share = 1; share <= arr_min; share++)
        {
            int divider_sum = 0;
            // arr 를 share 로 나눠서 divider 에 저장.
            // divider_sum : 1개씩 가져다가 씀.
            for (int idx = 0; idx < N; idx++)
            {
                divider[idx] = arr[idx] / share;
                divider_sum += divider[idx];
            }

            // divider_sum - N : 무슨 의미지?
            if (divider_sum - N > M) continue;
            double big, small;
            big = small = (double) arr[0] / divider[0];
            for (int idx = 1; idx < N; idx++)
            {
                double value = (double) arr[idx] / divider[idx];
                big = (big < value) ? value : big;
                small = (small < value) ? small : value;
            }
            between = (between < (big - small)) ? between : (big - small);
        }
        cout << '#' << test_case << ' ' << between << '\n';
    }
    return 0;
}