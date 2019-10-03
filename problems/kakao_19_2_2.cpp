/**
 * 2019.10.03. 17:30 ~ 18:15
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string revStr(const string& str)
{
    string ans = "";
    for (int i=0; str[i]; i++)
    {
        if (str[i] == '(') ans += ')';
        else ans += '(';
    }
    return ans;
}

string subsol(const string& subs)
{
    if (subs.size() == 0) return "";
    
    int idxU = 0, szU = 1, cntLeft=0;
    bool flag;
    if (subs[idxU] == ')')
    {
        cntLeft--;
        flag = false;
    }
    else
    {
        cntLeft++;
        flag = true;
    }
    
    while (cntLeft != 0)
    {
        if (subs[idxU+szU] == '(') cntLeft++;
        else cntLeft--;
        szU++;
    }
    
    string u = subs.substr(0, szU);
    string v = subs.substr(szU, subs.size());
    
    if (flag) return u + subsol(v);
    return "(" + subsol(v) + ")" + revStr(u.substr(1, u.size()-2));
}

string solution(string p) {
    string answer = subsol(p);
    return answer;
}

int main(int argc, char const *argv[])
{
    cout << solution("(()())()") << endl;
    cout << solution(")(") << endl;
    cout << solution("()))((()") << endl;
    
    return 0;
}
/*
"(()())()"
"()"
"()(())()"
*/