/**
 * 19.1.6.
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int T; scanf("%d", &T);
    for (int test_case=0; test_case<T; test_case++)
    {
        int N; scanf("%d", &N);

        int arr1[100000] = {};
        int arr2[100000] = {};

        for (int i=0; i<N; i++) 
        {
            int a, b; scanf("%d %d", &a, &b);
            arr1[a-1] = b-1;
            arr2[b-1] = a-1;
        }

        bool arr[100000] = {false, };


        int _min = arr1[0];
        arr[_min] = true;
        for (int i=1; i<N; i++)
        {
            if (arr1[i] < _min)
            {
                _min = arr1[i];
                arr[_min] = true;
            }
        }

        _min = arr2[0];
        int count = 1;
        for (int i=1; i<N; i++)
        {
            if (!arr[i]) continue;
            if (arr2[i] < _min)
            {
                count++;
                _min = arr2[i];
            }
        }

        printf("%d\n", count);
    }
    return 0;
}
