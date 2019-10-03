/**
 * 2019.10.03. 15:00 ~ 17:30
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int isSame(const string& s, int idxStart, const int szSubStr)
{
    int ans = 0;
    string toDetect = s.substr(idxStart, szSubStr);
    while (toDetect == s.substr(idxStart, szSubStr))
    {
        idxStart += szSubStr;
        ans++;
    }

    return ans;
}

int subSol(const string& s, const int szSubStr)
{
    int ans = 0;
    int idxStart = 0;
    while (idxStart + szSubStr < s.size())
    {
        int tmp = isSame(s, idxStart, szSubStr);
        idxStart += tmp*szSubStr;
        ans += szSubStr;
        if (tmp>1) for (; tmp; tmp/=10) ans++;
    }
    
    return ans + s.size() - idxStart;
}

int solution(string s) {
    int answer = s.size();
    for (int i=1; i<=s.size()/2; i++)
    {
        int tmp = subSol(s, i);
        answer = answer < tmp ? answer : tmp;
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    cout << solution("aabbaccc") << '\n';
    cout << solution("ababcdcdababcdcd") << '\n';
    cout << solution("abcabcdede") << '\n';
    cout << solution("abcabcabcabcdededededede") << '\n';
    cout << solution("xababcdcdababcdcd") << '\n';

    return 0;
}
/**
7
9
8
14
17
*/