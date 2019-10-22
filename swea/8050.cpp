#include <iostream>
#define MAXN 1<<17
#define MAXNN 1<<18
#define MAXK 30
using namespace std;

int n, k;
int map[MAXNN][MAXK];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int T; cin >> T;
	for(int test_case = 1; test_case <= T; ++test_case)
	{
        int cnt=0, maxlen=0;
        cin >> n >> k;
        for (int i=0; i<n; i++) for (int j=0; j<k; j++) map[i][j] = -1;

        cout << "test_case : " << test_case << "\tn : " << n << "\tk : " << k << "\n";

        for (int i=0; i<n; i++)
        {
            bool isRight = true;
            for (int j=0, tmp; j<k; j++)
            {
                cin >> tmp;
                cout << "i : " << i << "\tj : " << j << "\tmap[i][j] : " << tmp << "\tk : " << k << "\n";
                map[MAXN+i][j] = tmp;
                isRight = isRight && (tmp == 1);
            }
            if(isRight) cnt++;
            cout << "n : " << n << "\tk : " << k << "\n";
        }

        if (cnt>0) maxlen = 1;

        for (int idx = MAXN/2, maxi = n/2; 0<maxi; idx /= 2, maxi /= 2)
        {
            for (int i=0; i<maxi; i++)
            {
                for (int j=0; j<k; j++) map[idx+i][j] = map[idx*2+i][j] + map[idx*2+i+1][j];
            }
        }

        for (int i=0; i<n; i++)
        {
            cout << "i : " << i;
            for (int j=0; j<k; j++) cout << ' ' << map[MAXN+i][j];
            cout << '\n';
        }
	}
	return 0;
}