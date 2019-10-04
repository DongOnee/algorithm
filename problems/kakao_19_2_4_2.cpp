#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
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

int subSolution(vector<string>& words, int& idxWord, string query, int szWords)
{
    int ret = 0, tmp = idxWord;
    bool flag = false;
    if (query[0] == '?') flag = true;
    while (true)
    {
        if (compWord(words[idxWord], query)) ret++;
        if (++idxWord >= szWords) break;
    }
    if (flag) idxWord = tmp;

    return ret;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answers;
    int n = words.size();
    sort(words.begin(), words.end());
    sort(queries.begin(), queries.end());

    int idxWords = 0;

    for (auto query : queries)
    {
        cout << "idxWords : " << idxWords << "\tquery : " << query << endl;
        answers.push_back(subSolution(words, idxWords, query, n));
    }
    
    return answers;
}