/**
 * 19.3.20.
 */
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int codes[10] = {13, 25, 19, 61, 35, 49, 47, 59, 55, 11};


int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    for (int TestCase=0, rows, cols; TestCase<T; TestCase++)
    {
        scanf("%d %d\n", &rows, &cols);
        int sol = 0; // 암호 번호
        int ret = 0; // 계산값
        for (int row=0; row<rows; row++)
        {
            int rowNum=0;

            string tmp;
            getline(cin, tmp);
            if (sol != 0)
            {
                if (ret == 0)
                {
                    int copyNum = sol;
                    while (copyNum)
                    {
                        ret += copyNum%10;
                        copyNum /= 10;
                        ret += (copyNum%10)*3;
                        copyNum /= 10;
                    }
                }
                continue;
            }
            
            bool chk = false;
            for (int col=0, cnt=0; col<cols; col++)
            {
                rowNum <<=1;
                rowNum += tmp[col]-'0';
                if (chk)
                {
                    cnt++;
                    if (cnt!=7) continue;
                }
                for (int i=0; i<10; i++) if(rowNum == codes[i])
                {
                    if (tmp[col+1] == '1') continue;
                    sol*=10;
                    sol+=i;
                    rowNum = 0;
                    chk = true;
                    cnt = 0;
                }
            }
        }
        printf("#%d ", TestCase+1);
        if (ret %10 ==0)
        {
            int p = 0;
            while(sol)
            {
                p += sol%10;
                sol/=10;
            }
            printf("%d\n", p);
        }
        else printf("0\n");
    }
    return 0;
}
