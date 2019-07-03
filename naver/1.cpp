// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int ret = 1;
    int cur_height = A[0];
    vector<int>::iterator itr = A.begin();

    while (*itr != cur_height) itr++;
    if (itr == A.end()) return 2;
    bool condition = cur_height < *itr;
    cur_height = *itr;

    for (; itr != A.end(); itr++)
    {
        if (cur_height == *itr) continue;
        else if (cur_height < *itr)
        {
            if (condition) continue;
            else
            {
                condition = true;
                ret++;
            }
        }
        else
        {
            if (!condition) continue;
            else
            {
                condition = false;
                ret++;
            }
            
        }
    }
    return ret;
}