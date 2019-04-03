#include <iostream>
using namespace std;

long long calc() {
    int tmps = 100000;
    long long max_ = 1000000000;
    // printf("%lld", tmps * max_);
    long long rets = tmps * max_;
    // return rets;
    return tmps * max_;
}

int main(void) {
    int tmps = 100000;
    int max_ = 1000000000;
    printf("%lld\n", tmps * max_);
    printf("%lld\n", calc());
}

