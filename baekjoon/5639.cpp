#include <iostream>
using namespace std;

#define _MAXN 10000

typedef struct nnn
{
	int data, l, r;
	nnn() : data(-1), l(-1), r(-1) {}
}node;
node nodes[_MAXN];

void posto(int index)
{
	if (nodes[index].l > -1) posto(nodes[index].l);
	if (nodes[index].r > -1) posto(nodes[index].r);
	cout << nodes[index].data << '\n';
}


int main(void)
{
	int input, index = 0;
	while (cin >> input)
	{
		nodes[index].data = input;
		int cur = 0;

		while (index > 0)
		{
			if (input < nodes[cur].data)
			{
				if (nodes[cur].l == -1)
				{
					nodes[cur].l = index;
					break;
				}
				else cur = nodes[cur].l;
			}
			else
			{
				if (nodes[cur].r == -1)
				{
					nodes[cur].r = index;
					break;
				}
				else cur = nodes[cur].r;
			}
		}
		index++;
	}

	if (index > 0) posto(0);

	return 0;
}
