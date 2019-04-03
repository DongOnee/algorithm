/**
 * 19.2.12.
 */
#include <cstdio>
#include <string>
using namespace std;

string s;
int len;

bool chk()
{
    int chk_len = len/2;
    int size=0;
    while(size<chk_len)
    {
        size +=1;
        string subs1 = s.substr(len-size, size);
        string subs2 = s.substr(len-size*2, size);

        // printf("string : %s\tsub_s 2 : %s\tsubs_s 1 : %s\n", s.c_str(), subs2.c_str(), subs1.c_str());
        if (subs1.compare(subs2) == 0) return false; // same same...
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int N; scanf("%d", &N);

    s = "1";
    len = 1;
    int input_=1;
    while (len<N)
    {
        len +=1;
        for ( ; input_<4; input_++)
        {
            s.push_back(input_+'0');
            if (chk()) 
            {
                input_=1;
                break;
            }
            s.pop_back();
        }
        if (input_ == 4)
        {
            // 마지막 3 이라는뜻~
            // s.pop_back();
            len-=1;
            input_ = s.at(len-1) -'0'+1;
            // printf("%d", input_);
            s.pop_back();
            len-=1;
        }
    }

    printf("%s\n", s.c_str());

    return 0;
}

/*
1
12
121
1213
12131
121312
1213121
12131231
12132123
*/