/**
 * 19.1.4.
 */
#include <cstdio>
#include <cmath>

int main(int argc, char const *argv[])
{
    int T; scanf("%d", &T);
    for (int test_case=0; test_case<T; test_case++)
    {
        int length, ants; scanf("%d %d", &length, &ants);
        int far = 0, close=0;
        for (int i=0; i<ants; i++)
        {
            int input; scanf("%d", &input);
            int short_path = 2*input > length ? length-input : input;
            // int long_path = 2*input > length ? input : length-input;
            int long_path = length - short_path;
            far = fmax(far, short_path);
            close = fmax(close, long_path);
        }

        printf("%d %d\n", far, close);
    }
    return 0;
}
