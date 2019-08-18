/**
 * 19.2.20.
 */
#include <cstdio>
#include <vector>
using namespace std;

#define mod 1000
typedef vector<vector<int>> matrix;

int N;
long long B;
matrix vt;
matrix sol;

matrix matmul_calc(matrix mat1, matrix mat2)
{
    matrix ret;
    for (int row_index=0; row_index<N; row_index++)
    {
        vector<int> rows;
        for (int col_index=0; col_index<N; col_index++)
        {
            int sum = 0;
            for (int i=0; i<N; i++)
            {
                sum += mat1[row_index][i] * mat2[i][col_index];
                sum %= mod;
            }
            rows.push_back(sum);
        }
        ret.push_back(rows);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    scanf("%d%lld", &N, &B);
    for (int i=0; i<N; i++)
    {
        vector<int> tmp;
        vector<int> tmp2;
        for (int j=0, a; j<N; j++)
        {
            scanf("%d", &a);
            tmp.push_back(a);
            if (i==j) tmp2.push_back(1);
            else tmp2.push_back(0);
        }
        vt.push_back(tmp);
        sol.push_back(tmp2);
    }

    while(B)
    {
        if (B&1) sol = matmul_calc(sol, vt);
        B >>= 1;
        vt = matmul_calc(vt, vt);
    }

    for (auto a : sol)
    {
        for (auto b: a)
        {
            printf("%d ", b);
        }
        puts("");
    }

    return 0;
}
