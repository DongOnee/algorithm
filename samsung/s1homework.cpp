#include <iostream>
#include <vector>
using namespace std;

vector<char> map[10];
int maxHeight, score;
vector<pair<int, int>> toErase;

bool search()
{
    
    return !toErase.empty();
}

void erase()
{

}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    
    cin >> maxHeight;

    // first
    for (int i=0; i<maxHeight; i++)
    {
        for (int j=0; j<10; j++)
        {
            char tmp; cin >> tmp;
            map[j].push_back(tmp);
        }
    }

    
    while (search()) erase();

    for (int i=0; i<10; i++) map[i].clear();
    
    // second
    for (int i=0; i<maxHeight; i++)
    {

    }
    return 0;
}

