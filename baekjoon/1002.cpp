#include <iostream>
using namespace std;

#define MMAX(a, b) (a)>(b)?(a):(b)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	for (int tt=0; tt<t; tt++)
	{
		int ax, ay, ar, bx, by, br;
		cin >> ax >> ay >> ar >> bx >> by >> br;

		if ( ax == bx && ay == by)
		{
			if (ar == br) cout << "-1\n";
			else cout << "0\n";
		}
		else
		{
			int pow_dist = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
			int pow_r = (ar + br) * (ar + br);
			int pow_minus_r = (ar - br) * (ar - br);

			if (pow_dist < pow_minus_r) cout << "0\n";
			else if (pow_dist == pow_minus_r) cout << "1\n";
			else if (pow_dist < pow_r) cout << "2\n";
			else if (pow_dist == pow_r) cout << "1\n";
			else cout << "0\n";
		}
	}
	return 0;
}