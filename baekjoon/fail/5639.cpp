#include <iostream>
using namespace std;

#define _MAXN 10000

typedef struct nnn
{
	int data, l, r, p;
	nnn() : data(-1), l(-1), r(-1), p(-1) {}
}node;
node nodes[_MAXN + 1];

void posto(int index)
{
	if (nodes[index].l > -1) posto(nodes[index].l);
	if (nodes[index].r > -1) posto(nodes[index].r);
	cout << nodes[index].data << '\n';
}


int main(void)
{
	int input, curp = 0, index = 1;
	while (cin >> input)
	{
		nodes[index].data = input;
		if (index == 1);
		else if (input < nodes[curp].data) nodes[curp].l = index;
		else
		{
			while (nodes[nodes[curp].p].data < input && curp != 1) curp = nodes[curp].p;
			nodes[curp].r = index;
		}
		nodes[index].p = curp;
		curp = index;
		index++;
	}

	posto(1);

	return 0;
}