#include <iostream>

using namespace std;

int size;
int* data;

void swap(int a, int b) {
    int tmp = data[a];
    data[a] = data[b];
    data[b] = tmp;
}

void fixHeap(int p_index) {
    int small_index = p_index;
    int l_index = 2 *p_index +1;
    int r_index = 2 *p_index +2;

    if (l_index<size && data[l_index]<data[small_index]) small_index = l_index;
    if (r_index<size && data[r_index]<data[small_index]) small_index = r_index;

    if (small_index != p_index)
    {
        swap(p_index, small_index);
        if (2 *small_index +1 < size) fixHeap(small_index); // not leaf
    }
    return;
}

void makeHeap(int p_index) {
    int l_index = 2 *p_index +1;
    int r_index = 2 *p_index +2;

    if (l_index < size) // not leaf
    {
        makeHeap(l_index);
        if(r_index < size) makeHeap(r_index);
        fixHeap(p_index);
    }
}
void heapSort() {
    while(size)
    {
        cout << data[0] << endl;
        data[0] = data[--size];
        fixHeap(0);
    }
}

int main(void) {
    size= 0;
    int N;
    cin >> N;
    data = new int[N];
    while(N--) cin >> data[size++];
    makeHeap(0);
    heapSort();
    return 0;
}