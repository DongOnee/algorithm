#include <cstdio>

int main(int argc, char const *argv[])
{
    // freopen("2056_input.txt", "r", stdin);
    int tc; scanf("%d", &tc);
    for (int test_case = 1; test_case <= tc; test_case++)
    {
        int y; scanf("%d", &y);
        int d = y%100;
        y /= 100;
        int m = y%100;
        y /= 100;
        if ((m < 1) || (12 < m) || (d == 0) ||
            (m == 1 && 31 < d) || 
            (m == 2 && 28 < d) || 
            (m == 3 && 31 < d) || 
            (m == 4 && 30 < d) || 
            (m == 5 && 31 < d) || 
            (m == 6 && 30 < d) || 
            (m == 7 && 31 < d) || 
            (m == 8 && 31 < d) || 
            (m == 9 && 30 < d) || 
            (m == 10 && 31 < d) || 
            (m == 11 && 30 < d) || 
            (m == 12 && 31 < d)) printf("#%d -1\n", test_case);
        else printf("#%d %04d/%02d/%02d\n", test_case, y, m, d);
    }
    return 0;
}
