/**
 * 아스키 코드 값을 비교하는 테크닉 정도?
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    string name;
    getline(cin, name);
    for (int i=0; i<name.length(); i++)
    {
        if('A'<=name[i] && name[i] <= 'Z') cout << name[i];
    }
    return 0;
}
