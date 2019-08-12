/**
 * 19.3.20.
 */
#include <cstdio>

int main(int argc, char const *argv[])
{
    while(true)
    {
        char input_;
        scanf("%c", &input_);
        if (input_ == '\n') break;
        if (input_ -'a'>=0 && input_-'z'<=0 ) printf("%c", input_-'a'+'A');
        else printf("%c", input_);

    }
    return 0;
}
