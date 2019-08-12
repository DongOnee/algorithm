#include <iostream>
using namespace std;

int data[1000000]
int size;



int main(int argc, char const *argv[]) {
    /* code */
    size = 0;
    int N;
    cin >> N;
    for (int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        data[size++] = tmp;
    }
    return 0;
}
