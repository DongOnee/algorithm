#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class container{
    private:
    int data[1000000];
    int size;
    public:
    container() : size(0) {};
    ~container() {};
    bool isempty() {
        if (size ==0) return true;
        return false;
    }
    int getSize() {return size;}
    void swap(int index1, int index2){
        int tmp = data[index1];
        data[index1] = data[index2];
        data[index2] = tmp;
    }
    void push(int input) {
        int index = size++; // index = input's index;
        data[index] = input;
        int p_index = (index -1) /2;
        if(size == 1) return;
        while(index != 0)
        {
            if(data[index] < data[p_index])
            {
                swap(index, p_index);
                index = p_index;
                p_index = (index -1) /2;
            }else break;
        }
    }
    void pop() {
        cout << data[0] << endl;
        data[0] = data[--size];
    }
    void isHeap(int p_index){
        int small_index = p_index;
        int l_index = 2*p_index +1;
        int r_index = 2*p_index +2;
        if (l_index<size && data[l_index]<data[small_index]) small_index = l_index;
        if (r_index<size && data[r_index]<data[small_index]) small_index = r_index;
        if (small_index == p_index) return;
        swap(small_index, p_index);
        isHeap(small_index);
    }
    void heapSort() {
        while(1)
        {
            pop();
            if (size == 0) return;
            isHeap(0);
        }
    }
};

int main(int argc, char const *argv[])
{
    container con;
    int N;
    cin >> N;
    while(N--) {
        int tmp;
        cin >> tmp;
        con.push(tmp);
    }
    con.heapSort();
    return 0;
}
