/**
 * MAC MAC MAC
 * COMPUTER2 Modify2 ~~~~
 * I hate GIT!
 * TEST Brunch
 */


#include <iostream>

using namespace std;

int d[1000000];

void insert(int in, int pos, int end_pos)
{
    for (int i=end_pos; pos<=i; i--) d[i+1] = d[i];
    d[pos] = in;
}

void sort(int in, int in_pos)
{
    if(in_pos == 0)
    {
        d[0] = in;
        return;
    } else if (in_pos == 1)
    {
        if (d[0] < in ) d[1] = in;
        else {
            d[1] = d[0];
            d[0] = in;
        }
        return;
    }
    int start = 0;
    int end = in_pos-1;
    int mid = (start+end)/2;
    while(start != mid)
    {
        if (in <= d[mid]) end = mid;
        else start = mid;
        mid = (start+end)/2;
    }
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int tmp;
    for (int i=0; i<n; i++)
    {
        cin >> tmp;
        sort(tmp,i);
    }
    for(int i=0; i<n; i++) cout << d[i] << endl;
    return 0;
}
