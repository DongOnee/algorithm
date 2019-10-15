#include <iostream>
#include <list>
using namespace std;

string initMsg;
list<char> lst;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> initMsg;
    for (auto x : initMsg)
        lst.push_back(x);
    
    int cntCmd; cin >> cntCmd;
    list<char>::iterator cursor = lst.end();
    while (cntCmd--)
    {
        char cmd; cin >> cmd;
        if (cmd == 'L')
        {
            if(cursor != lst.begin()) cursor--;
        }
        else if (cmd == 'D')
        {
            if(cursor != lst.end()) cursor++;
        }
        else if (cmd == 'B')
        {
            if(cursor != lst.begin()) cursor = lst.erase(--cursor);
        }
        else if (cmd == 'P')
        {
            char input; cin >> input;
            lst.insert(cursor, input);
        }
    }

    for (list<char>::iterator itr = lst.begin(); itr != lst.end(); itr++) cout << *itr;

    return 0;
}
