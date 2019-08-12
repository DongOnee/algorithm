/**
 * 19.04.12.
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[10];
bool arr2[10];

int main(int argc, char const *argv[])
{
    /* code */
    int sum = 0;
    for (int i=0; i<9; i++) scanf("%d", arr+i);
    sort(arr, arr+9);
    for (int i=0; i<9; i++) sum += arr[i];

    for (int i=0; i<8; i++)
    {
        arr2[i] = true;
        sum -= arr[i];
        for (int j=i+1; j<9; j++)
        {
            arr2[j] = true;
            sum -= arr[j];
            if (sum == 100)
            {
                for (int z=0; z<9; z++)
                {
                    if (arr2[z]) continue;
                    printf("%d\n", arr[z]);
                }
                return 0;
            }
            sum += arr[j];
            arr2[j] = false;
        }
        arr2[i] = false;
        sum += arr[i];
    }
    
    return 0;
}
