#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (a == 0) return b;
	return gcd(b%a, a);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	for (int tc=0, a, b; tc<t; tc++)
	{
		cin >> a >> b;
		cout << a * b / gcd(a, b) << '\n';
	}
	
	return 0;
}
