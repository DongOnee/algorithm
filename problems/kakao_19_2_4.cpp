#include <string>
#include <vector>
using namespace std;

bool compWord(const string& word, const string& query)
{
    int n = word.size(), m = query.size();
    if (n != m) return false;
    for (int i=0; i<n; i++)
    {
        if (word[i] != query[i] && query[i] != '?') return false;
    }
    
    return true;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answers;
    int n = words.size(), m = queries.size();
    for (int i=0; i<m; i++)
    {
        int answer = 0;
        for (int j=0; j<n; j++) if (compWord(words[j], queries[i])) answer++;
        answers.push_back(answer);
    }
    return answers;
}