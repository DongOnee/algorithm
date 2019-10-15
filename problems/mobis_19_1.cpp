#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> P) {
    int answer = P[0], minValue = P[0];
    for (int i=1; i<n; i++)
    {
        if (P[i] < minValue) minValue = P[i];
        answer += minValue;
    }
    return answer;
}