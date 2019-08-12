/**
 * 19.4.4.
 */
#include <cstdio>
#include <vector>
using namespace std;

int numberCnt[10];

int main(int argc, char const *argv[])
{
    bool zero_ = false;
    long long sum_ =0;
    int cnt=0;
    while(true)
    {
        char input_;
        scanf("%c", &input_);
        if (input_ == '\n') break;
        int input__ = input_ - '0';
        numberCnt[input__]++;
    }

    if (numberCnt[0] ==0) printf("-1\n");
    else
    {
        for (int i=1; i<9; i++)
        {
            sum_ += i * numberCnt[i];
            sum_ %= 3;
        }
        if (sum_ != 0) printf("-1\n");
        else
        {
            for (int i=9; 0<=i; i--)
            {
                while(numberCnt[i]--) printf("%d", i);
            }
        }
        
    }
    

    return 0;
}