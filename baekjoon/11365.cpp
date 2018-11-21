/**
 * 18.11.16. 금요일
 * 문제집중 기본 문제를 풀어본다.
 * string 을 다루는 방법? 어느정도 알게 되었나? 싶다.
 * 아래에 사용한 함수 두개를 생각해두자.
 */

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    while(1)
    {
        string cmd;
        getline(cin, cmd);
        if(cmd.compare("END") == 0) break;
        reverse(cmd.begin(), cmd.end());
        cout << cmd << endl;
    }
    return 0;
}
