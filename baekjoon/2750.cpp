#include <iostream>

using namespace std;

int d[1000];

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int tmp;
    for (int i=0; i<n; i++)
    {
        cin >> tmp;
        int j = i -1;
        while(tmp < d[j] && 0<= j)
        {
            d[j+1] = d[j];
            j--;
        }
        d[j+1] = tmp;
    }
    for(int i=0; i<n; i++) cout << d[i] << endl;
    return 0;
}
