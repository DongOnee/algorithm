#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int data[1000000];
int size;

void swap(int index1, int index2){
	int tmp = data[index1];
	data[index1] = data[index2];
	data[index2] = tmp;
}
void push(int input) {
	int index = size++;// index = input's index;
	data[index] = input;
	int p_index = (index -1) /2;
	if(size == 1) return;
	while(data[index] < data[p_index])
	{
		swap(index, p_index);
		index = p_index;
		p_index = (index -1) /2;
	}
}
void pop() {
	cout << data[0] << endl;
	data[0] = data[--size];
}
void ifHeap(int p_index){
	int small_index = p_index;
	int l_index = 2*p_index +1;
	int r_index = 2*p_index +2;

	if (l_index<size && data[l_index]<data[small_index]) small_index = l_index;
	if (r_index<size && data[r_index]<data[small_index]) small_index = r_index;
	if (small_index == p_index) return;
	swap(small_index, p_index);
	ifHeap(small_index);
}
void heapSort() {
	while(1)
	{
		pop();
		if (size == 0) return;
		ifHeap(0);
	}
}

int main(int argc, char const *argv[])
{
	size =0;
	int N;
	cin >> N;
	while(N--) {
		int tmp;
		cin >> tmp;
		push(tmp);
	}
	heapSort();
	return 0;
}
