/**
 * 19.3.21.
 */
#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string rowString;
int curIndex, curCnt;

int char2int(char input)
{
    int ret = input - '0';
    if (9<ret)
    {
        ret += '0';
        ret -= 'A';
        ret += 10;
    }
    return ret;
}

int getCur()
{
    char tmp = rowString[curIndex];
    int ret = char2int(tmp);
    return ((ret&(1<<curCnt))?1:0);
}

void shiftCur()
{
    if (++curCnt==4)
    {
        --curIndex;
        curCnt=0;
    }
}

int codes[10] = {13, 25, 19, 61, 35, 49, 47, 59, 55, 11};
int int2code(int input)
{
    for (int i=0; i<10; i++)
        if (codes[i]==input) return i;
    return -1;
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    for (int tc=0, rows, cols; tc<T; tc++)
    {
        scanf("%d %d\n", &rows, &cols);
        int jumbpack[501] = {0,};
        int ret = 0;
        for (int row=0; row<rows; row++)
        {
            getline(cin, rowString);
            curCnt=0;
            curIndex = cols-1;
            while (curIndex > 0)
            {
                while (getCur()==0 && 0<=curIndex)
                {
                    shiftCur();
                    jumbpack[curIndex+1] = 0;
                } // cur 은 1 이다.
                if (jumbpack[curIndex] != 0)
                {
                    int diff = jumbpack[curIndex] * 56;
                    for (int i=0; i<diff; i++) shiftCur();
                    continue;
                }
                
                int PassWord = 0, calc = 0;

                if (curIndex <= 0) break;
                int saveCurIndex=curIndex;
                int saveCurCnt=curCnt;
                int jumpSize = 1;
                for (int codeIndex=0; codeIndex<8; codeIndex++)
                {
                    int oneCode=0;
                    for (int i=0; i<7; i++)
                    {
                        int tmp = getCur();
                        for (int j=0; j<jumpSize; j++) shiftCur();
                        oneCode += tmp<<i;
                    }
                    int oneCodeint = int2code(oneCode);
                    if (oneCodeint == -1)
                    {
                        jumpSize++;
                        curIndex = saveCurIndex;
                        curCnt = saveCurCnt;
                        codeIndex=-1;
                        PassWord=0;
                        continue;
                    }
                    PassWord += oneCodeint*pow(10, codeIndex);
                }
                // printf("\t\tpassword : %d\n", PassWord);
                jumbpack[saveCurIndex] = jumpSize;

                int tmp = PassWord;
                while(tmp)
                {
                    calc += tmp%10;
                    tmp /= 10;
                    calc += (tmp%10)*3;
                    tmp /= 10;
                }
                // printf("\t\tcalc : %d\n", calc);
                if (calc%10 == 0)
                {
                    int tmp = PassWord;
                    while(tmp)
                    {
                        ret += tmp%10;
                        tmp /= 10;
                    }
                }
            }
        }
        printf("#%d %d\n", tc+1, ret);
    }
    return 0;
}
