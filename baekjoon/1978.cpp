#include <iostream>
#include <cmath>
using namespace std;


int main(void) {
    int N;
    cin >> N;
    int sol=0;
    for (int i=0; i<N; i++)
    {
        bool isPrime = true;
        int tmp;
        cin >> tmp;
        if (tmp ==1) isPrime = false;
        else
        {
            for (int j=2; j<=(int)sqrt(tmp) && isPrime; j++)
                if (tmp % j ==0) isPrime=false;
        } if(isPrime) sol++;
    }
    cout << sol << endl;

    return 0;
}