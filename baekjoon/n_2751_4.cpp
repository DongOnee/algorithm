#include <iostream>
using namespace std;

int data[1000000];
int size;

void swap(int a, int b) {int tmp=data[a];data[a]=data[b];data[b]=tmp;}

void fixHeap(int p_index) {
    cout << "fixHeap func\tParents index " << p_index << endl;
    int l_index = 2*p_index+1;
    int r_index = 2*p_index+2;

    if (l_index<size) { // if not leaf
        int small_index = p_index;
        if (data[l_index] < data[small_index]) small_index = l_index;
        if (r_index < size && data[r_index] < data[small_index]) small_index = r_index;
        if (small_index != p_index) {
            swap(small_index, p_index);
            fixHeap(small_index);
        }
    } return;
}

void buildHeap(int p_index) { // data array -> Heap struct
    cout << "buildHeap func\tParents index " << p_index << endl;
    int l_index = 2*p_index+1;
    if (size <= l_index) return; // if leaf
    int r_index = 2*p_index+2;

    buildHeap(l_index);
    if(r_index < size) buildHeap(r_index);
    fixHeap(p_index);
    return;
}

void HeapSort(int n) {
    cout << "HeapSort func" << endl;
    while(--n)
    {
        swap(0, --size);
        fixHeap(0);
    }
}

void arrPrint(int count) {
    for (int i=count; 0<i; i--) cout << data[i-1] << endl;
}

int main(void) {
    size= 0;
    int N;
    cin >> N;
    int count = N;
    while(N--) cin >> data[size++];
    buildHeap(0);
    HeapSort(size);
    // arrPrint(count);
    return 0;
}