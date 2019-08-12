#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> vt;

int main(void)
{
	int sums = 0, n;
	scanf("%d", &n);
	vt.push_back(0);
	for (int i=0; i<n; i++)
	{
		int input;
		scanf("%d", &input);
		sums += input;
		vt.push_back(sums);
	}
	sort(vt.begin(), vt.end());
	printf("%d\n",vt.back()- vt.front());

	return 0;
}