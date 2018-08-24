#include <iostream>
using namespace std;

int d[1000000];

void sort(int input, int insert_pos)
{
    int start=0;
    int end = insert_pos-1;
    int mid = (start + end)/2;
    while(true)
    {

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
