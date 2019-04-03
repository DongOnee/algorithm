/**
 * 19.3.20.
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int cntCodes[2] = {7, 14};
int codes[2][10] = {{13, 25, 19, 61, 35, 49, 47, 59, 55, 11}, {243, 963, 783, 4083, 3087, 3843, 3327, 4047, 3903, 207}};

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    for (int testCase=0, rows, cols; testCase<T; testCase++)
    {
        scanf("%d %d\n", &rows, &cols);
        int passWord=0, calc=0, selecter=0;
        for (int row=0; row<rows; row++)
        {
            string inputRow;
            getline(cin, inputRow);

            if (calc != 0) continue;

            int endIndex=cols-1;
            while(inputRow[--endIndex] == '0');

            if (endIndex == -1) continue;

            int tmp = inputRow[endIndex] - '0';
            int tmpCnt = 0;
            if (9 < tmp) tmp += ('0' - 'A'+10);

            while (0<endIndex)
            {
                while ((tmp&1) == 0)
                {
                    tmp>>=1;
                    tmpCnt++;
                    if (tmpCnt == 4)
                    {
                        tmp = inputRow[--endIndex] - '0';
                        if (9 < tmp) tmp += ('0' - 'A' + 10);
                        tmpCnt = 0;
                    }
                    if (endIndex == -1) break;;
                }
                if (endIndex == -1) break;;


                for (int i=0; i<8; i++)
                {
                    int cnt=0;
                    int OneCode=0;
                    while(1)
                    {
                        int insert_ = tmp&1;
                        OneCode += insert_<<cnt;
                        // if (OneCode > 0 && OneCode < 1000) printf("OneCode : %d\n", OneCode);
                        tmp >>= 1;
                        tmpCnt++;

                        if (tmpCnt == 4)
                        {
                            tmp = inputRow[--endIndex] - '0';
                            if (9 < tmp) tmp += ('0' - 'A' + 10);
                            tmpCnt = 0;
                        }

                        if (++cnt == cntCodes[selecter])
                        {
                            bool chk = false;
                            for (int j=0; j<10; j++)
                            {
                                if (codes[selecter][j] == OneCode)
                                {
                                    // printf("%d\n", j);
                                    chk = true;
                                    passWord += j*pow(10, i);
                                    // printf("%d", passWord);
                                    break;
                                }
                            }
                            if (!chk)
                            {
                                selecter++;
                                continue;
                            }
                            break;
                        }
                    }
                }

                int cppw = passWord;
                while(cppw)
                {
                    calc += cppw%10;
                    cppw /=10;
                    calc += (cppw%10)*3;
                    cppw /=10;
                }
                if (calc%10 != 0) 
                {
                    calc=0;
                    passWord=0;
                }
                else
                {
                    calc = 0;
                    while(passWord)
                    {
                        calc += passWord%10;
                        passWord /= 10;
                    }
                }
            }
        }
        printf("#%d %d\n", testCase+1, calc);
    }
    return 0;
}



// 0001101 -> 13 -> 0
// 0001011 -> 11 -> 9
// 0100011 -> 35 -> 4
// 0110111 -> 
// 0110111
// 0010011
// 0100011
// 0111101