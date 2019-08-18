#include <iostream>
#include <utility>
#include <string.h>
using namespace std;

typedef pair<int, int> pii;

pii nodes[26];

void preo(int i)
{
	cout << char('A'+i);
	if (nodes[i].first != -1) preo(nodes[i].first);
	if (nodes[i].second != -1) preo(nodes[i].second);
}

void ino(int i)
{
	if (nodes[i].first != -1) ino(nodes[i].first);
	cout << char('A'+i);
	if (nodes[i].second != -1) ino(nodes[i].second);
}

void posto(int i)
{
	if (nodes[i].first != -1) posto(nodes[i].first);
	if (nodes[i].second != -1) posto(nodes[i].second);
	cout << char('A'+i);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(nodes, -1, sizeof(nodes));

	int n; cin >> n;
	for (int i=0; i<n; i++)
	{
		char cur, l, r;
		cin >> cur >> l >> r;
		if (l != '.') nodes[cur - 'A'].first = l-'A';
		if (r != '.') nodes[cur - 'A'].second = r-'A';
	}

	preo(0); cout << '\n';
	ino(0); cout << '\n';
	posto(0); cout << '\n';

	return 0;
}