#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

char input[11];

int main(int argc, char const *argv[])
{
    scanf("%s", input);

    sort(input, input+11, greater<char>());
    printf("%s\n", input);

    return 0;
}
