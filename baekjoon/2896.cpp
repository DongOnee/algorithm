#include <iostream>
using namespace std;

#define MMIN(a, b) (a)<(b)?(a):(b)
#define MMMIN(a, b, c) MMIN(MMIN(a, b), c)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	float o, a, p; cin >> o >> a >> p;
	int oo, aa, pp; cin >> oo >> aa >> pp;

	float ooo, aaa, ppp;
	ooo = o / oo;
	aaa = a / aa;
	ppp = p / pp;

	float n = MMMIN(ooo, aaa, ppp);

	printf("%lf %lf %lf\n", o-n*oo, a-n*aa, p-n*pp);

	return 0;
}
