#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int arr[10] = {0};

    while (true)
    {
        arr[n%10]++;
        if (n/10 == 0) break;
        n /= 10;
    }
    
    int sol = 0;
    for (int i=0; i<10; i++)
        if (i !=6 && i != 9) sol = max(sol, arr[i]);

    cout << max(sol, (arr[6] + arr[9] + 1) / 2 ) << endl;
    /* code */
    return 0;
}


// http://blockdmask.tistory.com/97