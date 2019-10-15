#include <cstdio>
int idx, cnt[26];

int main(int argc, char const *argv[])
{
    char input[101];
    scanf("%s", input);
    while(input[idx])
    {
        cnt[input[idx] - 'a']++;
        idx++;
    }

    for (int i=0; i<26; i++) printf("%d ", cnt[i]);
    return 0;
}
