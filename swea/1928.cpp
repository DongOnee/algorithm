#include <cstdio>
#include <map>
using namespace std;

map<char, int> mp;
int cnt;

int main(int argc, char const *argv[])
{
    for (int i='A'; i<='Z'; i++) mp[i] = cnt++;
    for (int i='a'; i<='z'; i++) mp[i] = cnt++;
    for (int i='0'; i<='9'; i++) mp[i] = cnt++;
    mp['+'] = 62, mp['/'] = 63;

    // freopen("1928_input.txt", "r", stdin);
    int tc; scanf("%d\n", &tc);
    for (int test_case=1; test_case<=tc; test_case++)
    {
        printf("#%d ", test_case);
        int cnt = 0, c = 0;
        while (true)
        {
            char input; scanf("%c", &input);
            if (input == '\n') break;
            c <<= 6;
            c += mp[input];
            cnt++;

            if (cnt%4 == 0)
            {
                printf("%c", c / (1<<16));
                c %= (1<<16);
                printf("%c", c / (1<<8));
                c %= (1<<8);
                printf("%c", c);
                c = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
