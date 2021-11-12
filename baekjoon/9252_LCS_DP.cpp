#include <iostream>
#include <string>

using namespace std;

#define MAXN 1'001

string str1, str2;
int lcs[MAXN][MAXN];
string lcsString[MAXN][MAXN];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str1 >> str2;

    for (int i = 0; i < str1.length(); ++i) {
        for (int j = 0; j < str2.length(); ++j) {
            if (str1[i] == str2[j]) {
                lcs[i+1][j+1] = lcs[i][j] + 1;
                lcsString[i+1][j+1] = lcsString[i][j] + str1[i];
            }
            else {
                if (lcs[i][j+1] < lcs[i+1][j]) {
                    lcs[i+1][j+1] = lcs[i+1][j];
                    lcsString[i+1][j+1] = lcsString[i+1][j];
                }
                else {
                    lcs[i+1][j+1] = lcs[i][j+1];
                    lcsString[i+1][j+1] = lcsString[i][j+1];
                }
            }
        }
    }

    cout << lcs[str1.length()][str2.length()] << '\n' << lcsString[str1.length()][str2.length()] << '\n';

    return 0;
}
