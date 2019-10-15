#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, string> pis;

string solution(int n, vector<string> plates, vector<int> odo, int k, vector<int> drives) {
    string answer = "";
    priority_queue<pis, vector<pis>, greater<pis>> pq;
    for (int i=0; i<n; i++) pq.push({odo[i], plates[i]});
    
    for (int x : drives)
    {
        pis tp = pq.top(); pq.pop();
        pq.push({tp.first+x, tp.second});
    }
    return pq.top().second;
}